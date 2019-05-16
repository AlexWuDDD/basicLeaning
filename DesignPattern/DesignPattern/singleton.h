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
			//�����������������е���Դ�����磺db���ӣ��ļ������
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