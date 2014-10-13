#pragma once
#include "DynamicObject.h"
class Frog :
	public DynamicObject
{
public:
	Frog();
	~Frog();
	void draw();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

