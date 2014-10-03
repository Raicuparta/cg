#pragma once
#include "GameObject.h"
class DynamicObject :
	public GameObject
{
public:
	DynamicObject();
	~DynamicObject();
	virtual void draw();
};

