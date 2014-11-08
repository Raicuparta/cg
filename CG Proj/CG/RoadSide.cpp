#include "RoadSide.h"

RoadSide::RoadSide() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

RoadSide::~RoadSide() {

}

void RoadSide::draw() {
	glColor3f(189/255.f, 117/255.f, 118/255.f);
	glPushMatrix();
	glTranslatef(0.f, -6.f, 0.f);
	glScalef(15.f, 1.f, 1.f);
	glutSolidCube(1);
	glTranslatef(0.f, 6.f, 0.f);
	glutSolidCube(1);
	glPopMatrix();
}
