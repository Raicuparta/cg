#include "Road.h"

Road::Road() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

Road::~Road() {

}

void Road::draw() {
	glColor3f(108/255.f, 82/255.f, 77/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 5.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();
}