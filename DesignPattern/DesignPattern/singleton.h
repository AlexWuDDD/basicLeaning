#pragma once

#include <iostream>
#include <mutex>

class Singleton
{
public:
	static Singleton* GetInstance();
private:
	Singleton() {};
private:
	static Singleton* m_pSingleton;
	static std::mutex m_mutex; 

	class GC
	{
	public:
		~GC()
		{
			//可以在这里销毁所有的资源，例如：db连接，文件句柄等
			if (m_pSingleton != NULL) {
				std::cout << "Here destory the m_pSingleton" << std::endl;
				delete m_pSingleton;
				m_pSingleton = NULL;
			}
		}
		static GC gc;
	};
};

int testSingleton();