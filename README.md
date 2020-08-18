# ROS_programing
+ hello_world
topic 형태로 String type으로 정보를 주고 받음. package를 만들때, python 위의 #!/usr/bin/env python이 써지지 않으면 실행 자체가 안됨!! 주의!<br>

hello_world package안에 src에 python node를 넣어야 하는줄 알았는데 밖으로 빼서 script에서 만든 것이 특이함. 그리고 환경변수 설정에도 주의 해야함. 한글자 잘못 쳤더니, 실행도 안되고 디버깅도 힘듬. catkin_make를 만들어야지, devel이랑 build가 생김.<br>
그리고 출처를 밝히는 CMakeList.txt랑 package.xml을 쓰지 않았는데 실행됐다. ㅇㅁㅇ
