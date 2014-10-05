#pragma once
#include "DynamicObject.h"
class Frog :
	public DynamicObject
{
public:
	Frog(std::vector<GameObject*>& game_objects);
	~Frog();
	void draw();
};

