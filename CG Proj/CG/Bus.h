#pragma once
#include "DynamicObject.h"
class Bus :
	public DynamicObject
{
public:
	Bus(std::vector<GameObject*>& game_objects);
	~Bus();
	void draw();
};

