#pragma once
#include "Entity.h"
class GameObject :
	public Entity
{
public:
	GameObject();
	~GameObject();
	virtual void draw();
};

