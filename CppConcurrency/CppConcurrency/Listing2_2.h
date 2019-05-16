#pragma once
#include "Listing2_1.h"
#include "Listing2_3.h"

void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);

}