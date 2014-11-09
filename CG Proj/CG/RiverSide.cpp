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
	/*glColor3f(191/255.f, 216/255.f, 99/255.f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 2.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();*/

	glPushMatrix();
	for(float i = -7.5; i < 7.5 ; i += 1) {
		for(float j = 7.5; j > 5.5; j -= 1) {
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

	glPushMatrix();

	//Altura RiverSide
	for(float k = -7.5; k < 7.5; k += 1) {
			glBegin(GL_QUADS);
			glNormal3f(0, -1, 0);
			glVertex3f(k , 5.5, 0.5);
			glVertex3f(k , 5.5, 0);
			glVertex3f(k+1 , 5.5, 0);
			glVertex3f(k+1 , 5.5, 0.5);
			glEnd();
	}

	glPopMatrix();

}

