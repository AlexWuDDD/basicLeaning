# CMakeList.txt : CMake project for networkLearningNotes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (mytestapp main.cpp
	getaddrinfo.h mysocket.h mybind.h myconnect.h mylisten.h myaccept.h sendandrecv.h
	sendtoandrecvfrom.h getXXXXname.h)

add_executable(server1 server1.cpp)
add_executable(client1 client1.cpp)
add_executable(listener1 listener1.cpp)
add_executable(talker1 talker1.cpp)
add_executable(myselect myselect.cpp)
add_executable(selectServer selectServer.cpp)

# TODO: Add tests and install targets if needed.
