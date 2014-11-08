#pragma once
#include "DynamicObject.h"
class Car :
	public DynamicObject
{
public:
	Car();
	~Car();
	void draw();
	void drawHexagon();
};

