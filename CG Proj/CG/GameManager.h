#include <GL/glut.h>
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

