#include "singleton.h"

Singleton* Singleton::m_pSingleton = NULL;
std::mutex Singleton::m_mutex;

Singleton::GC Singleton::GC::gc; //重要

/*
在程序运行结束时，系统会调用 Singleton 的静态成员 GC 的析构函数，该析构函数会进行资源的释放。这种方式的最大优点就是在“不知不觉”中进行，所以，对我们来说，尤为省心。
*/

Singleton* Singleton::GetInstance()
{
	if (m_pSingleton == NULL) {
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_pSingleton == NULL) {
			m_pSingleton = new Singleton();
		}
	}
	return m_pSingleton;
}

int testSingleton()
{
	Singleton* pSingleton1 = Singleton::GetInstance();
	Singleton* pSingleton2 = Singleton::GetInstance();

	std::cout << (pSingleton1 == pSingleton2) << std::endl;
	return 0;
}