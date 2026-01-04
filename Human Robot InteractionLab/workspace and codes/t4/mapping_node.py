#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec  3 18:44:02 2025

@author: hri-lab-Velayudhan
"""
import rospy
from std_msgs.msg import Int16
from std_msgs.msg import Float32

class MappingNode:

    def __init__(self):
        rospy.init_node('mapping_node', anonymous=True)
        self.max_sensor_force = rospy.get_param('/max_sensor_force')
        if self.max_sensor_force <= 0:
            rospy.logerr("Parameter /max_sensor_force must be a positive integer.")
            rospy.signal_shutdown("Invalid max sensor force parameter.")
            return
        self.raw_force = 0
        self.subscriber = rospy.Subscriber('/pub_force', Int16, self.force_callback)
        self.publisher = rospy.Publisher('/force_mapped', Float32, queue_size=10)
        self.rate = rospy.Rate(50) 
        
    def force_callback(self, data):
        self.raw_force = data.data

    def map_force(self, raw_value):
        if raw_value > self.max_sensor_force:
            mapped_value = 1.0
        elif raw_value < 0:
            mapped_value = 0.0
        else:
            mapped_value = float(raw_value) / float(self.max_sensor_force)            
        return mapped_value
    
    def run(self):
        while not rospy.is_shutdown():
            mapped_force = self.map_force(self.raw_force)
            msg = Float32()
            msg.data = mapped_force
            self.publisher.publish(msg)
            self.rate.sleep()


if __name__ == '__main__':
    try:
        node = MappingNode()
        node.run()
    except rospy.ROSInterruptException:
        pass

