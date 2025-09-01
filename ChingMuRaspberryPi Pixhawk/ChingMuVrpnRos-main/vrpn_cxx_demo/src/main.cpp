#include <iostream>
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"


//Rigid body information seen on the chingmu client
int bodyId = 0;
std::string server_name = "MCServer/";

using namespace std;
//msg.pose.position : include location information
//msg.pose.oritation : Contains the quaternion of the rigid body, representing the attitude angle
void topicCallback(geometry_msgs::PoseStamped msg) {
    auto& pos = msg.pose.position;
    printf("pos: x: %02f,y: %02f,z: %02f\n",pos.x,pos.y,pos.z);
}

int main(int argc, char **argv) {
    std::string nodeName = "vrpn_cxx_demo_node";

    //Create a ROS node
    ros::init(argc, argv, nodeName);
    ros::NodeHandle node;

    //create subscriber
    std::string topicName = "/vrpn_client_node/" + server_name + "/" + to_string(bodyId) + "/pose";
    const ros::Subscriber &subscriber = node.subscribe(topicName, 10, topicCallback);

    // 阻塞线程
    ros::spin();
    return 0;
}
