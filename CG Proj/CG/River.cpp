#include "River.h"

River::River() : StaticObject() {
	_width = 15;
	_height = 5;
	_position = new Vector3(0, 3, 0);
	Draw::loadTexture("river.bmp", &_bmpWidth, &_bmpHeight, &_bmpSize, (unsigned char**)&_imageData);
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

	glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _bmpWidth, _bmpHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, _imageData);
    

	glPushMatrix();
		glTranslatef(-7.5, 0.5, 0.2);
		Draw::texturedPlane(25, 60, 15, 5, _texture);
	glPopMatrix();

}

