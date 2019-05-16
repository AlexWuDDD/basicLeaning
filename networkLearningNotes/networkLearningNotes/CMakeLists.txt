# CMakeList.txt : CMake project for networkLearningNotes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (mytestapp main.cpp
	getaddrinfo.h mysocket.h mybind.h myconnect.h mylisten.h myaccept.h sendandrecv.h
	sendtoandrecvfrom.h getXXXXname.h
	server1.h)

# TODO: Add tests and install targets if needed.
