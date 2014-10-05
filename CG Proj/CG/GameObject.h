#pragma once
#include "Entity.h"

class GameObject :
	public Entity
{
public:
	GameObject(std::vector<GameObject*>& game_objects);
	~GameObject();
	virtual void draw();
};

