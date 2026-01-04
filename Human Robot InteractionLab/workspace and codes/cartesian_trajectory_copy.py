#!/usr/bin/env python3
import rospy
import numpy as np
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
import roboticstoolbox as rtb
from spatialmath import SE3


class Node(object):

    def __init__(self):

        # Create robot object for rtb functions (Franka Emika Robot is also called "Panda") 
        self.panda = rtb.models.DH.Panda()

        # Initial cartesian robot position
        
        self.initial_pos = np.array([[1,0,0,0.3074],[0,-1,0,0],[0,0,-1,0.4855],[0,0,0,1]])
        
        # Corresponding initial joint position (to initialize inverse kinematics function)
        self.start_q = [0.0, -np.pi/4, 0.0, -3*np.pi/4, 0.0, np.pi/2, np.pi/4]
        
        """
        TODO Define the inital and goal positions as 4x4 matrix
        """
        
        self.goal_pos = np.array([[1,0,0,0.3074],[0,-1,0,0],[0,0,-1,0.4855],[0,0,0,1]])
        # Distance in x-direction
        self.goal_pos[0,3] = self.goal_pos[0,3] + 0.0
        
        self.goal_pos[1,3] = self.goal_pos[1,3] + 0.0
        # Distance in z-direction
        self.goal_pos[2,3] = self.goal_pos[2,3] + 0.0
        

        # Initialise publishers
        self.joint_pos_publisher = rospy.Publisher('/position_joint_trajectory_controller/command' , JointTrajectory, queue_size=10)
        
        # Create the message for commanding the joint positions
        self.panda_joints = ['panda_joint1','panda_joint2','panda_joint3','panda_joint4','panda_joint5',
                              'panda_joint6','panda_joint7']
        self.joint_pos_msg = JointTrajectory()
        self.joint_pos_msg.joint_names = self.panda_joints
        self.joint_pos_msg.points.append(JointTrajectoryPoint())
        self.joint_pos_msg.points[0].positions = self.start_q
        self.joint_pos_msg.points[0].velocities = [0.0 for i in self.panda_joints]
        self.joint_pos_msg.points[0].accelerations = [0.0 for i in self.panda_joints]
        self.joint_pos_msg.points[0].time_from_start = rospy.Duration(3)
        #######
        self.initial_pos_joint_space =  self.panda.ikine_LM(SE3(self.initial_pos), q0=self.start_q)
        self.goal_pos_joint_space =  self.panda.ikine_LM(SE3(self.goal_pos), q0=self.start_q)
        #######

        
    def run(self):
        
        # Parameters
        N_steps = 100
        rate = rospy.Rate(10)
        
        """
        TODO Create an (N_steps, 4, 4) array for the cartesian positions along the trajectory.
        To do this, divide the distance between the start and target positions into N equal steps.
        """
        
        ########################################################
        #traj = np.linspace(self.initial_pos,  self.goal_pos, N_steps)
        #traj = np.zeros((N_steps, 7))
        traj = np.linspace( self.initial_pos_joint_space.q,  self.goal_pos_joint_space.q, N_steps)



        ###########################################################################        
        # Predefefinition of trajectory in joint space
        #traj_joint_space = np.zeros((N_steps, 7))
        
        #for k in range(N_steps):
            
       
          
         #   if k == 0:
          #      traj_joint_space_k = self.panda.ikine_LM(SE3(traj[k]), q0=self.start_q)
           # else:
            #    traj_joint_space_k = self.panda.ikine_LM(SE3(traj[k]), q0=traj_joint_space[k-1])
                
            # Store joint values of the ik solution to the joint space trajectory
            #traj_joint_space[k] = traj_joint_space_k.q
            
            
        i = 0
        
        while not rospy.is_shutdown():

            """
            TODO Take the positions from the trajectory as commands for the joint position
            """
            if i < N_steps: 
                self.joint_pos_msg.points[0].positions = traj[i]
            else:
                self.joint_pos_msg.points[0].positions = traj[N_steps-1]

            print(self.joint_pos_msg.points[0].positions)

            """
            TODO Publish the message here
            """
            self.joint_pos_publisher.publish(self.joint_pos_msg) 
            
            i = i + 1
            
            rate.sleep()


if __name__ == '__main__':
    rospy.init_node('cartesian_trajectory_copy', anonymous=False)
    n = Node()
    n.run()
    
    
