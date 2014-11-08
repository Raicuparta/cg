#pragma once
#include "Entity.h"

class GameObject :
	public Entity
{
protected:
	double _width, _height;

public:
	GameObject();
	~GameObject();
	virtual void draw();
	bool collidesWith(GameObject* obj);
	double getXMin();
	double getYMin();
	double getXMax();
	double getYMax();
};

