#pragma once
#include "DynamicObject.h"
#include "TimberLog.h"
class Frog :
	public DynamicObject
{
private:
	TimberLog* _log;
	float _angle;
	bool _faceCamera;

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
	void setAngle(float angle);
	float getAngle();
	void faceCamera();
};

