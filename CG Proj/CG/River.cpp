#include "River.h"

River::River() : StaticObject() {
	_width = 15;
	_height = 5;
	_position = new Vector3(0, 3, 0);
}

River::~River()
{
}

void River::draw() {
	/*
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 5.f, 0.f);
	glutSolidCube(1);
	glPopMatrix();*/

	glColor3f(121/255.f, 184/255.f, 175/255.f);

	GLfloat amb[]={0.24f,0.61f,0.72f,1.0f};
	GLfloat diff[]={0.49f,0.49f,0.39f,1.0f};
	GLfloat spec[]={0.39f,0.29f,0.22f,1.0f};
	GLfloat shine=40;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

	glPushMatrix();
		glTranslatef(-7.5, 0.5, 0.2);
		Draw::plane(25, 60, 15, 5);
	glPopMatrix();

}

