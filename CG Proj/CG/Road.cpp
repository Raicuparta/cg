#include "Road.h"

Road::Road() : StaticObject() {
	_position = new Vector3(0, -3, 0);
}

Road::~Road() {

}

void Road::draw() {

	//cor
	glColor3f(108/255.f, 82/255.f, 77/255.f);

	//material
	GLfloat amb[]={0.39f,0.26f,0.3f,1.0f};
	GLfloat diff[]={0.4f,0.27f,0.24f,1.0f};
	GLfloat spec[]={0.0f,0.0f,0.0f,1.0f};
	GLfloat shine=0;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

	//textura
	glEnable(GL_TEXTURE_2D);

	GLuint texture;

	// allocate a texture name
	glGenTextures( 1, &texture );

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
		glTranslatef(-7.5, -5.5, 0.5);
		Draw::plane(25, 60, 15, 5);
	glPopMatrix();

}