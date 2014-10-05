#pragma once
#include "StaticObject.h"
class RoadSide :
	public StaticObject
{
public:
	RoadSide(std::vector<GameObject*>& game_objects);
	~RoadSide();
	void draw();
};

