#include "Lights.h"

Lights::Lights(){

	//Ambiente
	GLfloat model_amb[] = { .2, .2, .2, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_amb);


	//Sol
	glEnable(GL_LIGHT0);
	GLfloat amb_direction[] = { 0, 0, 1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, amb_direction);

	GLfloat amb_ambient[] = { .3, .3, .3, 1 };
	GLfloat amb_diffuse[] = { .4, .4, .4, 1 };
	GLfloat amb_specular[] = { .2, .2, .2, 1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, amb_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, amb_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, amb_specular);

	//Spotlights
	
	GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };

	GLfloat spot_ambient[] = { 1, 1, 1, 1 };
	GLfloat spot_diffuse[] = { 1, 1, 1, 1 };
	GLfloat spot_specular[] = { 1, 1, 1, 1 };
	GLfloat lin_att = 0.3;
	GLfloat spot_exp = 20, spot_cutoff = 35; 

	GLfloat spot_positions[6][4] = {
		{ -6, 7, 10, 1 },
		{ -6, 0, 10, 1 },
		{ -6, -7, 10, 1 },
		{ 6, 7, 10, 1 },
		{ 6, 0, 10, 1 },
		{ 6, -7, 10, 1 }
	};
	
	for(int i = 0; i < 6; i++) {
		glLightf(GL_LIGHT1 + i, GL_SPOT_CUTOFF, spot_cutoff);
		glLightfv(GL_LIGHT1 + i, GL_SPOT_DIRECTION, spot_direction);
		glLightf(GL_LIGHT1 + i, GL_SPOT_EXPONENT, spot_exp);

		glLightfv(GL_LIGHT1 + i, GL_AMBIENT, spot_ambient);
		glLightfv(GL_LIGHT1 + i, GL_DIFFUSE, spot_diffuse);
		glLightfv(GL_LIGHT1 + i, GL_SPECULAR, spot_specular);
		glLightf(GL_LIGHT1 + i, GL_LINEAR_ATTENUATION, lin_att);

		glLightfv(GL_LIGHT1 + i, GL_POSITION, spot_positions[i]);
	}

		//frog light
		float directionFrogLight[] = {0, 1, 0};

		glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, spot_cutoff);
		glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, directionFrogLight);
		glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, spot_exp);

		glLightfv(GL_LIGHT7, GL_AMBIENT, spot_ambient);
		glLightfv(GL_LIGHT7, GL_DIFFUSE, spot_diffuse);
		glLightfv(GL_LIGHT7, GL_SPECULAR, spot_specular);
		glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, lin_att);

		float positionFrogLight[] = {0, 0, 0, 1};
		glLightfv(GL_LIGHT7, GL_POSITION, positionFrogLight);
}

void Lights::toggleSpotlights() {
	if(glIsEnabled(GL_LIGHT1)){
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		glDisable(GL_LIGHT6);
	} else {
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		glEnable(GL_LIGHT6);
	}
}

void Lights::toggleLighting() {
	if(glIsEnabled(GL_LIGHTING)) { 
		glDisable(GL_LIGHTING);
	} else {
		glEnable(GL_LIGHTING);
	}
}

void Lights::toggleAmbient() {
	if(glIsEnabled(GL_LIGHT0)) {
		glDisable(GL_LIGHT0);
	} else {
		glEnable(GL_LIGHT0);
	}
}

void Lights::updateFrogLight(float x, float y, float z, float angle) {

	float position[] = {x, y, z, 1};
	glLightfv(GL_LIGHT7, GL_POSITION, position);

	GLfloat direction[] = { 0.0, 0.0, 0.0 };

	if (angle == 0) {
		direction[1] = 1.0;
	} else if (angle == 90) {
		direction[0] = -1.0;
	} else if (angle == 180) {
		direction[1] = -1.0;
	} else if (angle == 270) {
		direction[0] = 1.0;
	}
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, direction);

}

void Lights::toggleFrogLight() {
	if(glIsEnabled(GL_LIGHT7)){
		glDisable(GL_LIGHT7);
	} else {
		glEnable(GL_LIGHT7);
	}
}