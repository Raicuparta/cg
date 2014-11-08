#include "River.h"

River::River() : StaticObject() {
	_width = 15;
	_height = 5;
	_position = new Vector3(0, 3, 0);
}

River::~River()
{
}

void River::draw() {
	glColor3f(121/255.f, 184/255.f, 175/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 5.f, 0.f);
	glutSolidCube(1);
	glPopMatrix();
}

