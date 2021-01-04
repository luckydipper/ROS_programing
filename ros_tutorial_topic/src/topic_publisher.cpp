#include "ros/ros.h"//ros기본 headerfile
#include "ros_tutorials_topic/MsgTutorial.h"//빌드 후 생성되는 headerfile

int main(int argc,char **argv)//node main function
{
    ros::init(argc,argv,"topic_publisher"); //노드 이름 초기화
    ros::NodeHandle nh; //통신을 위한 핸들 선언
    
    //publisher 선언, ros_tutorial_topic 패키지의 MsgTutorial 메세지 파일을 이용하여,
    //ros_tutorial_pub 작성. 토픽명은 "ros_tutorial_msg",
    //publisher 큐(queue)사이즈를 100개로 설정
    ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg",100);
    //loop 주기가 10hz, 0.1초마다 반복
    ros::Rate loop_rate(10);
    //MsgTutorial 메세지 파일 형식으로 msg 파일 선언
    ros_tutorials_topic::MsgTutorial msg;
    int count = 0;
 
    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); // 현재 시간을 msg 하위 stamp에 담는다.
        msg.data = count; // count라는 변수 값을 msg의 하위 data에 담는다.

        //printf error warnning 종류별로 info 볼 수 있어. fatal
        ROS_INFO("send msg = %d", msg.stamp.sec);//stamp의 메세지 표시
        ROS_INFO("send msg = %d", msg.stamp.nsec);//stamp의 메세지 표시
        ROS_INFO("send msg = %d", msg.data); //data메세지를 표시

        ros_tutorial_pub.publish(msg); //msg 발행
        loop_rate.sleep();// 루프 주기에 따라 sleep
        ++ count;//count 1씩 증가
    }

    return 0;
}

