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

	glColor3f(166/255.f, 115/255.f, 86/255.f);

	GLfloat amb[]={0.34f,0.3f,0.22f,1.0f};
	GLfloat diff[]={0.45f,0.29f,0.25f,1.0f};
	GLfloat spec[]={0.1f,0.1f,0.1f,1.0f};
	GLfloat shine=54;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
		glScalef(2.5f, 0.8f, 1.f);
		glutSolidCube(1);
	glPopMatrix();
}