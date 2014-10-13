#pragma once
#include <vector>
#include <GL/glut.h>
#include "Vector3.h"
class Entity
{
protected:
	Vector3* _position;
public:
	Entity();
	~Entity();
	Vector3* getPosition();
	Vector3* setPosition(double x, double y, double z);
	Vector3* setPosition(Vector3 &vec);
};

