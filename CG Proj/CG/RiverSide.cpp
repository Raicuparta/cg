#include "RiverSide.h"

RiverSide::RiverSide() : StaticObject() {
	_position = new Vector3(0, 6.5, 0);
	_width = 15;
	_height = 2;
}

RiverSide::~RiverSide()
{
}

void RiverSide::draw() {
	glColor3f(191/255.f, 216/255.f, 99/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 2.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();

}
