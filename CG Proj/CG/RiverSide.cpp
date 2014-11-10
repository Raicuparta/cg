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
		glTranslatef(-7.5, 5.5, 0.5);
		Draw::plane(10, 60, 15, 2);
	glPopMatrix();

	glPushMatrix();
		//Altura RiverSide
		glTranslatef(-7.5, 5.5, 0);
		glRotatef(90, 1, 0, 0);
		Draw::plane(5, 60, 15, 0.5);
	glPopMatrix();

}

