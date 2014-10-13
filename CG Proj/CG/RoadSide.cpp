#include "RoadSide.h"

RoadSide::RoadSide() : StaticObject() {
}

RoadSide::~RoadSide() {

}

void RoadSide::draw() {
	glColor3f(0.4f, 0.1f, 0.7f);
	glPushMatrix();
	glTranslatef(0.f, -6.f, 0.f);
	glScalef(15.f, 1.f, 1.f);
	glutSolidCube(1);
	glTranslatef(0.f, 6.f, 0.f);
	glutSolidCube(1);
	glPopMatrix();
}
