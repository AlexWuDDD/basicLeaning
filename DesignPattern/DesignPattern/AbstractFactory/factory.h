#pragma once
#include "product.h"

//���󹤳�
class AFactory
{
public:
	enum FACTORY_TYPE {
		BENZ_FACTORY,
		BMW_FACTORY,
		AUDI_FACTORY
	};

	virtual ICar* CreateCar() = 0; //��������
	virtual IBike* CreateBike() = 0; //�������г�
	static AFactory* CreateFactory(FACTORY_TYPE); //��������
};

int AFtest();