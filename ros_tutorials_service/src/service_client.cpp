#include "ros/ros.h"//로스 기본 헤더 파일
#include "ros_tutorials_service/SrvTutorial.h" //빌드 후 생성되는 해더
#include <cstdlib> //atoll 함수를사용하기 위한 lib

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client");// node name initialize

    if (argc != 3)// 입력값 오류 처리
    {
        ROS_INFO("cmd: rosroun ros_tutorials_service service_client arg0 arg1");
        ROS_INFO("arg0: double number, arg1: double number");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient ros_tutorials_service_client=
    nh.serviceClient<ros_tutorials_service::SrvTutorial>("ros_tutorial_srv");

    //srv이름의 srvTutorial service 파일을 이용하는 서비스 선언
    ros_tutorials_service::SrvTutorial srv;
    
    //서비스 요청 값으로 노드가 실행 될 때, 입력으로 사용된 매개변수를  ab 에 저장
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);//str to int
    //서비스가 요청하고, 요청이 받아들여지면 응답을 값에 저장
    if(ros_tutorials_service_client.call(srv))// call 요청
    {
        ROS_INFO("send srv, srv.Request.a and b: %ld, %ld",(long int)srv.request.a, (long int)srv.request.b);
        ROS_INFO("receive srv, srv.Response.result:%ld",(long int)srv.response.result);
    }
    else
    {
        ROS_ERROR("Fail to call service ros_tutorial_srv");
        return 1;
    }
    return 0;   
}