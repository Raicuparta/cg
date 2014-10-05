#pragma once
#include "DynamicObject.h"
class TimberLog :
	public DynamicObject
{
public:
	TimberLog(std::vector<GameObject*>& game_objects);
	~TimberLog();
	void draw();
};

