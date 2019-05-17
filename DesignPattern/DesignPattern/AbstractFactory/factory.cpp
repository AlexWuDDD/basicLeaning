#include "factory.h"
#include "concrete_factory.h"
#include <iostream>
using namespace std;

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#endif


AFactory* AFactory::CreateFactory(FACTORY_TYPE factory)
{
	AFactory* pFactory = NULL;
	switch (factory) {
		case FACTORY_TYPE::BENZ_FACTORY:
			pFactory =  new BenzFactory();
			break;
		case FACTORY_TYPE::BMW_FACTORY:
			pFactory = new BmwFactory();
			break;
		case FACTORY_TYPE::AUDI_FACTORY:
			pFactory = new AudiFactory();
			break;
		default:
			break;
	}
	return pFactory;
}

int AFtest()
{
	//±¼³Û
	AFactory* pFactroy = AFactory::CreateFactory(AFactory::FACTORY_TYPE::BENZ_FACTORY);
	ICar* pCar = pFactroy->CreateCar();
	IBike* pBike = pFactroy->CreateBike();

	cout << "Benz Factory- Car" << pCar->Name() << std::endl;
	cout << "Benz Factory- Bike" << pBike->Name() << std::endl;

	SAFE_DELETE(pCar);
	SAFE_DELETE(pBike);
	SAFE_DELETE(pFactroy);

	//±¦Âí
	pFactroy = AFactory::CreateFactory(AFactory::FACTORY_TYPE::BMW_FACTORY);
	pCar = pFactroy->CreateCar();
	pBike = pFactroy->CreateBike();

	cout << "Bmw Factory- Car" << pCar->Name() << std::endl;
	cout << "Bmw Factory- Bike" << pBike->Name() << std::endl;

	SAFE_DELETE(pCar);
	SAFE_DELETE(pBike);
	SAFE_DELETE(pFactroy);

	//°ÂµÏ
	pFactroy = AFactory::CreateFactory(AFactory::FACTORY_TYPE::AUDI_FACTORY);
	pCar = pFactroy->CreateCar();
	pBike = pFactroy->CreateBike();

	cout << "Audi Factory- Car" << pCar->Name() << std::endl;
	cout << "Audi Factory- Bike" << pBike->Name() << std::endl;

	SAFE_DELETE(pCar);
	SAFE_DELETE(pBike);
	SAFE_DELETE(pFactroy);

	getchar();
	return 0;
}