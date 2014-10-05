#pragma once
#include "StaticObject.h"
class Road :
	public StaticObject
{
public:
	Road(std::vector<GameObject*>& game_objects);
	~Road();
	void draw();
};

