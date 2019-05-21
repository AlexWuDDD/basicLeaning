#pragma once

#include "product.h"

// ±¼³ÛÆû³µ
class BenzCar : public ICar
{
public:
	string Name() {
		return "Benz Car";
	}
};

// ±¦ÂíÆû³µ
class BmwCar : public ICar
{
public:
	string Name() {
		return "Bmw Car";
	}
};

// °ÂµÏÆû³µ
class AudiCar : public ICar
{
public:
	string Name() {
		return "Audi Car";
	}
};