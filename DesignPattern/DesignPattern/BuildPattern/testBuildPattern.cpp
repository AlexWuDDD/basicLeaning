#include "testBuildPattern.h"

int testBuildPattern()
{
	Director* pDirector = new Director();
	ThinkPadBuilder* pTPBuilder = new ThinkPadBuilder();
	YogaBuilder* pYogaBuilder = new YogaBuilder();

	//��װThinkPad, Yoga
	pDirector->Create(pTPBuilder);
	pDirector->Create(pYogaBuilder);

	//��ȡ��װ��ĵ���
	Computer* pThinkPadComputer = pTPBuilder->GetResult();
	Computer* pYogaComputer = pYogaBuilder->GetResult();

	// �������
	cout << "-----ThinkPad-----" << endl;
	cout << "CPU: " << pThinkPadComputer->GetCPU() << endl;
	cout << "Mainboard: " << pThinkPadComputer->GetMainboard() << endl;
	cout << "Ram: " << pThinkPadComputer->GetRam() << endl;
	cout << "VideoCard: " << pThinkPadComputer->GetVideoCard() << endl;

	cout << "-----Yoga-----" << endl;
	cout << "CPU: " << pYogaComputer->GetCPU() << endl;
	cout << "Mainboard: " << pYogaComputer->GetMainboard() << endl;
	cout << "Ram: " << pYogaComputer->GetRam() << endl;
	cout << "VideoCard: " << pYogaComputer->GetVideoCard() << endl;

	SAFE_DELETE(pThinkPadComputer);
	SAFE_DELETE(pYogaComputer);
	SAFE_DELETE(pTPBuilder);
	SAFE_DELETE(pYogaBuilder);
	SAFE_DELETE(pDirector);

	getchar();

	return 0;
}