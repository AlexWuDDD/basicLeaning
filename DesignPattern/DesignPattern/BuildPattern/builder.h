#pragma once

#include "product.h"

class IBuilder
{
public:
	virtual void BuildCpu() = 0; 
	virtual void BuildMainboard() = 0;
	virtual void BuildRam() = 0;
	virtual void BuildVideoCard() = 0;
	virtual Computer* GetResult() = 0;
};