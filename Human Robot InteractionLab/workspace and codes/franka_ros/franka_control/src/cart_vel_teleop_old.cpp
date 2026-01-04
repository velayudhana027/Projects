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

float smoothing(float is_value, float goal_value){
  float smoothed_value = 0.99 * is_value + 0.01 * goal_value;
  return smoothed_value;
}


bool CartVelTeleop::init(hardware_interface::RobotHW* robot_hardware, ros::NodeHandle& node_handle) {

  sub_cart_vel = nh.subscribe("cartesian_velocity", 1000, &CartVelTeleop::cartVelCallback, this, ros::TransportHints().reliable().tcpNoDelay());
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

  // std::cout << w_x << std::endl;
  // std::cout << w_y << std::endl;
  // std::cout << w_z << std::endl;
  // std::array<double, 6> command = {{v_x, v_y, v_z, w_x, w_y, w_z}};

  v_x = smoothing(v_x_old, v_x);
  v_x_old = v_x;

  v_y = smoothing(v_y_old, v_y);
  v_y_old = v_y;

  v_z = smoothing(v_z_old, v_z);
  v_z_old = v_z;
  
  w_x = smoothing(w_x_old, w_x);
  w_x_old = w_x;

  w_y = smoothing(w_y_old, w_y);
  w_y_old = w_y;

  w_z = smoothing(w_z_old, w_z);
  w_z_old = w_z;
  
  std::array<double, 6> command = {{v_x, v_y, v_z, w_x, w_y, w_z}};
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



}  // namespace franka_example_controllers

PLUGINLIB_EXPORT_CLASS(franka_control::CartVelTeleop,
                       controller_interface::ControllerBase)
