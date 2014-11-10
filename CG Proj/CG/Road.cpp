#include "Road.h"

Road::Road() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

Road::~Road() {

}

void Road::draw() {
	/*
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(15.f, 5.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();*/



	glColor3f(108/255.f, 82/255.f, 77/255.f);

	GLfloat amb[]={0.39f,0.26f,0.3f,1.0f};
	GLfloat diff[]={0.4f,0.27f,0.24f,1.0f};
	GLfloat spec[]={0.0f,0.0f,0.0f,1.0f};
	GLfloat shine=0;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);


	glPushMatrix();
	/*for(float i = -7.5; i < 7.5 ; i += 1) {
		for(float j = -0.5; j >= -4.5; j -= 1) {
			glBegin(GL_QUADS);
			glNormal3f(0, 0, 1);
			glVertex3f(i , j, 0.5);
			glVertex3f(i , j-1, 0.5);
			glVertex3f(i+1 , j-1, 0.5);
			glVertex3f(i+1 , j, 0.5);
			glEnd();
		}
	}*/
		glTranslatef(-7.5, -5.5, 0.5);
		Draw::plane(25, 60, 15, 5);

	glPopMatrix();

}