#pragma once
#include "product.h"

//抽象工厂
class AFactory
{
public:
	enum FACTORY_TYPE {
		BENZ_FACTORY,
		BMW_FACTORY,
		AUDI_FACTORY
	};

	virtual ICar* CreateCar() = 0; //生产汽车
	virtual IBike* CreateBike() = 0; //生产自行车
	static AFactory* CreateFactory(FACTORY_TYPE); //创建工厂
};

int AFtest();