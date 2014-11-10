#include "Limit.h"


Limit::Limit(void)
{
	_position = new Vector3(0, 0, 0);
	_width = 0;
	_height = 0;

}


Limit::~Limit(void)
{
}

void Limit::draw() {
	GLdouble eq1[4] = { 1, 0.0, 0.0, 0.0 };
	glPushMatrix();
	glTranslatef(-_position->getX(), _position->getY(), _position->getZ());
	glClipPlane(GL_CLIP_PLANE0, eq1);
	glEnable(GL_CLIP_PLANE0);
	glPopMatrix();

	GLdouble eq2[4] = { -1, 0.0, 0.0, 0.0 };
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glClipPlane(GL_CLIP_PLANE1, eq2);
	glEnable(GL_CLIP_PLANE1);
	glPopMatrix();
}