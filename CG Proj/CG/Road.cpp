#include "Road.h"

Road::Road() : StaticObject() {
	_width = 15;
	_height = 5;
	_position = new Vector3(0, -3, 0);
	Draw::loadTexture("roadAsphalt.bmp", &_bmpWidth, &_bmpHeight, &_bmpSize, (unsigned char**)&_imageData);
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

	// allocate a texture name
	/*glGenTextures( 1, &texture );

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
		glTranslatef(-7.5, -5.5, 0.5);
		Draw::plane(25, 60, 15, 5);
	glPopMatrix();*/
	

	glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB , _bmpWidth, _bmpHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, _imageData);
    
	glPushMatrix();
		glTranslatef(-7.5, -5.5, 0.5);
		Draw::texturedPlane(25, 60, 15, 5, _texture);
	glPopMatrix();
}