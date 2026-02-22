import mujoco
import mujoco.viewer
import numpy as np
import time

# 1. LOAD MODEL AND DATA
# This loads your room, obstacles, and the G1 robot
try:
    model = mujoco.MjModel.from_xml_path('mjcf/scene_cath.xml')
    data = mujoco.MjData(model)
except Exception as e:
    print(f"Error loading XML: {e}")
    exit()

# 2. PD CONTROL PARAMETERS (Virtual Muscle Strength)
# kp: Stiffness. Higher values make the joints rigid.
# kv: Damping. Higher values prevent shaking/jittering.
kp = 400
kv = 20

# 3. SET THE TARGET POSE
# We want all 29 motors to aim for 0 radians (standard standing T-pose/I-pose)
target_pose = np.zeros(model.nu)



# 4. SIMULATION LOOP
with mujoco.viewer.launch_passive(model, data) as viewer:
    print("G1 Standing Controller Active. The robot should now be balanced.")
    
    while viewer.is_running():
        step_start = time.time()

        # 5. CALCULATE AND APPLY TORQUE
        # qpos[7:]: We skip the first 7 values (pelvis X,Y,Z and Rotation) 
        # because the pelvis doesn't have a motor.
        current_pos = data.qpos[7:]
        current_vel = data.qvel[6:] # Skip 6-DOF base velocity
        
        # Torque Equation: Force = kp * (Error) - kv * (Velocity)
        data.ctrl[:] = kp * (target_pose - current_pos) - kv * current_vel

        # 6. STEP THE PHYSICS
        mujoco.mj_step(model, data)
        
        # Sync the viewer with the physics state
        viewer.sync()

        # Maintain real-time frequency (default is 0.002s per step)
        time_until_next_step = model.opt.timestep - (time.time() - step_start)
        if time_until_next_step > 0:
            time.sleep(time_until_next_step)