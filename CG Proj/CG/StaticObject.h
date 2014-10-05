#pragma once
#include "GameObject.h"
class StaticObject :
	public GameObject
{
public:
	StaticObject(std::vector<GameObject*>& game_objects);
	~StaticObject();
	virtual void draw();
};



