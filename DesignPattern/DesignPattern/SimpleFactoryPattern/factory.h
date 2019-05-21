#pragma once

#include "concrete_product.h"

// ����
class Factory
{
public:
	enum CAR_TYPE {
		BENZ_CAR,  // ��������
		BMW_CAR,  // ��������
		AUDI_CAR  // �µ�����
	};

	// ��������
	ICar* CreateCar(CAR_TYPE type) {
		ICar* pCar = NULL;
		switch (type) {
		case CAR_TYPE::BENZ_CAR:
			pCar = new BenzCar();  // ��������
			break;
		case CAR_TYPE::BMW_CAR:
			pCar = new BmwCar();  // ��������
			break;
		case CAR_TYPE::AUDI_CAR:
			pCar = new AudiCar();  // �µ�����
			break;
		default:
			break;
		}
		return pCar;
	}
};