#include "Frog.h"
#include <iostream>

#define SPEED 0.1

Frog::Frog() : DynamicObject() {
	_position = new Vector3(0, -7, 0);
}

Frog::~Frog()
{
}

void Frog::draw() {
	std::cout << "x: " << _position->getX() << " y: " << _position->getY() << " z: " << _position->getZ() << std::endl;

	//corpo do sapo
	glPushMatrix();
	glColor3f(0.f, 0.6f, 0.f);
	glTranslatef(_position->getX(), _position->getY(), _position->getZ()+1);

	glScalef(0.7f, 0.7f, 0.7f);
	glutSolidSphere(.5f, 20.f, 20.f);
	glPopMatrix();

	//pata superior direita
	glPushMatrix();
	glColor3f(.0f, .9f, .0f);
	glTranslatef(_position->getX() + 0.3, _position->getY() + 0.3, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//pata superior esquerda
	glPushMatrix();
	glColor3f(.0f, .9f, .0f);
	glTranslatef(_position->getX() - 0.3, _position->getY() + 0.3, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//pata inferior esquerda
	glPushMatrix();
	glColor3f(.0f, .9f, .0f);
	glTranslatef(_position->getX() - 0.3, _position->getY() - 0.3, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//pata inferior direita
	glPushMatrix();
	glColor3f(.0f, .9f, .0f);
	glTranslatef(_position->getX() + 0.3, _position->getY() - 0.3, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
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
