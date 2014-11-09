#include "TimberLog.h"

TimberLog::TimberLog() : DynamicObject() {
	_position = new Vector3(0, 1, 0);
	_speed = *(new Vector3(0, 0, 0));
	_width = 3;
	_height = 1;
}

TimberLog::~TimberLog() {
}

void TimberLog::draw() {
	
	/******** versao com cilindro
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(90.f, 0, 1, 0 );
    glColor3f(0.5,0.3,0.1);
    glBegin(GL_POLYGON);
    GLUquadricObj *obj = gluNewQuadric();
 
    gluCylinder(obj, 1.0, 1, 5, 30, 30);	//gluCylinder(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks)
 
	glPopMatrix();*/


	/******versao com cubo*******/
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
		glColor3f(166/255.f, 115/255.f, 86/255.f);
		glScalef(2.5f, 0.8f, 1.f);
		glutSolidCube(1);
	glPopMatrix();
}