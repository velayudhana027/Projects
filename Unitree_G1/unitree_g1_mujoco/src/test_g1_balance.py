import mujoco
import mujoco.viewer
import numpy as np
import time
from stable_baselines3 import PPO
from train_g1_balance import G1StandEnv # Import your env class

def main():
    # 1. Path to your scene and model
    XML_PATH = '~/workspaces/humanoid_ws/src/unitree_g1_description/urdf_xml/scene_cath.xml'
    MODEL_PATH = "/home/velayudhan/Downloads/model_29999.pt"
    
    import os
    XML_PATH = os.path.expanduser(XML_PATH)

    # 2. Create the environment and load the model
    env = G1StandEnv(XML_PATH)
    model = PPO.load(MODEL_PATH, env=env, device="cpu")

    # 3. Setup MuJoCo viewer
    # We use the raw model/data from the env for the viewer
    with mujoco.viewer.launch_passive(env.model, env.data) as viewer:
        print("Model loaded. Starting balance test...")
        
        obs, _ = env.reset()
        
        while viewer.is_running():
            step_start = time.time()

            # 4. Predict action using the trained RL policy
            # deterministic=True ensures the robot uses its best learned strategy
            action, _states = model.predict(obs, deterministic=True)

            # 5. Step the environment
            obs, reward, terminated, truncated, info = env.step(action)

            # 6. Optional: Auto-reset if the robot falls
            if terminated or truncated:
                obs, _ = env.reset()
                print("Robot fell! Resetting environment...")

            # 7. Sync viewer
            with viewer.lock():
                viewer.sync()

            # Maintain real-time simulation speed
            time_until_next_step = env.model.opt.timestep - (time.time() - step_start)
            if time_until_next_step > 0:
                time.sleep(time_until_next_step)

if __name__ == "__main__":
    main()