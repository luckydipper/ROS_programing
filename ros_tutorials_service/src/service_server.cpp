#include "ros/ros.h"
#include "ros_tutorials_service/SrvTutorial.h"

enum Operator
{
    PLUS = 0,
    MINUS, 
    MULTIPLICATION,
    DIVISION
};

int g_operator = PLUS;

//service 요청이 있는 경우, 아래 수행
//service 요청은 req, 응답은 res
bool calculation(ros_tutorials_service::SrvTutorial::Request &req,
ros_tutorials_service::SrvTutorial::Response &res)
{
    //서비스 요청받을 시, 값을 더해서 응답값에 저장
    //res.result = req.a + req.b;


    switch(g_operator)
    {
        case PLUS:
        res.result = req.a + req.b; break;
        case MINUS:
        res.result = req.a - req.b; break;
        case MULTIPLICATION:
        res.result = req.a * req.b; break;
        case DIVISION:
        if(req.b == 0){
            res.result = 0; break;
        }
        else{
            res.result = req.a/req.b; break;
        }
        default:
            res.result = req.a + req.b; break;
    }
    ROS_INFO("request: x=%ld, y=%ld",(long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: %ld", (long int)res.result);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv, "service_server"); // 노드 이름 초기화
    ros::NodeHandle nh; //node handle 선언

    nh.setParam("calculation_method",PLUS); //매개변수 초기 설정
    //서버 선언, rㅐs_tutorial service 패키지의 srvtutorial 서비스 파일을 이용.
    //서비스 서버 rostutorial s service server를 선언
    //서비스 명은 ros_tutorial srv , 서비스 요청이 있을 때 계산.
    ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);
    ROS_INFO("ready srv server!");

    //ros::spin(); //서비스 요청을 무조건 대기함.


    //계속 확인하려고 roop를 돌고 있음.
    ros::Rate r(10); // 10hz
    while(1)
    {
        nh.getParam("calculation_method",g_operator); // 연산자를 매개변수로 붙어 받은 값으로 변경
        ros::spinOnce();// 콜백 함수 처리 루틴
        r.sleep();//루틴 반복을 위한 sleep 처리
    }
    
    return 0;
}