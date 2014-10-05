#include <vector>
#include <GL/glut.h>
#include "GameObject.h"
#include "River.h"
#include "RiverSide.h"
#include "Road.h"
#include "RoadSide.h"
#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();
	void display();
	void reshape(GLsizei width, GLsizei height);
	void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();

};

