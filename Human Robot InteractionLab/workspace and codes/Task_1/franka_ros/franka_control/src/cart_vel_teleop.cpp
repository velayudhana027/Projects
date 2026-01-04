// Testen: subscriber: Wert auf 1000


// Copyright (c) 2017 Franka Emika GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include <franka_control/cart_vel_teleop.h>

#include <array>
#include <cmath>
#include <memory>
#include <string>

#include <controller_interface/controller_base.h>
#include <hardware_interface/hardware_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>
#include <ros/node_handle.h>

#include <iostream>

#include <franka/robot_state.h>

#include <fstream>

namespace franka_control {

ros::NodeHandle nh;
ros::Subscriber sub_cart_vel;
std_msgs::Float64MultiArray cart_vel[6];

float v_x = 0.0;
float v_y = 0.0;
float v_z = 0.0;
float w_x = 0.0;
float w_y = 0.0;
float w_z = 0.0;

float v_x_old = 0.0;
float v_y_old = 0.0;
float v_z_old = 0.0;
float w_x_old = 0.0;
float w_y_old = 0.0;
float w_z_old = 0.0;

float acc_lim_lin = 0.1;
float acc_lim_ang = 0.1;

float check_acc_lim_lin(float is_value, float goal_value){
  float acc = (goal_value - is_value)/0.001;
  if (acc > acc_lim_lin) {
    goal_value = is_value + acc_lim_lin * 0.001;
  }
  if (acc < -acc_lim_lin) {
    goal_value = is_value - acc_lim_lin * 0.001;
  }
  return goal_value;
}

float check_acc_lim_ang(float is_value, float goal_value){
  float acc = (goal_value - is_value)/0.001;
  if (acc > acc_lim_ang) {
    goal_value = is_value + acc_lim_ang * 0.001;
  }
  if (acc < -acc_lim_ang) {
    goal_value = is_value - acc_lim_ang * 0.001;
  }
  return goal_value;
}


bool CartVelTeleop::init(hardware_interface::RobotHW* robot_hardware, ros::NodeHandle& node_handle) {

  sub_cart_vel = nh.subscribe("cartesian_velocity", 10, &CartVelTeleop::cartVelCallback, this);//, ros::TransportHints().reliable().udp()
  //sub_cart_vel = nh.subscribe("cartesian_velocity", 1000, &CartVelTeleop::cartVelCallback);

  std::string arm_id;
  if (!node_handle.getParam("arm_id", arm_id)) {
    ROS_ERROR("CartVelTeleop: Could not get parameter arm_id");
    return false;
  }

  velocity_cartesian_interface_ =
      robot_hardware->get<franka_hw::FrankaVelocityCartesianInterface>();
  if (velocity_cartesian_interface_ == nullptr) {
    ROS_ERROR(
        "CartVelTeleop: Could not get Cartesian velocity interface from "
        "hardware");
    return false;
  }
  try {
    velocity_cartesian_handle_ = std::make_unique<franka_hw::FrankaCartesianVelocityHandle>(
        velocity_cartesian_interface_->getHandle(arm_id + "_robot"));
  } catch (const hardware_interface::HardwareInterfaceException& e) {
    ROS_ERROR_STREAM(
        "CartVelTeleop: Exception getting Cartesian handle: " << e.what());
    return false;
  }

  auto state_interface = robot_hardware->get<franka_hw::FrankaStateInterface>();
  if (state_interface == nullptr) {
    ROS_ERROR("CartVelTeleop: Could not get state interface from hardware");
    return false;
  }

  // try {
  //   auto state_handle = state_interface->getHandle(arm_id + "_robot");

  //   std::array<double, 7> q_start = {{0, -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4}};
  //   for (size_t i = 0; i < q_start.size(); i++) {
  //     if (std::abs(state_handle.getRobotState().q_d[i] - q_start[i]) > 0.1) {
  //       ROS_ERROR_STREAM(
  //           "CartVelTeleop: Robot is not in the expected starting position "
  //           "for running this example. Run `roslaunch franka_example_controllers "
  //           "move_to_start.launch robot_ip:=<robot-ip> load_gripper:=<has-attached-gripper>` "
  //           "first.");
  //       return false;
  //     }
  //   }
  // } catch (const hardware_interface::HardwareInterfaceException& e) {
  //   ROS_ERROR_STREAM(
  //       "CartVelTeleop: Exception getting state handle: " << e.what());
  //   return false;
  // }

  return true;
}

void CartVelTeleop::starting(const ros::Time& /* time */) {
  elapsed_time_ = ros::Duration(0.0);
}

void CartVelTeleop::update(const ros::Time& /* time */, const ros::Duration& period) {

  float v_x_temp = v_x;
  v_x_temp = check_acc_lim_lin(v_x_old, v_x);
  v_x_old = v_x_temp;

  float v_y_temp = v_y;
  v_y_temp = check_acc_lim_lin(v_y_old, v_y);
  v_y_old = v_y_temp;

  float v_z_temp = v_z;
  v_z_temp = check_acc_lim_lin(v_z_old, v_z);
  v_z_old = v_z_temp;
 
  float w_x_temp = w_x; 
  w_x_temp = check_acc_lim_ang(w_x_old, w_x);
  w_x_old = w_x_temp;

  float w_y_temp = w_y;
  w_y_temp = check_acc_lim_ang(w_y_old, w_y);
  w_y_old = w_y_temp;

  float w_z_temp = w_z;
  w_z_temp = check_acc_lim_ang(w_z_old, w_z);
  w_z_old = w_z_temp;
  
  //std::array<double, 6> command = {{v_x, 0.0, 0.0, 0.0, 0.0, 0.0}};
  //std::array<double, 6> command = {{v_x, v_y, v_z, w_x, w_y, w_z}};
  std::array<double, 6> command = {{v_x_temp, v_y_temp, v_z_temp, w_x_temp, w_y_temp, w_z_temp}};
  //std::array<double, 6> command = {{v_x_temp, v_y_temp, v_z_temp, 0.0, 0.0, 0.0}};
  velocity_cartesian_handle_->setCommand(command);
  
}

void CartVelTeleop::stopping(const ros::Time& /*time*/) {
  // WARNING: DO NOT SEND ZERO VELOCITIES HERE AS IN CASE OF ABORTING DURING MOTION
  // A JUMP TO ZERO WILL BE COMMANDED PUTTING HIGH LOADS ON THE ROBOT. LET THE DEFAULT
  // BUILT-IN STOPPING BEHAVIOR SLOW DOWN THE ROBOT.
  

}


void CartVelTeleop::cartVelCallback(const std_msgs::Float64MultiArray::ConstPtr& msg) {
  v_x = msg->data[0];
  v_y = msg->data[1];
  v_z = msg->data[2];
  w_x = msg->data[3];
  w_y = msg->data[4];
  w_z = msg->data[5];
}

/*void CartVelTeleop::cartVelCallback(const std_msgs::Float64::ConstPtr& msg) {
  v_x = msg->data;
  v_y = msg->data[1];
  v_z = msg->data[2];
  w_x = msg->data[3];
  w_y = msg->data[4];
  w_z = msg->data[5];
}
*/

}  // namespace franka_example_controllers

PLUGINLIB_EXPORT_CLASS(franka_control::CartVelTeleop,
                       controller_interface::ControllerBase)
