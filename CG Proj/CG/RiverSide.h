#pragma once
#include "StaticObject.h"
class RiverSide :
	public StaticObject
{
public:
	RiverSide(std::vector<GameObject*>& game_objects);
	~RiverSide();
	void draw();
};

