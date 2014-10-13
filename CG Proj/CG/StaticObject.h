#pragma once
#include "GameObject.h"
class StaticObject :
	public GameObject
{
public:
	StaticObject();
	~StaticObject();
	virtual void draw();
};



