// DesignPattern.cpp : Defines the entry point for the application.
//

#include "DesignPattern.h"
#include "singleton.h"
#include "AbstractFactory/factory.h"
#include "BuildPattern/testBuildPattern.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	//testSingleton();
	//AFtest();
	testBuildPattern();
	
	return 0;
}
