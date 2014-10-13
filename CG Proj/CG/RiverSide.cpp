#include "RiverSide.h"

RiverSide::RiverSide() : StaticObject() {
}

RiverSide::~RiverSide()
{
}

void RiverSide::draw() {
	glColor3f(0.3f, 0.7f, 0.1f);
	glPushMatrix();
	glTranslatef(0.f, 6.5f, 0.f);
	glScalef(15.f, 2.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();

}
