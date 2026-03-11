import mujoco
import mujoco.viewer
import torch
import numpy as np
import time

# --- CONFIGURATION ---
MODEL_PATH = "/home/velayudhan/workspaces/humanoid_ws/src/unitree_g1_description/mjlab_training_model_unitree_g1_phase1/model_29999.pt"
XML_PATH = "/home/velayudhan/workspaces/humanoid_ws/src/unitree_g1_description/urdf_xml/scene_cath_mujoco.xml"
ACTION_SCALE = 0.25 

# PD Gains from training
KP = 20.0 
KD = 5.0

def get_policy_and_stats(path):
    class ActorModel(torch.nn.Module):
        def __init__(self):
            super().__init__()
            self.mlp = torch.nn.Sequential(
                torch.nn.Linear(99, 512), torch.nn.ELU(),
                torch.nn.Linear(512, 256), torch.nn.ELU(),
                torch.nn.Linear(256, 128), torch.nn.ELU(),
                torch.nn.Linear(128, 29)
            )
        def forward(self, x): return self.mlp(x)

    checkpoint = torch.load(path, map_location='cpu', weights_only=False)
    model = ActorModel()
    model.load_state_dict(checkpoint['actor_state_dict'], strict=False)
    mean = checkpoint['actor_state_dict']['obs_normalizer._mean'].numpy()
    std = np.sqrt(checkpoint['actor_state_dict']['obs_normalizer._var'].numpy() + 1e-8)
    return model.eval(), mean, std

def main():
    model_mj = mujoco.MjModel.from_xml_path(XML_PATH)
    data_mj = mujoco.MjData(model_mj)
    policy, obs_mean, obs_std = get_policy_and_stats(MODEL_PATH)

    # Nominal Stance
    default_dof_pos = np.zeros(29)
    default_dof_pos[2], default_dof_pos[8] = -0.2, -0.2  # Hip Pitch
    default_dof_pos[3], default_dof_pos[9] = 0.45, 0.45  # Knee Pitch
    default_dof_pos[4], default_dof_pos[10] = -0.25, -0.25 # Ankle Pitch

    # Initialization: Height 0.793 matches your XML
    data_mj.qpos[2] = 0.793 
    data_mj.qpos[7:] = default_dof_pos
    mujoco.mj_forward(model_mj, data_mj)

    # Use 'torso_link' for orientation data
    torso_id = model_mj.body('torso_link').id
    for _ in range(100):
        data_mj.qpos[2] = 0.793
        data_mj.qpos[7:] = default_dof_pos
        mujoco.mj_step(model_mj, data_mj)

    with mujoco.viewer.launch_passive(model_mj, data_mj) as viewer:
        while viewer.is_running():
            step_start = time.time()

            # 1. Observation (Torso-Link frame)
            quat = data_mj.xquat[torso_id]
            grav = np.zeros(3)
            mujoco.mju_rotVecQuat(grav, np.array([0, 0, -1]), quat)

            obs_raw = np.zeros(99)
            obs_raw[0:3] = data_mj.cvel[torso_id][3:6] # Linear Vel
            obs_raw[3:6] = data_mj.cvel[torso_id][0:3] # Angular Vel
            obs_raw[6:9] = grav
            obs_raw[9:38] = data_mj.qpos[7:] - default_dof_pos 
            obs_raw[38:67] = data_mj.qvel[6:]

            # 2. Inference
            obs_norm = (obs_raw - obs_mean) / obs_std
            with torch.no_grad():
                action = policy(torch.tensor(obs_norm).float().view(1, -1)).numpy().squeeze()

            # 3. EXPLICIT PD CONTROL
            target_pos = default_dof_pos + (action * ACTION_SCALE)
            current_pos = data_mj.qpos[7:]
            current_vel = data_mj.qvel[6:]
            
            # tau = Kp * (target - pos) - Kd * vel
            torques = KP * (target_pos - current_pos) - KD * current_vel
            data_mj.ctrl[:] = np.clip(torques, -88, 88) 

            # Instead of one mj_step, step the physics to match your 0.02s delay
            steps_per_action = int(0.02 / model_mj.opt.timestep)
            for _ in range(steps_per_action):
                mujoco.mj_step(model_mj, data_mj)
            viewer.sync()

            # 4. Loop Sync (50Hz)
            time.sleep(max(0, 0.02 - (time.time() - step_start)))

if __name__ == "__main__":
    main()