#include "Car.h"
#include <stdlib.h> /* srand, rand */

Car::Car() : DynamicObject() {
	int rando = rand() % 5 + 1;
	rando *= -1;
	_position = new Vector3(0, rando, 0);
}

Car::~Car()
{
}

void Car::draw() {

	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());

		//corpo do carro

		glColor3f(0.5f, 0.5f, 0.f);
		glScalef(1.0f, 0.5f, 0.5f);
		glutSolidCube(1);


		//rodas esquerdas
		glPushMatrix();
			glColor3f(0.5f, .0f, 0.f);
			glTranslatef(0.4, -0.5, 0);
			glRotatef(90.f, 1, 0, 0 );
			glutSolidTorus(.1f, .2f, 50, 100);
			glTranslatef(-0.8, 0, 0);
			glutSolidTorus(.1f, .2f, 50, 100);
		glPopMatrix();

		//rodas direitas
		glPushMatrix();
			glColor3f(0.5f, .0f, 0.f);
			glTranslatef(0.4, 0.5, 0);
			glRotatef(90.f, 1, 0, 0 );
			glutSolidTorus(.1f, .2f, 50, 100);
			glTranslatef(-0.8, 0, 0);
			glutSolidTorus(.1f, .2f, 50, 100);
		glPopMatrix();

	glPopMatrix();

}
