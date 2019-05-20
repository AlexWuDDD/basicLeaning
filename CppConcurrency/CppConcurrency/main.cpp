// CppConcurrency.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <thread>
#include "Chapter2.h"
#include "Listing2_1.h"
#include "Listing2_2.h"
#include <assert.h>

using std::cout;
using std::endl;

void hello()
{
	cout << "Hello Concurrent World" << endl;
}


int main()
{
//	std::thread t(hello);
//	t.join();
//	t.detach();
//	assert(!t.joinable());
	cout << "this computer can has " << std::thread::hardware_concurrency() << " CPU cores!" <<  endl;

	return 0;
}

//page 31
