#include "Car.h"
#include <stdlib.h> /* srand, rand */

Car::Car(std::vector<GameObject*>& game_objects) : DynamicObject(game_objects) {
	int rando = rand() % 5 + 1;
	rando *= -1;
	_position = new Vector3(-7, rando, 0);
}

Car::~Car()
{
}

void Car::draw() {
	//corpo do carro
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.f);
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(1.0f, 0.5f, 0.5f);
	glutSolidCube(1);
	glPopMatrix();

	//roda dianteira direita
	glPushMatrix();
	glColor3f(0.5f, .0f, 0.f);
	glTranslatef(_position->getX() + 0.25, _position->getY() - 0.25, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidTorus(.3f, .6f, 50, 100);
	glPopMatrix();

	//roda dianteira esquerda
	glPushMatrix();
	glColor3f(0.5f, .0f, 0.f);
	glTranslatef(_position->getX() + 0.25, _position->getY() + 0.25, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidTorus(.3f, .6f, 50, 100);
	glPopMatrix();


	//roda traseira direita
	glPushMatrix();
	glColor3f(0.5f, .0f, 0.f);
	glTranslatef(_position->getX() - 0.25, _position->getY() - 0.25, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidTorus(.3f, .6f, 50, 100);
	glPopMatrix();

	//roda traseira esquerda
	glPushMatrix();
	glColor3f(0.5f, .0f, 0.f);
	glTranslatef(_position->getX() - 0.25, _position->getY() + 0.25, _position->getZ());
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidTorus(.3f, .6f, 50, 100);
	glPopMatrix();
}
