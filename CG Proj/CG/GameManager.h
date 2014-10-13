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
#pragma once

class GameManager {
public:
	GameManager(int value);
	~GameManager();
	//void display();
	//void reshape(GLsizei width, GLsizei height);
	//void keyboard(unsigned char key, int x, int y);
	//void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();
};