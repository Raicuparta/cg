#pragma once
#include "StaticObject.h"
class River :
	public StaticObject
{
public:
	River(std::vector<GameObject*>& game_objects);
	~River();
	void draw();
};

