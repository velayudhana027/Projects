import torch
import time
from dataclasses import asdict
from mjlab.tasks.registry import load_env_cfg, load_rl_cfg, load_runner_cls
from mjlab.envs import ManagerBasedRlEnv
from mjlab.rl import MjlabOnPolicyRunner, RslRlVecEnvWrapper
from mjlab.viewer import NativeMujocoViewer
from mjlab.viewer.native.keys import KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT

# Global state to track keys from the viewer thread
pressed_keys = {"up": False, "down": False, "left": False, "right": False}

def my_key_callback(key):
    """
    Handles keyboard events from the MuJoCo viewer thread.
    This updates the global state which the main loop reads.
    """
    # Note: This viewer implementation often sends the key code on press.
    # To keep it simple, we toggle or set states here.
    if key == KEY_UP:    pressed_keys["up"] = True
    elif key == KEY_DOWN:  pressed_keys["down"] = True
    elif key == KEY_LEFT:  pressed_keys["left"] = True
    elif key == KEY_RIGHT: pressed_keys["right"] = True
    
    # Optional: Reset others when a new key is pressed
    other_keys = [k for k in pressed_keys if k != key]
    # For a 'stop' logic, you can add a specific key (like Space) to clear all.

#def main():
    # --- 1. CONFIGURATION ---
    TASK_ID = "Mjlab-Velocity-Flat-Unitree-G1"
    CHECKPOINT_PATH = "/home/velayudhan/Downloads/model_29999.pt"
    DEVICE = "cpu"  # Forced to CPU for GTX 1050 compatibility

    # --- 2. INITIALIZE ENVIRONMENT ---
    env_cfg = load_env_cfg(TASK_ID, play=True)
    agent_cfg = load_rl_cfg(TASK_ID)
    env_cfg.scene.num_envs = 1 # Single env for clear viewing

    env = ManagerBasedRlEnv(cfg=env_cfg, device=DEVICE)
    env = RslRlVecEnvWrapper(env, clip_actions=agent_cfg.clip_actions)
    
    # --- 3. LOAD TRAINED POLICY ---
    runner_cls = load_runner_cls(TASK_ID) or MjlabOnPolicyRunner
    runner = runner_cls(env, asdict(agent_cfg), device=DEVICE)
    print(f"Loading checkpoint from: {CHECKPOINT_PATH}")
    runner.load(CHECKPOINT_PATH, load_cfg={"actor": True})
    policy = runner.get_inference_policy(device=DEVICE)

    # --- 4. SETUP NATIVE VIEWER ---
    # NativeMujocoViewer handles the complex GPU-to-CPU state syncing
    viewer = NativeMujocoViewer(
        env, 
        policy, 
        key_callback=my_key_callback,
        enable_perturbations=True  # Enables Ctrl+Mouse interaction
    )

    # Add this check to ensure the viewer launched
    if viewer.viewer is None:
        print("ERROR: MuJoCo viewer failed to initialize.")
        return

    # Small delay to allow the window thread to spawn
    time.sleep(1.0)

    print("\n" + "="*30)
    print("INTERACTIVE G1 CONTROL ACTIVE")
    print("="*30)
    print("Arrow Keys : Move Robot")
    print("Ctrl+Mouse : Pull Torso (Test Balance)")
    print("ESC        : Close Viewer")
    print("="*30 + "\n")

    # --- 5. MAIN INTERACTIVE LOOP ---
    obs, _ = env.reset()
    while viewer.is_running():
        step_start = time.time()

        # A. Process Keyboard Input -> Velocity Command
        # Command format for base_velocity: [Lin_X, Lin_Y, Ang_Z]
        vel_cmd = torch.zeros((1, 3), device=DEVICE)
        
        if pressed_keys["up"]:    vel_cmd[0, 0] = 1.0   # Walk forward
        if pressed_keys["down"]:  vel_cmd[0, 0] = -1.0  # Walk backward
        if pressed_keys["left"]:  vel_cmd[0, 1] = 0.4   # Strafe left
        if pressed_keys["right"]: vel_cmd[0, 1] = -0.4  # Strafe right

        # B. Inject command into mjlab CommandManager
        cmd_term = env.unwrapped.command_manager.get_term("base_velocity")
        cmd_term.command[:] = vel_cmd

        # C. RL Inference and Physics Step
        with torch.inference_mode():
            actions = policy(obs)
        obs, rewards, terminated, truncated, extras = env.step(actions)

        # D. Viewer Synchronization
        # Copy GPU state to CPU MjData for rendering
        viewer.sync_env_to_viewer()
        # Back-sync mouse perturbation forces to the GPU simulation
        viewer.sync_viewer_to_env() 

        # E. Maintain Real-time Playback Speed
        time_until_next_step = env.unwrapped.step_dt - (time.time() - step_start)
        if time_until_next_step > 0:
            time.sleep(time_until_next_step)

def main():
    # --- 1. CONFIGURATION ---
    TASK_ID = "Mjlab-Velocity-Flat-Unitree-G1"
    CHECKPOINT_PATH = "/home/velayudhan/Downloads/model_29999.pt"
    DEVICE = "cpu" 

    # --- 2. INITIALIZE ENVIRONMENT ---
    env_cfg = load_env_cfg(TASK_ID, play=True)
    agent_cfg = load_rl_cfg(TASK_ID)
    env_cfg.scene.num_envs = 1 

    env = ManagerBasedRlEnv(cfg=env_cfg, device=DEVICE)
    env = RslRlVecEnvWrapper(env, clip_actions=agent_cfg.clip_actions)
    
    # --- 3. LOAD TRAINED POLICY ---
    runner_cls = load_runner_cls(TASK_ID) or MjlabOnPolicyRunner
    runner = runner_cls(env, asdict(agent_cfg), device=DEVICE)
    runner.load(CHECKPOINT_PATH, load_cfg={"actor": True})
    policy = runner.get_inference_policy(device=DEVICE)

    # --- 4. LAUNCH VISER (WEB VIEWER) ---
    from mjlab.viewer import ViserPlayViewer
    print("\nStarting Viser Web Viewer...")
    print("Open the URL provided (usually http://0.0.0.0:8080) in your browser!")
    
    viewer = ViserPlayViewer(env, policy)
    viewer.run()
    
if __name__ == "__main__":
    main()