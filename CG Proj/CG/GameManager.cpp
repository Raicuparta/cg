#include "GameManager.h"

std::vector<GameObject*> _static_objects;
std::vector<DynamicObject*> _dynamic_objects;
std::vector<Camera*> _cameras;
int _current_camera = 0;

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

	glViewport(0, 0, width, height);

	/*_cameras[_current_camera]->computeProjectionMatrix();

	_cameras[_current_camera]->reshape(width, height);

	_cameras[_current_camera]->computeVisualizationMatrix();*/

	


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
    //glutPostRedisplay();
    
}

void GameManager::update(double dt) {

	for (DynamicObject* obj : _dynamic_objects)
	{
		obj->update(dt);
	}

	_cameras[_current_camera]->update();

		glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(100, 1, -5, 5);
	//gluOrtho2D(-7.5, 7.5, -7.5, 7.5);
	gluLookAt(frog->getPosition()->getX(), frog->getPosition()->getY() - 8, 5, frog->getPosition()->getX(), 7.5, 2, 0, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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

	Car* car2 = new Car();
	_dynamic_objects.push_back(car2);

	OrthogonalCamera* ortho = new OrthogonalCamera(-7.5, 7.5, -7.5, 7.5, -5, 5);
	_cameras.push_back(ortho);
}


