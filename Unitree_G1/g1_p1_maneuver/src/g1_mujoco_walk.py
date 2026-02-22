import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import mujoco
import mujoco.viewer
import numpy as np
import time
from humanoid_gait_generator import HumanoidGaitGenerator

class G1MuJoCoBridge(Node):
    def __init__(self):
        super().__init__('g1_mujoco_bridge')
        # 1. ROS 2 Subscription
        self.subscription = self.create_subscription(Twist, '/cmd_vel', self.cmd_vel_callback, 10)
        self.target_vel = np.array([0.0, 0.0, 0.0]) # [linear_x, linear_y, angular_z]
        
        # 2. MuJoCo Setup
        self.model = mujoco.MjModel.from_xml_path('mjcf/scene_cath.xml')
        self.data = mujoco.MjData(self.model)
        self.gait = HumanoidGaitGenerator()
        
        # 3. Control Gains (Your stable baseline)
        self.kp = 1000
        self.kv = 50

        self.pelvis_y = 0.0

    def cmd_vel_callback(self, msg):
        # Update target velocity based on keyboard input
        self.target_vel[0] = msg.linear.x
        self.target_vel[1] = msg.linear.y
        self.target_vel[2] = msg.angular.z

    def run_simulation(self):
        with mujoco.viewer.launch_passive(self.model, self.data) as viewer:
            while viewer.is_running() and rclpy.ok():
                viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTFORCE] = True
                viewer.opt.flags[mujoco.mjtVisFlag.mjVIS_CONTACTSPLIT] = True
                step_start = time.time()
                rclpy.spin_once(self, timeout_sec=0.0)
                rclpy.spin_once(self.gait, timeout_sec=0)

                # 4. Generate Trajectory based on Velocity
                # Pass self.target_vel to your gait generator
                # The internal phase is updated by the timer in HumanoidGaitGenerator
                target_pose = self.gait.get_target_pose()

                # 5. Apply PD Control to 29 actuators
                current_pos = self.data.qpos[7:] # Skip free joint
                current_vel = self.data.qvel[6:]
                self.data.ctrl[:] = self.kp * (target_pose - current_pos) - self.kv * current_vel

               

                #. Keep the robot from falling but leave Y-velocity (index 1) FREE
                #self.data.qpos[0] = 0.0              # Lock X (Side-to-side)
                #self.data.qpos[2] = 0.745            # Relaxed height to prevent bouncing
                self.data.qpos[3:7] = [1, 0, 0, 0]    # Lock Rotation

                self.data.qvel[0] = 0   # No side-drift
                self.data.qvel[2] = 0   # No vertical bouncing
                self.data.qvel[3:6] = 0 # No tipping over
                # data.qvel[1] is NOT modified. It is left to the physics engine.
                ###########################

                # --- INSERT DEBUG CODE HERE ---
                
                total_force = 0

                for i in range(self.data.ncon):
                    c_array = np.zeros(6)
                    mujoco.mj_contactForce(self.model, self.data, i, c_array)
                    total_force += np.linalg.norm(c_array[:3])
                
                # Print results to your terminal
                print(f"Contacts: {self.data.ncon} | Total Force: {total_force:.2f}")
                # ------------------------------
                #############################

                mujoco.mj_step(self.model, self.data)
                viewer.sync()

                # Sync with real-time (0.001s timestep suggested)
                time.sleep(max(0, self.model.opt.timestep - (time.time() - step_start)))

def main():
    rclpy.init()
    node = G1MuJoCoBridge()
    node.run_simulation()
    rclpy.shutdown()

if __name__ == '__main__':
    main()