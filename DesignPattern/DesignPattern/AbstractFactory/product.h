#pragma once
//�����ǵ�ʾ���У� ��Ҫ��������Ʒ --- ���������г�
#include <string>
using namespace std;

//�����ӿ�
class ICar
{
public:
	virtual string Name() = 0; //��������
};

//���г��ӿ�
class IBike
{
public:
	virtual string Name() = 0; //���г��ӿ�
};