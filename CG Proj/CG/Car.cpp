#include "Car.h"
#include <stdlib.h> /* srand, rand */

Car::Car() : DynamicObject() {
	_position = new Vector3(0, 0, 0);
	_speed = *(new Vector3(0.0008, 0, 0));
	_width = 2;
	_height = 0.6;

}

Car::~Car()
{
}

void Car::draw() {



	glPushMatrix();

		glTranslatef(_position->getX(), _position->getY(), _position->getZ());
		glScalef(0.2, 0.15, 0.2);

		//tejadilho
		glColor3d(1.f, 150/255.f, 50/255.f);

		GLfloat amb[]={0.57f,0.36f,0.09f,1.0f};
		GLfloat diff[]={0.5, 0.5, 0.5};
		GLfloat spec[]={0.1, 0.1, 0.1};
		GLfloat shine=1;
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);

		glPushMatrix();
			glTranslatef(0, 0, 1);
			glScalef(1, 1, 2);
			
			glBegin(GL_QUADS);
			glNormal3d(0, 0, 1);
			glVertex3d(-2,-1,0.5);
			glVertex3d(2,-1,0.5);
			glVertex3d(2,1,0.5);
			glVertex3d(-2,1,0.5);
			glEnd();

			glBegin(GL_QUADS);
			glNormal3d(-1, 0, 1);
			
			glVertex3d(-2,1,0.5);
			glVertex3d(-2,-1,0.5);
			glVertex3d(-3,-2,-0.5);
			glVertex3d(-3,2,-0.5);
			glEnd();


			glBegin(GL_QUADS);
			glNormal3d(1, 0, 1);
			glVertex3d(3,-2,-0.5);
			glVertex3d(3,2,-0.5);
			glVertex3d(2,1,0.5);
			glVertex3d(2,-1,0.5);
			glEnd();


			glBegin(GL_QUADS);
			glNormal3d(0, 1, 1);
			glVertex3d(3,2,-0.5);
			glVertex3d(-3,2,-0.5);
			glVertex3d(-2,1,0.5);
			glVertex3d(2,1,0.5);
			glEnd();


			glBegin(GL_QUADS);
			glNormal3d(0, -1, 1);
			glVertex3d(-3,-2,-0.5);
			glVertex3d(3,-2,-0.5);
			glVertex3d(2,-1,0.5);
			glVertex3d(-2,-1,0.5);
			glEnd();
		
		glPopMatrix();

		//carrocaria
		glColor3d(1.f, 225/255.f, 79/255.f);

		GLfloat amb1[]={1.0f,0.65f,0.36f,1.0f};
		GLfloat diff1[]={0.87f,0.44f,0.25f,1.0f};
		GLfloat spec1[]={0.53f,0.38f,0.28f,1.0f};
		GLfloat shine1=0;
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec1);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine1);
		

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

			glBegin(GL_QUADS);
			glNormal3d(0, -1, 0);
			glVertex3d(-5,-2.5,-1);
			glVertex3d(5,-2.5,-1);
			glVertex3d(5,-2.5,1);
			glVertex3d(-5,-2.5,1);
			glEnd();

			glBegin(GL_QUADS);
			glNormal3d(0, 1, 0);
			glVertex3d(-5,2.5,-1);
			glVertex3d(5,2.5,-1);
			glVertex3d(5,2.5,1);
			glVertex3d(-5,2.5,1);
			glEnd();

			glBegin(GL_QUADS);
			glNormal3d(1, 0, 0);
			glVertex3d(5,-2.5,-1);
			glVertex3d(5,2.5,-1);
			glVertex3d(5,2.5,1);
			glVertex3d(5,-2.5,1);
			glEnd();

			glBegin(GL_QUADS);
			glNormal3d(-1, 0, 0);
			glVertex3d(-5,-2.5,-1);
			glVertex3d(-5,2.5,-1);
			glVertex3d(-5,2.5,1);
			glVertex3d(-5,-2.5,1);
			glEnd();

		glPopMatrix();

		//rodas
		glColor3d(81/255.f, 39/255.f, 38/255.f);

		GLfloat amb2[]={0.16f,0.08f,0.05f,1.0f};
		GLfloat diff2[]={0.39f,0.36f,0.37f,1.0f};
		GLfloat spec2[]={0.0f,0.0f,0.0f,1.0f};
		GLfloat shine2=0;
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb2);
		glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff2);
		glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec2);
		glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine2);

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