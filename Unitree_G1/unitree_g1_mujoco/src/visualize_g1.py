import mujoco
import mujoco.viewer
import os
import time

def main():
    # 1. Define the absolute path to your MJCF file
    xml_path = os.path.expanduser('~/workspaces/humanoid_ws/src/unitree_g1_description/urdf_xml/scene_cath.xml')
    
    if not os.path.exists(xml_path):
        print(f"ERROR: XML file not found at: {xml_path}")
        return

    # 2. Load the model and data
    try:
        # MuJoCo will use the meshdir="../meshes" relative to this path
        model = mujoco.MjModel.from_xml_path(xml_path)
        data = mujoco.MjData(model)
        print("Model loaded successfully!")
    except Exception as e:
        print(f"Failed to load model: {e}")
        return

    # 3. Launch the passive viewer
    # This viewer runs in a separate thread, allowing the simulation to loop
    with mujoco.viewer.launch_passive(model, data) as viewer:
        print("MuJoCo Viewer started.")
        
        # Keep the script running
        while viewer.is_running():
            step_start = time.time()

            # Advance the simulation by one timestep
            mujoco.mj_step(model, data)

            # Synchronize the viewer with the simulation state
            viewer.sync()

            # Maintain real-time execution speed
            time_until_next_step = model.opt.timestep - (time.time() - step_start)
            if time_until_next_step > 0:
                time.sleep(time_until_next_step)

if __name__ == "__main__":
    main()