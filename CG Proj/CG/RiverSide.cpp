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
	/*
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 2.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();*/


	glColor3f(191/255.f, 216/255.f, 99/255.f);

	GLfloat amb[]={0.49f,0.83f,0.39f,1.0f};
	GLfloat diff[]={0.48f,0.63f,0.26f,1.0f};
	GLfloat spec[]={0.16f,0.22f,0.1f,1.0f};
	GLfloat shine=25;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

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

