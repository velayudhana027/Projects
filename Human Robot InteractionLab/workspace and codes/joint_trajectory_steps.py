#!/usr/bin/env python3

import rospy
import numpy as np
from franka_msgs.msg import FrankaState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint


def sender():
            
    """
    TODO: Define the goal positions for the seven robot joints (Exercise 14f)
    """
    goal_positions = [0.01901304171430437, -0.7578371916647495, -0.022408882223304574, -2.431409371565221, 0.030831767103785736, 1.6727610352569153, 0.7962078065817378]
    #actual_pos = [-0.011818183742202283, -0.6885936248429411, -0.16629278179594253, -2.1425662586141097, 0.030857278544041838, 2.1645743454756867, 0.7962923290299043]
    #actual_pos2 = [-0.623617315183606, -1.5341351992985401, 0.5808896207677557, -2.217003143105584, 0.032897564931048284, 1.7347898848227434, 0.8091143329998294]
    actual_pos = [0.6854069863118624, -1.732940587511243, -1.444179002839459, -2.605146587147025, 2.8760291213641933, 1.2099894276298666, 0.7790561344193088]
    # Joint Trajectory
    # Number of waypoints in the trajectory
    N_steps = 200

    """
    TODO: Create an N_stepsx7 array for the joint positions along the trajectory.
    To do this, divide the distance between the start and target positions into N equal steps.
    (one way to solve the problem is with np.linspace())
    """
    traj = np.linspace( actual_pos,  goal_positions, N_steps)
    

    rospy.loginfo("Starting to execute the trajectory!")
    rospy.sleep(1)

    i = 0

    while not rospy.is_shutdown():
        
        if i < N_steps: 
            joint_pos_msg.points[0].positions = traj[i, :]
        else:
            joint_pos_msg.points[0].positions = traj[N_steps-1, :]


        print(joint_pos_msg.points[0].positions)
            
        joint_pos_publisher.publish(joint_pos_msg)

        i = i + 1

        rate.sleep()


if __name__ == '__main__':
    
    rospy.init_node('joint_trajectory', anonymous=False)
    
    # Parameters
    rate = rospy.Rate(10)

    """
    TODO: Initialise a Publisher publishing to the Topic "/position_joint_trajectory_controller/command"
    with the message type "JointTrajectory". Joint positions sent to this topic are used as desired positions 
    for the low level position controller.
    """
    joint_pos_publisher = rospy.Publisher('/position_joint_trajectory_controller/command', JointTrajectory, queue_size=10)
    
    
    # Read the robot states once and get initial joint positions
    franka_state = rospy.wait_for_message("franka_state_controller/franka_states", FrankaState)
    initial_pos = list(franka_state.q)

    # Create the message for commanding the joint positions
    panda_joints = ['panda_joint1','panda_joint2','panda_joint3','panda_joint4','panda_joint5',
                         'panda_joint6','panda_joint7']
    joint_pos_msg = JointTrajectory()
    joint_pos_msg.joint_names = panda_joints
    joint_pos_msg.points.append(JointTrajectoryPoint())
    joint_pos_msg.points[0].positions = initial_pos
    joint_pos_msg.points[0].velocities = [0.0 for i in panda_joints]
    joint_pos_msg.points[0].accelerations = [0.0 for i in panda_joints]
    joint_pos_msg.points[0].time_from_start = rospy.Duration(3)

    sender()
