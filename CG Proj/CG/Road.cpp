#include "Road.h"

Road::Road() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

Road::~Road() {

}

void Road::draw() {
	/*glColor3f(108/255.f, 82/255.f, 77/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 5.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();*/

	glPushMatrix();
	for(float i = -7.5; i <= 7.5 ; i += 1) {
		for(float j = -0.5; j >= -5.5; j -= 1) {
			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);
			glVertex3f(i , j, 0.5);
			glVertex3f(i , j-1, 0.5);
			glVertex3f(i+1 , j-1, 0.5);
			glVertex3f(i+1 , j, 0.5);
			glEnd();
		}
	}
	glPopMatrix();

}