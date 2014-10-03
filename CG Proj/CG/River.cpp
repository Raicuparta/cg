#include "River.h"
#include <windows.h>
#include <GL/glut.h>


River::River()
{
}


River::~River()
{
}

void River::draw() {
	glColor3f(0.1f, 0.3f, 0.9f);
	glPushMatrix();
	glTranslatef(0.f, 3.f, 0.f);
	glScalef(15.f, 5.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();
}

