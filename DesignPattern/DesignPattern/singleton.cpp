#include "singleton.h"

Singleton* Singleton::m_pSingleton = NULL;
std::mutex Singleton::m_mutex;

Singleton::GC Singleton::GC::gc; //��Ҫ

/*
�ڳ������н���ʱ��ϵͳ����� Singleton �ľ�̬��Ա GC �����������������������������Դ���ͷš����ַ�ʽ������ŵ�����ڡ���֪�������н��У����ԣ���������˵����Ϊʡ�ġ�
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