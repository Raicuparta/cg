#include "Frog.h"
#include <iostream>

#define SPEED 0.01

Frog::Frog() : DynamicObject() {
	_position = new Vector3(0, -6, 1);
	_speed = *(new Vector3(0, 0, 0));
	_width = 0.5;
	_height = 0.5;
}

Frog::~Frog()
{

}

void Frog::draw() {

	GLfloat amb[]={0.07f,0.66f,0.34f,1.0f};
	GLfloat diff[]={0.17f,0.4f,0.2f,1.0f};
	GLfloat spec[]={0.12f,0.16f,0.18f,1.0f};
	GLfloat shine=0;
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);


	
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(0.15f, 0.15f, 0.15f); //mudei aqui
	//glTranslatef(0, 0, 7);

		//corpo
		/*
		glPushMatrix();
		glColor3f(63/255.f, 120/255.f, 79/255.f);
		//glScalef(2.f, 2.f, 5.f);
		glutSolidSphere(3.f, 20.f, 20.f);
		glPopMatrix();
		*/

		//cabeca
		glPushMatrix();
		glColor3f(63/255.f, 120/255.f, 79/255.f);
		
		/*GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
		GLfloat mat_diffuse[] = { 0.6, 0.6, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.8, 0.8, 0.8, 1.0 };
		GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
		GLfloat mat_shine = 100.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv (GL_FRONT, GL_EMISSION, mat_emission);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);*/


		glTranslatef(0.f, 0.f, 3.5f);
		glScalef(4.f, 2.f, 3.f);
		glutSolidSphere(1.f, 20.f, 20.f);
		glPopMatrix();




		//glColor3f(0.2f, 0.6f, 0.2f);
		glColor3f(63/255.f, 120/255.f, 79/255.f);

		//articulacao perna direita
		glPushMatrix();
		glTranslatef(1.f, 0.f, -2.f);
		glutSolidSphere(1.f, 5.f, 5.f);
		glPopMatrix();

		//articulacao perna esquerda
		glPushMatrix();
		glTranslatef(-1.f, 0.f, -2.f);
		glutSolidSphere(1.f, 5.f, 5.f);
		glPopMatrix();

		//glColor3f(0.1f, 0.8f, 0.1f);
		glColor3f(63/255.f, 120/255.f, 79/255.f);

		//perna direita
		glPushMatrix();
		glTranslatef(1.f, 0.f, -3.5f);
		glScalef(1.f, 1.f, 3.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();
		
		//perna esquerda
		glPushMatrix();
		glTranslatef(-1.f, 0.f, -3.5f);
		glScalef(1.f, 1.f, 3.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();

		//glColor3f(0.f, 0.3f, 0.f);
		glColor3f(63/255.f, 120/255.f, 79/255.f);

		/*//pe direito
		glPushMatrix();
		glTranslatef(1.f, 0.f, -5.5f);
		glScalef(1.5f, 3.f, 1.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();

		//pe esquerdo
		glPushMatrix();
		glTranslatef(-1.f, 0.f, -5.5f);
		glScalef(1.5f, 3.f, 1.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();*/

		GLfloat amb1[]={0.07f,0.66f,0.34f,1.0f};
		GLfloat diff1[]={0.17f,0.4f,0.2f,1.0f};
		GLfloat spec1[]={0.12f,0.16f,0.18f,1.0f};
		GLfloat shine1=10;
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec1);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine1);


		glColor3f(1.f, 1.f, 1.f);
		//olho direito
		glPushMatrix();
		glTranslatef(1.f, 0.f, 6.f);
		glScalef(1.f, 1.f, 2.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();

		//olho esquerdo
		glPushMatrix();
		glTranslatef(-1.f, 0.f, 6.f);
		glScalef(1.f, 1.f, 2.f);
		glutSolidSphere(1.f, 10.f, 10.f);
		glPopMatrix();

	glPopMatrix();

}

	void Frog::moveUp() {
		setSpeed(getSpeed()->getX(), getSpeed()->getY() + SPEED, getSpeed()->getZ());
	}

	void  Frog::moveDown() {
		setSpeed(getSpeed()->getX(), getSpeed()->getY() - SPEED, getSpeed()->getZ());
	}

	void  Frog::moveLeft() {
		setSpeed(getSpeed()->getX() - SPEED, getSpeed()->getY(), getSpeed()->getZ());
	}

	void  Frog::moveRight() {
		setSpeed(getSpeed()->getX() + SPEED, getSpeed()->getY(), getSpeed()->getZ());
	}

	void Frog::kill() {
		setPosition(0, -6, 1);
	}

	void Frog::update(double dt) {

		Vector3 speed = *getSpeed();
		Vector3 position = *getPosition();

		Vector3 newPosition = speed*dt + position;

		double xSpeedInc = 0;

		if (_log != NULL) {
			newPosition = newPosition + *_log->getSpeed()*dt;
		}

		if (abs(newPosition.getX()) > 7) {

			newPosition.set(getPosition()->getX(), newPosition.getY(), newPosition.getZ());
		}

		if (newPosition.getY() > 7 || newPosition.getY() < -6.1) {

			newPosition.set(newPosition.getX(), getPosition()->getY(), newPosition.getZ());
		}

		setPosition(newPosition);
	}

	void Frog::setLog(TimberLog* log) {
		_log = log;
	}