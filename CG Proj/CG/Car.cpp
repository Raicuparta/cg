#include "Car.h"
#include <stdlib.h> /* srand, rand */

Car::Car() : DynamicObject() {
	_position = new Vector3(0, 0, 0);
	_speed = *(new Vector3(0.0008, 0, 0));
	_width = 1;
	_height = 0.6;

}

Car::~Car()
{
}

void Car::draw() {


		//Metallic Red
	GLfloat mat_ambient1[] = { .1, .1, .1, 1 };
	GLfloat mat_diffuse1[] = { .1, .1, .1, 1 };
	GLfloat mat_specular1[] = { .1, 0, 0, 1 };
	GLfloat mat_shininess1[] = { 2 };
	//Rubber Black
	GLfloat mat_ambient2[] = { .3, .3, .3, 1 };
	GLfloat mat_diffuse2[] = { .2, .2, .2, .5 };
	GLfloat mat_specular2[] = { .1, .1, .1, 1 };
	GLfloat mat_shininess2[] = { 5 };
	//Metallic Silver
	GLfloat mat_ambient3[] = { .7, .7, .7, 1 };
	GLfloat mat_diffuse3[] = { .3, .3, .3, 1 };
	GLfloat mat_specular3[] = { .7, .7, .7, 1 };
	GLfloat mat_shininess3[] = { 120 };
	//White Lights
	GLfloat mat_ambient4[] = { .9, .9, .5, 1 };
	GLfloat mat_diffuse4[] = { 1, .1, .1, 1 };
	GLfloat mat_specular4[] = { .4, .4, 0, 1 };
	GLfloat mat_shininess4[] = { 20 };
	GLfloat mat_emission4[] = { .5, .4, .1, 0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);


	glPushMatrix();

		glTranslatef(_position->getX(), _position->getY(), _position->getZ());
		glScalef(0.2, 0.15, 0.2);

		//tejadilho
		glPushMatrix();
			glTranslatef(0, 0, 1);
		


			glColor3d(1, 1, 0);
			
			//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission4);

			glBegin(GL_QUADS);
			glNormal3d(0, 0, 1);
			glVertex3d(-2,-1,0.5);
			glVertex3d(2,-1,0.5);
			glVertex3d(2,1,0.5);
			glVertex3d(-2,1,0.5);
			glEnd();


			//glColor3d(0, 0, 1);

			glBegin(GL_QUADS);
			glNormal3d(-1, 0, 1);
			
			glVertex3d(-2,1,0.5);
			glVertex3d(-2,-1,0.5);
			glVertex3d(-3,-2,-0.5);
			glVertex3d(-3,2,-0.5);
			glEnd();


			//glColor3d(1, 1, 0);

			glBegin(GL_QUADS);
			glNormal3d(1, 0, 1);
			glVertex3d(3,-2,-0.5);
			glVertex3d(3,2,-0.5);
			glVertex3d(2,1,0.5);
			glVertex3d(2,-1,0.5);
			glEnd();


			//glColor3d(0, 1, 1);

			glBegin(GL_QUADS);
			glNormal3d(0, 1, 1);
			glVertex3d(3,2,-0.5);
			glVertex3d(-3,2,-0.5);
			glVertex3d(-2,1,0.5);
			glVertex3d(2,1,0.5);
			glEnd();


			//glColor3d(1, 0, 1);

			glBegin(GL_QUADS);
			glNormal3d(0, -1, 1);
			glVertex3d(-3,-2,-0.5);
			glVertex3d(3,-2,-0.5);
			glVertex3d(2,-1,0.5);
			glVertex3d(-2,-1,0.5);
			glEnd();
		
		glPopMatrix();

		//carrocaria


		

		glPushMatrix();
		
			glTranslatef(0, 0, -0.5);
	

			//glColor3d(1, 1, 1);

			glBegin(GL_QUADS);
			glNormal3d(0, 0, 1);
			glVertex3d(-5,-2.5,1);
			glVertex3d(5,-2.5,1);
			glVertex3d(5,2.5,1);
			glVertex3d(-5,2.5,1);
			glEnd();
		
			glColor3d(0, 0, 1);

			glBegin(GL_QUADS);
			glNormal3d(0, -1, 0);
			glVertex3d(-5,-2.5,-1);
			glVertex3d(5,-2.5,-1);
			glVertex3d(5,-2.5,1);
			glVertex3d(-5,-2.5,1);
			glEnd();

			glColor3d(0, 0, 1);

			glBegin(GL_QUADS);
			glNormal3d(0, 1, 0);
			glVertex3d(-5,2.5,-1);
			glVertex3d(5,2.5,-1);
			glVertex3d(5,2.5,1);
			glVertex3d(-5,2.5,1);
			glEnd();

			glColor3d(1, 0, 0);

			glBegin(GL_QUADS);
			glNormal3d(1, 0, 0);
			glVertex3d(5,-2.5,-1);
			glVertex3d(5,2.5,-1);
			glVertex3d(5,2.5,1);
			glVertex3d(5,-2.5,1);
			glEnd();
		
			glColor3d(1, 0, 0);

			glBegin(GL_QUADS);
			glNormal3d(-1, 0, 0);
			glVertex3d(-5,-2.5,-1);
			glVertex3d(-5,2.5,-1);
			glVertex3d(-5,2.5,1);
			glVertex3d(-5,-2.5,1);
			glEnd();

		glPopMatrix();

		//rodas
		glTranslatef(0, 0, -2);

		glPushMatrix();
			glTranslatef(2.5, -2, 0);
			drawHexagon();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5, -2, 0);
			drawHexagon();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.5, 3, 0);
			drawHexagon();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.5, 3, 0);
			drawHexagon();
		glPopMatrix();


		//corpo do carro

		/*glColor3d(1.f, 225/255.f, 79/255.f);
		glPushMatrix();
		glScalef(1.0f, 0.5f, 0.5f);
		glutSolidCube(1);
		glPopMatrix();


		glPushMatrix();

		glTranslatef(0, 0, -0.2);

		glColor3d(81/255.f, 39/255.f, 38/255.f);
		//rodas esquerdas
		glPushMatrix();
			glTranslatef(0.4, -0.3, 0);
			glRotatef(90.f, 1, 0, 0 );
			glutSolidTorus(.1f, .2f, 50, 100);
			glTranslatef(-0.8, 0, 0);
			glutSolidTorus(.1f, .2f, 50, 100);
		glPopMatrix();

		//rodas direitas
		glPushMatrix();
			glTranslatef(0.4, 0.3, 0);
			glRotatef(90.f, 1, 0, 0 );
			glutSolidTorus(.1f, .2f, 50, 100);
			glTranslatef(-0.8, 0, 0);
			glutSolidTorus(.1f, .2f, 50, 100);
		glPopMatrix();

		glPopMatrix();*/


		/*GLfloat default_emission[] = { 0, 0, 0, 1 };
		glMaterialfv(GL_FRONT, GL_EMISSION, default_emission);*/

		glPopMatrix();

}


void Car::drawHexagon() {

	//copiado do proj da leo e do dany


	glRotatef(90, 1, 0, 0);
	double hexagonX[6];
	double hexagonY[6];

	for (int i = 0; i < 6; i++) {
		hexagonX[i] = cos((60 * i) * 3.14159265 / 180.0);
		hexagonY[i] = sin((60 * i) * 3.14159265 / 180.0);
		//std::cout << "<" << hexagonX[i] << "," << hexagonY[i] << ">" << std::endl;
	}

	//Front
	glNormal3d(0, 0, -1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 0);
	}
	glEnd();

	//Back
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; i++){
		glVertex3d(hexagonX[i], hexagonY[i], 1);
	}
	glEnd();

	//Sides
	for (int i = 0; i < 6; i++){

		glBegin(GL_QUADS);
		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 0);

		glNormal3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);
		glVertex3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);

		glNormal3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 0);
		glVertex3d(hexagonX[(i + 1) % 6], hexagonY[(i + 1) % 6], 1);

		glNormal3d(hexagonX[i], hexagonY[i], 0);
		glVertex3d(hexagonX[i], hexagonY[i], 1);
		glEnd();
	}
}