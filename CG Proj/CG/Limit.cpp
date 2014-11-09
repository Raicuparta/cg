#include "Limit.h"


Limit::Limit(void)
{
	_position = new Vector3(0, 0, 0);
	_width = 6;
	_height = 20;
}


Limit::~Limit(void)
{
}

void Limit::draw() {
	//glColor3f(81/255.f, 39/255.f, 38/255.f);
	glColor3f(57/255.f, 33/255.f, 32/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(6, 20, 20);
	
	
	glutSolidCube(1);
	glPopMatrix();
}