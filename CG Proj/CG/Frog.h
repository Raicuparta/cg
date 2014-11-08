#pragma once
#include "DynamicObject.h"
#include "TimberLog.h"
class Frog :
	public DynamicObject
{
private:
	TimberLog* _log;

public:
	Frog();
	~Frog();
	void draw();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void kill();
	void update(double dt);
	void setLog(TimberLog* log);
};

