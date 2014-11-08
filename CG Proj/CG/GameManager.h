#include <vector>
#include <GL/glut.h>
#include <iostream>
#include "GameObject.h"
#include "River.h"
#include "RiverSide.h"
#include "Road.h"
#include "RoadSide.h"
#include "Frog.h"
#include "Car.h"
#include "TimberLog.h"
#include "Camera.h"
#include "OrthogonalCamera.h"
#include "PerspectiveCamera.h"
#include "Limit.h"
#pragma once

class GameManager {
	int _current_time;
	int _previous_time;
public:
	GameManager();
	~GameManager();
	void display();
	void reshape(GLsizei width, GLsizei height);
	void keyPressed(unsigned char key, int x, int y);
	void keyReleased(unsigned char key, int x, int y);
	void onTimer(int value);
	void idle();
	void update(double dt);
	void init();
	void reset();
};