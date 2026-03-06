import mujoco
import mujoco.viewer
import numpy as np
import time
import os

def run_stand_phase():
    try:
        #####change the xml path over here#####
        XML_PATH = os.path.expanduser('~/workspaces/humanoid_ws/src/unitree_g1_description/urdf_xml/scene_cath.xml')

        model = mujoco.MjModel.from_xml_path(XML_PATH)
        data = mujoco.MjData(model)
    except Exception as e:
        print(f"Error loading XML: {e}")
        return

    # 1. FINAL STABILIZED GAINS
    kp_final = 350.0  
    kv_final = 50.0   

    # 2. TARGET POSE WITH ANKLE COMPENSATION
    # Bending knees (3, 9) and hips (0, 6) while pitching ankles (4, 10) forward
    target_pose = np.zeros(model.nu)
    target_pose[0] = -0.4  # left_hip_pitch
    target_pose[3] = 0.8   # left_knee
    target_pose[4] = -0.4  # left_ankle_pitch (counters the hip/knee lean)
    
    target_pose[6] = -0.4  # right_hip_pitch
    target_pose[9] = 0.8   # right_knee
    target_pose[10] = -0.4 # right_ankle_pitch
    
    # 3. INITIALIZE
    mujoco.mj_resetData(model, data)
    data.qpos[2] = 0.76 # Precise height to minimize impact bounce

    with mujoco.viewer.launch_passive(model, data) as viewer:
        start_time = time.time()
        print("G1 Stand Phase: Stabilizing...")
        
        while viewer.is_running():
            step_start = time.time()
            
            # 4. GAIN RAMPING (Prevents the 'Snap' fall)
            # Gradually increase KP over the first 2 seconds
            elapsed_sim = time.time() - start_time
            scale = min(1.0, elapsed_sim / 2.0)
            current_kp = kp_final * scale
            current_kv = kv_final

            # 5. CONTROL CALCULATION
            current_pos = data.qpos[7:] 
            current_vel = data.qvel[6:] 
            data.ctrl[:] = current_kp * (target_pose - current_pos) - current_kv * current_vel

            mujoco.mj_step(model, data)
            viewer.sync()

            # Real-time synchronization
            time_until_next_step = model.opt.timestep - (time.time() - step_start)
            if time_until_next_step > 0:
                time.sleep(time_until_next_step)

if __name__ == "__main__":
    run_stand_phase()