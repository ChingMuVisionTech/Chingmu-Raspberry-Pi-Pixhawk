#! /usr/bin/env python3
# coding:utf-8
import rospy
from geometry_msgs.msg import PoseStamped

body_id = 0
node_name = "MCServer"


def ugv_pose_callback(pose_stamped):
    print("pos:",
          " x: ", round(pose_stamped.pose.position.x, 3),
          " y: ",  round(pose_stamped.pose.position.y, 3),
          " z: ", round(pose_stamped.pose.position.z, 3))


if __name__ == '__main__':
    # create node
    rospy.init_node("vrpn_python_demo")

    # create subscriber
    topic_name = "/vrpn_client_node/" + node_name + "/" + str(body_id) + "/pose"
    rospy.Subscriber(topic_name, PoseStamped, ugv_pose_callback)

    rospy.spin()
