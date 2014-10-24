#include "RiverSide.h"

RiverSide::RiverSide() : StaticObject() {
}

RiverSide::~RiverSide()
{
}

void RiverSide::draw() {
	glColor3f(1.f, 0.f, 0.f);
	glPushMatrix();
	glTranslatef(0.f, 6.5f, 0.f);
	glScalef(15.f, 2.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();

}
