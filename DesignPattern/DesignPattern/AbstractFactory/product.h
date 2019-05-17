#pragma once
//在我们的示例中， 需要有两个产品 --- 汽车和自行车
#include <string>
using namespace std;

//汽车接口
class ICar
{
public:
	virtual string Name() = 0; //汽车名称
};

//自行车接口
class IBike
{
public:
	virtual string Name() = 0; //自行车接口
};