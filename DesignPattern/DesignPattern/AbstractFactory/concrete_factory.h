#pragma once
#include "factory.h"
#include "concrete_product.h"

//���۹���
class BenzFactory : public AFactory
{
public:
	ICar* CreateCar() {
		return new BenzCar();
	}

	IBike* CreateBike() {
		return new BenzBike();
	}
};

//������
class BmwFactory : public AFactory
{
public:
	ICar* CreateCar() {
		return new BmwCar();
	}

	IBike* CreateBike() {
		return new BmwBike();
	}
};

//���۹���
class AudiFactory : public AFactory
{
public:
	ICar* CreateCar() {
		return new AudiCar();
	}

	IBike* CreateBike() {
		return new AudiBike();
	}
};