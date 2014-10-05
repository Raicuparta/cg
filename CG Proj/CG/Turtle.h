#pragma once
#include "DynamicObject.h"
class Turtle :
	public DynamicObject
{
public:
	Turtle(std::vector<GameObject*>& game_objects);
	~Turtle();
	void draw();
};

