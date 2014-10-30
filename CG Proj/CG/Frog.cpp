#include "Frog.h"
#include <iostream>

#define SPEED 0.02

Frog::Frog() : DynamicObject() {
	_position = new Vector3(0, -7, 0);
	_speed = *(new Vector3(0, 0, 0));
}

Frog::~Frog()
{
}

void Frog::draw() {

	
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glTranslatef(0, 0, 7);

		//corpo
		
		glPushMatrix();
		glColor3f(0.f, 0.6f, 0.f);
		glScalef(2.f, 2.f, 5.f);
		glutSolidSphere(1.f, 20.f, 20.f);
		glPopMatrix();

		//cabeca
		glPushMatrix();
		glColor3f(0.f, 0.6f, 0.f);
		glTranslatef(0.f, 0.f, 3.5f);
		glScalef(4.f, 2.f, 3.f);
		glutSolidSphere(1.f, 20.f, 20.f);
		glPopMatrix();


		glColor3f(1.f, 1.f, 1.f);

		//olho direito
		glPushMatrix();
		glTranslatef(1.f, 0.f, 6.f);
		glScalef(1.f, 1.f, 2.f);
		glutSolidSphere(1.f, 5.f, 5.f);
		glPopMatrix();

		//olho esquerdo
		glPushMatrix();
		glTranslatef(-1.f, 0.f, 6.f);
		glScalef(1.f, 1.f, 2.f);
		glutSolidSphere(1.f, 5.f, 5.f);
		glPopMatrix();

		glColor3f(0.2f, 0.6f, 0.2f);

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

		glColor3f(0.1f, 0.8f, 0.1f);

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

		glColor3f(0.f, 0.3f, 0.f);

		//pe direito
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