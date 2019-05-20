#pragma once
#include "concrete_builder.h"
#include "director.h"
#include <string.h>

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) if(p){delete (p); (p) = NULL;}
#endif

int testBuildPattern();