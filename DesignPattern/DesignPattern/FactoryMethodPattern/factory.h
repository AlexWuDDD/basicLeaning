#pragma once

#include "concrete_product.h"

#include "product.h"

// �����ӿ�
class AFactory
{
public:
	virtual ICar* CreateCar() = 0;  // ��������
};
