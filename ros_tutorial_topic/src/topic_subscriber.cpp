#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h" //빌드 후 생성.
// 메세지 콜백함수 ros_tutorial_msg라는 토픽
// 메세지 수신시 동작
// 입력 메세지는 rostopic의 MsgTutorial메세지를 받음

void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
    ROS_INFO("recieve msg = %d", msg -> stamp.sec); //msg 표시
    ROS_INFO("recieve msg = %d", msg -> stamp.nsec);//msg 표시
    ROS_INFO("recieve msg = %d", msg -> data);//msg 표시
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "topic_subscriber");// 노드명 초기화
    
    ros::NodeHandle nh; // ros system과 통신을 위한 노드 핸들

    //subscriber 선언, ros_tutorial_topic package의 MsgTutorial메세지를 이용해
    //subscriber ros_tutorial_sub을 작성 topic명은 "ros_tutorial_msg"
    //subscriber que size 100
    ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

    //callback호출을 위한 함수, 메세지가 수신되기를 대기
    //수신이 되었을 경우, callback 함수 실행
    ros::spin();

    return 0;
}