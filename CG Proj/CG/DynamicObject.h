#pragma once
#include "GameObject.h"
#include "Vector3.h"
class DynamicObject :
	public GameObject
{
protected:
	Vector3 _speed;

public:
	DynamicObject(std::vector<GameObject*>& game_objects);
	~DynamicObject();
	virtual void draw();
	void setSpeed(const Vector3& speed);
	void setSpeed(double x, double y, double z);
	Vector3 getSpeed();
};

