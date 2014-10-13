#include "GameManager.h"

std::vector<GameObject*> _game_objects;
Frog* frog = NULL;
Car* car1 = NULL;

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
	std::cout << "reshpeeeeeeeeeeeeee" << std::endl;
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

void keyPressed(unsigned char key, int x, int y)
{
	switch(key) {
		case 'q': std::cout << "'Q' pressed" << std::endl; // Q - up
			frog->moveUp();
			break;
		case 'a': std::cout << "'A' pressed" << std::endl; // A - down
			frog->moveDown();
			break;
		case 'o': std::cout << "'O' pressed" << std::endl; // O - left
			frog->moveLeft();
			break;
		case 'p': std::cout << "'P' pressed" << std::endl; // P - right
			frog->moveRight();
			break;
		default: break;
	}
}

void keyReleased(unsigned char key, int x, int y) {
	switch(key) {
		case 'q': std::cout << "'Q' released" << std::endl; // Q - up
			frog->moveDown();
			break;
		case 'a': std::cout << "'A' released" << std::endl; // A - down
			frog->moveUp();
			break;
		case 'o': std::cout << "'O' released" << std::endl; // O - left
			frog->moveRight();
			break;
		case 'p': std::cout << "'P' released" << std::endl; // P - right
			frog->moveLeft();
			break;
		default: break;
	}
}

void GameManager::onTimer(int value) {
	update();
	glutPostRedisplay();
}

void GameManager::idle() {

}

void GameManager::update() {

	frog->setPosition(frog->getPosition()->operator+(*frog->getSpeed()));
	
}

void GameManager::init() {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1200, 650);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Super Frogger 64");

	River* river = new River();
	_game_objects.push_back(river);

	RiverSide* river_side = new RiverSide();
	_game_objects.push_back(river_side);

	Road* road = new Road();
	_game_objects.push_back(road);

	RoadSide* road_side = new RoadSide();
	_game_objects.push_back(road_side);

	frog = new Frog();
	_game_objects.push_back(frog);

	car1 = new Car();
	_game_objects.push_back(car1);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
}


