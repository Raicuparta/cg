#pragma once
#include "GameObject.h"
class DynamicObject :
	public GameObject
{
public:
	DynamicObject(std::vector<GameObject*>& game_objects);
	~DynamicObject();
	virtual void draw();
};

