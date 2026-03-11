import gymnasium as gym
import mujoco
import mujoco.viewer
import time
from stable_baselines3 import PPO
from train_g1_balance import G1MoveEnv # Import your env class
import os

XML_PATH = os.path.expanduser('~/workspaces/humanoid_ws/src/unitree_g1_description/urdf_xml/scene_cath.xml')
# Path to your latest checkpoint or final model
#MODEL_PATH = "g1_final_model.zip" 
MODEL_PATH = os.path.expanduser("/home/velayudhan/workspaces/humanoid_ws/logs/g1_model_9000000_steps")
env = G1MoveEnv(XML_PATH)
model = PPO.load(MODEL_PATH,device="cpu")

obs, _ = env.reset()
with mujoco.viewer.launch_passive(env.model, env.data) as viewer:
    while viewer.is_running():
        action, _ = model.predict(obs, deterministic=True)
        obs, reward, terminated, truncated, _ = env.step(action)
        
        if terminated or truncated:
            obs, _ = env.reset()
            
        viewer.sync()
        time.sleep(env.model.opt.timestep)