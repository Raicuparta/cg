#include "GameManager.h"

std::vector<GameObject*> _static_objects;
std::vector<DynamicObject*> _dynamic_objects;

Frog* frog = new Frog();

GameManager::GameManager() {
	_current_time = 0;
	_previous_time = 0;
}

GameManager::~GameManager() {

}

void GameManager::display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (GameObject* obj : _static_objects)
	{
		obj->draw();
	}

	for (GameObject* obj : _dynamic_objects)
	{
		obj->draw();
	}
	glFlush();
}

void GameManager::reshape(GLsizei width, GLsizei height) {
	// O ecra tem as dimensoes 15x15
	// Cada unidade corresponde a um 'bloco' do jogo
	// Por exemplo, a estrada tem uma largura de 5 unidades
	float xmin = -7.5, xmax = 7.5, ymin = -7.5, ymax = 7.5;

	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float)width / height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
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

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void GameManager::keyPressed(unsigned char key, int x, int y)
{
	switch(key) {
		case 'q': // Q - up
		case 't':
			frog->moveUp();
			break;
		case 'a':// A - down
		case 'g':
			frog->moveDown();
			break;
		case 'o': // O - left
		case 'f':
			frog->moveLeft();
			break;
		case 'p': // P - right
		case 'h':
			frog->moveRight();
			break;
		default: break;
	}
	glutPostRedisplay();
}

void GameManager::keyReleased(unsigned char key, int x, int y) {
	switch(key) {
		case 'q': // Q - up
		case 't':
			frog->moveDown();
			break;
		case 'a': // A - down
		case 'g':
			frog->moveUp();
			break;
		case 'o': // O - left
		case 'f':
			frog->moveRight();
			break;
		case 'p': // P - right
		case 'h':
			frog->moveLeft();
			break;
		default: break;
	}
}

void GameManager::onTimer(int value) {
	idle();
	glutPostRedisplay();

}

void GameManager::idle(){
    _current_time = glutGet(GLUT_ELAPSED_TIME);
    update(_current_time - _previous_time);
    _previous_time = _current_time;
    glutPostRedisplay();
    
}

void GameManager::update(double dt) {

	for (DynamicObject* obj : _dynamic_objects)
	{
		obj->update(dt);
	}

}

void GameManager::init() {

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1200, 650);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Super Frogger 64");

	River* river = new River();
	_static_objects.push_back(river);

	RiverSide* river_side = new RiverSide();
	_static_objects.push_back(river_side);

	Road* road = new Road();
	_static_objects.push_back(road);

	RoadSide* road_side = new RoadSide();
	_static_objects.push_back(road_side);

	TimberLog* _timber_log = new TimberLog();
	_dynamic_objects.push_back(_timber_log);

	frog = new Frog();
	_dynamic_objects.push_back(frog);

	Car* car1 = new Car();
	_dynamic_objects.push_back(car1);


}


