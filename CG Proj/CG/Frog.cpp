#include "Frog.h"

#define SPEED 0.005

Frog::Frog() : DynamicObject() {
	_position = new Vector3(0, -6, 1);
	_speed = *(new Vector3(0, 0, 0));
	_width = 0.5;
	_height = 0.3;
	_angle = 0;
	_faceCamera = false;
}

Frog::~Frog()
{

}

void Frog::draw() {

	glColor3f(63/255.f, 120/255.f, 79/255.f);
	GLfloat amb[]={0.07f,0.66f,0.34f,1.0f};
	GLfloat diff[]={0.17f,0.4f,0.2f,1.0f};
	GLfloat spec[]={0.12f,0.16f,0.18f,1.0f};
	GLfloat shine=0;

	if(_faceCamera) {
		diff[0] = 0; diff[1] = 0; diff[2] = 0; diff[3] = 0;
		spec[0] = 0; spec[1] = 0; spec[2] = 0; spec[3] = 0;
	}
		
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(0.1f, 0.1f, 0.1f);
	glTranslatef(1, 1, 1);
	if (!_faceCamera) {
		glRotatef(_angle, 0, 0, 1);
	} else {
		glRotatef(-90, 1, 0, 0);
		glRotatef(180, 0, 0, 1);
		glScalef(0.7f, 0.7f, 0.7f);
	}
	

		//corpo
		glPushMatrix();
		glScalef(6.f, 4.f, 4.f);
		glutSolidCube(1);
		glPopMatrix();
		


		//pernas

		//perna esquerda
		glPushMatrix();
		glTranslatef(-2, 0, -4);
		glScalef(1, 1 ,4);
		glutSolidCube(1);
		glPopMatrix();

		//perna direita
		glPushMatrix();
		glTranslatef(2, 0, -4);
		glScalef(1, 1 ,4);
		glutSolidCube(1);
		glPopMatrix();


		//bracos

		//ombro esquerdo
		glPushMatrix();
		glTranslatef(-4, 0, 0);
		glScalef(2, 1 ,1);
		glutSolidCube(1);
		glPopMatrix();

		//ombro direito
		glPushMatrix();
		glTranslatef(4, 0, 0);
		glScalef(2, 1 ,1);
		glutSolidCube(1);
		glPopMatrix();

		//braco esquerdo
		glPushMatrix();
		glTranslatef(-4.5, 0, 1);
		glScalef(1, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();

		//braco direito
		glPushMatrix();
		glTranslatef(4.5, 0, 1);
		glScalef(1, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();


		//palpebra direita
		glPushMatrix();
		
		glTranslatef(3.f, 1.5f, 2.f);
		glScalef(2, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();

		//palpebra esquerda
		glPushMatrix();
		
		glTranslatef(-3.f, 1.5f, 2.f);
		glScalef(2, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();

		//palpebra esquerda

		GLfloat amb2[]={1.0f,1.0f,1.0f,1.0f};
		GLfloat diff2[]={1.0f,1.0f,1.0f,1.0f};
		GLfloat spec2[]={0.0f,0.0f,0.0f,1.0f};
		GLfloat shine2=0;
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb2);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff2);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec2);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine2);

		glColor3f(1.f, 1.f, 1.f);
		//olho direito
		glPushMatrix();
		glTranslatef(3.f, 2.5f, 2.f);
		glScalef(2, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();

		//olho esquerdo
		glPushMatrix();
		glTranslatef(-3.f, 2.5f, 2.f);
		glScalef(2, 1 ,2);
		glutSolidCube(1);
		glPopMatrix();

		

	glPopMatrix();

}

	void Frog::moveUp() {
		setSpeed(0, SPEED, getSpeed()->getZ());
	}

	void  Frog::moveDown() {
		setSpeed(0, -SPEED, getSpeed()->getZ());
	}

	void  Frog::moveLeft() {
		setSpeed(-SPEED, 0, getSpeed()->getZ());
	}

	void  Frog::moveRight() {
		setSpeed(+SPEED, 0, getSpeed()->getZ());
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

	void Frog::setAngle(float angle) {
		_angle = angle;
	}

	void Frog::faceCamera() {
		_faceCamera = true;
	}

	float Frog::getAngle() {
		return _angle;
	}