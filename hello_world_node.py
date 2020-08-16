#/user/bine/env python
import rospy
from std_msgs.msg import String
def talker():
    pub = rospy.Publisher('hello_pub', String, queue_size=10)
