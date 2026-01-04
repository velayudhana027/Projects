#!/usr/bin/env python3

"""
Setting limits for robot's collision behavior.
"""

import rospy
from franka_msgs.srv import SetForceTorqueCollisionBehavior, SetForceTorqueCollisionBehaviorRequest, SetForceTorqueCollisionBehaviorResponse
from franka_msgs.srv import SetFullCollisionBehavior, SetFullCollisionBehaviorRequest, SetFullCollisionBehaviorResponse
from controller_manager_msgs.srv import SwitchController, SwitchControllerRequest
import time


def set_limits():
	# Controllers to be stopped in between:
	ctrl1 = 'cart_vel_teleop'
	ctrl2 = 'franka_state_controller'


	collisionService = rospy.ServiceProxy('/franka_control/set_force_torque_collision_behavior', SetForceTorqueCollisionBehavior)
	controllerService = rospy.ServiceProxy('/controller_manager/switch_controller', SwitchController)


	## Stop controllers:
	req = SwitchControllerRequest()
	req.strictness = SwitchControllerRequest.BEST_EFFORT
	req.stop_controllers.append(ctrl1)
	req.stop_controllers.append(ctrl2)
	res1 = controllerService(req)
	print("Controllers stopped")

	rospy.wait_for_service('/franka_control/set_force_torque_collision_behavior', timeout=5.0)

	time.sleep(1)


	## Set Collision behavior
	behavior = SetForceTorqueCollisionBehaviorRequest()
	behavior.lower_torque_thresholds_nominal = [100.0] * 7
	behavior.upper_torque_thresholds_nominal = [100.0] * 7
	behavior.lower_force_thresholds_nominal = [100.0] * 6
	behavior.upper_force_thresholds_nominal = [100.0] * 6
	res2 = collisionService(behavior)
	print("Collision behavior changed")
	print(behavior)

	rospy.wait_for_service('/controller_manager/switch_controller', timeout=5.0)

	time.sleep(1)


	## Start controllers again:
	req = SwitchControllerRequest()
	req.stop_controllers = []
	req.start_controllers.append(ctrl1)
	req.start_controllers.append(ctrl2)
	res3 = controllerService(req)
	print("Controllers started again")


def set_limits_full():
	# Controllers to be stopped in between:
	ctrl1 = 'cart_vel_teleop'
	ctrl2 = 'franka_state_controller'


	collisionService = rospy.ServiceProxy('/franka_control/set_full_collision_behavior', SetFullCollisionBehavior)
	controllerService = rospy.ServiceProxy('/controller_manager/switch_controller', SwitchController)


	## Stop controllers:
	req = SwitchControllerRequest()
	req.strictness = SwitchControllerRequest.STRICT
	req.stop_controllers.append(ctrl1)
	req.stop_controllers.append(ctrl2)
	res1 = controllerService(req)
	print("Controllers stopped")

	rospy.wait_for_service('/franka_control/set_full_collision_behavior', timeout=5.0)

	time.sleep(1)


	## Set Collision behavior
	behavior = SetFullCollisionBehaviorRequest()
	behavior.lower_torque_thresholds_nominal = [20.0] * 7
	behavior.upper_torque_thresholds_nominal = [20.0] * 7
	behavior.lower_force_thresholds_nominal = [20.0] * 6
	behavior.upper_force_thresholds_nominal = [20.0] * 6
	behavior.lower_torque_thresholds_acceleration = [20.0] * 7
	behavior.upper_torque_thresholds_acceleration = [20.0] * 7
	behavior.lower_force_thresholds_acceleration = [20.0] * 6
	behavior.upper_force_thresholds_acceleration = [20.0] * 6
	res2 = collisionService(behavior)
	print("Collision behavior changed")
	print(behavior)

	rospy.wait_for_service('/controller_manager/switch_controller', timeout=5.0)

	time.sleep(1)


	## Start controllers again:
	req = SwitchControllerRequest()
	req.strictness = SwitchControllerRequest.STRICT
	req.stop_controllers = []
	req.start_controllers.append(ctrl1)
	req.start_controllers.append(ctrl2)
	res3 = controllerService(req)
	print("Controllers started again")


if __name__ == "__main__":
	set_limits_full()
	print("------ CONTROLLER STARTED ------")




