#pragma once

#include "concrete_product.h"

#include "product.h"

// 工厂接口
class AFactory
{
public:
	virtual ICar* CreateCar() = 0;  // 生产汽车
};
