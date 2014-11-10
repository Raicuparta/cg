#include "RoadSide.h"

RoadSide::RoadSide() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

RoadSide::~RoadSide() {

}

void RoadSide::draw() {
	/*
	glPushMatrix();
	glTranslatef(0.f, -6.f, 0.f);
	glScalef(15.f, 1.f, 1.f);
	glutSolidCube(1);
	glTranslatef(0.f, 6.f, 0.f);
	glutSolidCube(1);
	glPopMatrix();*/

	glColor3f(189/255.f, 117/255.f, 118/255.f);

	GLfloat amb[]={0.91f,0.37f,0.47f,1.0f};
	GLfloat diff[]={0.7f,0.37f,0.35f,1.0f};
	GLfloat spec[]={0.14f,0.1f,0.07f,1.0f};
	GLfloat shine=25;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

	//Entre o rio e a estrada (Largura = 1)
	glPushMatrix();
		glTranslatef(-7.5, -0.5, 0.5);
		Draw::plane(10, 60, 15, 1);
	glPopMatrix();

	//Ao lado da estrada (Largura = 2)
	glPushMatrix();
		glTranslatef(-7.5, -7.5, 0.5);
		Draw::plane(10, 60, 15, 2);
	glPopMatrix();

}
