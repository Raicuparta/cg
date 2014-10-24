#include "GameManager.h"
#define DELAY 10

GameManager* gm;

void keyPressed(unsigned char key, int x, int y) {
	gm->keyPressed(key, x, y);
}

void keyReleased(unsigned char key, int x, int y) {
	gm->keyReleased(key, x, y);
}

void onTimer(int value) {
	gm->onTimer(value);
	glutTimerFunc(DELAY, onTimer, 0);
}

void display() {
	gm->display();
}

void reshape(GLsizei width, GLsizei height) {
	gm->reshape(width, height);
}

int main(int argc, char ** argv) {

	glutInit(&argc, argv);

	gm = new GameManager();
	gm->init();

	glutKeyboardFunc(keyPressed);	//Funcao a ser chamada ao pressionar uma tecla 
	glutIgnoreKeyRepeat(1);		//Impedir que, ao pressionar uma tecla continuamente, seja chamada a funcao keyPressed repetidamente
	glutKeyboardUpFunc(keyReleased);	//Funcao a ser chamada ao libertar uma tecla
	glutTimerFunc(DELAY, onTimer, 0);	//Funcao a ser chamada a cada 20 milisegundos
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}