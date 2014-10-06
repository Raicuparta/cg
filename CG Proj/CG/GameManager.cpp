#include "GameManager.h"

#include "Vector3.h"

std::vector<GameObject*> _game_objects;

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (GameObject* obj : _game_objects)
	{
		obj->draw();
	}

	glFlush();
}

void reshape(GLsizei width, GLsizei height) {
	// O ecra tem as dimensoes 15x15
	// Cada unidade corresponde a um 'bloco' do jogo
	// Por exemplo, a estrada tem uma largura de 5 unidades
	float xmin = -7.5, xmax = 7.5, ymin = -7.5, ymax = 7.5;

	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)width / height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (ratio < aspect)
	{
		float delta = ((ymax - ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D(xmin - delta, xmax + delta, ymin, ymax);
	}
	else
	{
		float delta = ((xmax - xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D(xmin, xmax, ymin - delta, ymax + delta);
	}
}

void keyPressed() {

}

void onTimer() {

}

void idle() {

}

void update() {

}

void init() {

}

int main(int argc, char ** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1200, 650);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("janela");

	River* river = new River(_game_objects);
	RiverSide* river_side = new RiverSide(_game_objects);
	Road* road = new Road(_game_objects);
	RoadSide* road_side = new RoadSide(_game_objects);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;

}

