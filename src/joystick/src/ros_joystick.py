#!/usr/bin/python
import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist


def on_joy_data(data):
    """

    :type data: Joy
    """
    msg = Twist()
    msg.linear.x = data.axes[1]
    msg.angular.z = data.axes[2]
    pub.publish(msg)

rospy.init_node("joystick_teleoperation")
sub = rospy.Subscriber("joy", Joy, on_joy_data)
pub = rospy.Publisher("cmd_vel", Twist, queue_size=1)
rospy.spin()
