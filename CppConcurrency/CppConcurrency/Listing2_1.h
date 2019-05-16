#pragma once
// A function that returns while a thread still has access to local variables
#include <iostream>
#include <thread>

struct func
{
	int& i;
	func(int i_):i(i_){}

	void operator()()
	{
		for (unsigned int j = 0; j < 1000000; ++j) {
			do_something(i);
		}
		std::cout << std::endl;
	}

	void do_something(int i) {
		std::cout << i << " ";
	}
	
};

void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.detach();
}