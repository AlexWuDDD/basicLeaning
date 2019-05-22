// DesignPattern.cpp : Defines the entry point for the application.
//

#include "DesignPattern.h"
#include "singleton.h"
#include "AbstractFactory/factory.h"
#include "BuildPattern/testBuildPattern.h"
#include "PrototypePattern/testPP.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	//testSingleton();
	//AFtest();
	//testBuildPattern();
	testPP();
	return 0;
}
