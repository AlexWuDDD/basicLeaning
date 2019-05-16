#pragma once
#include <iostream>
#include <thread>

class background_task
{
public:
	void operator()() const
	{
		do_something();
		do_something_else();
	}

	void do_something() const {
		std::cout << "do something" << std::endl;
	}

	void do_something_else() const {
		std::cout << "do something else" << std::endl;
	}
};

int testChapter2_1()
{
	background_task f;
	std::thread my_thread(f);
	my_thread.join();
	return 0;
}