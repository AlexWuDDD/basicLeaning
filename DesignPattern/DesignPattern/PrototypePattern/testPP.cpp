#include "testPP.h"

int testPP()
{
	//�����
	Monkey* pSWK = new SunWuKong("Qi Tian Da Sheng");

	//��¡���Ӻ���
	Monkey* pSWK1 = pSWK->Clone();
	Monkey* pSWK2 = pSWK->Clone();

	pSWK1->Play();
	pSWK2->Play();

	SAFE_DELETE(pSWK1);
	SAFE_DELETE(pSWK2);
	SAFE_DELETE(pSWK);

	getchar();
	return 0;
}