#pragma once
#include <thread>
//!!!!!  一些需要注意的点

/*-------------------------- 1 --------------------------*/
void f(int i, std::string const& s) {}
void not_oops(int some_param)
{
	char buffer[1024];
	sprintf(buffer, "%i", some_param);
	std::thread t(f, 3, std::stringbuf(buffer)); //Using std::string avoids dangling pointer
	t.detach();
}

/*-------------------------- 2 --------------------------*/
void update_data_for_widget(widget_id w, widget_data& data);
void oops_again(widget_id w)
{
	widget_data data;
	std::thread t(update_data_for_widget, w, std::ref(data));
	display_status();
	t.join();
	process_widget_data(data);
}

/*-------------------------- 3 --------------------------*/
void some_function();
void some_other_function();
std::thread t1(some_function);
std::thread t2 = std::move(t1);
t1 = std::thread(some_other_function);
std::thread t3;
t3 = std::move(t2);
t1 = std::move(t3); //the assignment will terminate program!
