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
	for(float i = -7.5; i < 7.5 ; i += 1) {
		float j = 0.5;
		glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glVertex3f(i , j, 0.5);
		glVertex3f(i , j-1, 0.5);
		glVertex3f(i+1 , j-1, 0.5);
		glVertex3f(i+1 , j, 0.5);
		glEnd();
		
	}

	//Ao lado da estrada (Largura = 2)
	for(float i = -7.5; i < 7.5 ; i += 1) {
		for(float j = -5.5; j > -7.5; j -= 1) {
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

	/*
	glPushMatrix();

	//Altura RoadSide (lado do rio)
	for(float k = -7.5; k < 7.5; k += 1) {
			glBegin(GL_QUADS);
			glNormal3f(0, 1, 0);
			glVertex3f(k , 0.5, 0.5);
			glVertex3f(k , 0.5, 0);
			glVertex3f(k+1 , 0.5, 0);
			glVertex3f(k+1 , 0.5, 0.5);
			glEnd();
	}

	//Altura RoadSide (lado da estrada)
	for(float k = -7.5; k < 7.5; k += 1) {
			glBegin(GL_QUADS);
			glNormal3f(0, -1, 0);
			glVertex3f(k , -0.5, 0.5);
			glVertex3f(k , -0.5, 0);
			glVertex3f(k+1 , -0.5, 0);
			glVertex3f(k+1 , -0.5, 0.5);
			glEnd();
	}

	glPopMatrix();
	*/
}
