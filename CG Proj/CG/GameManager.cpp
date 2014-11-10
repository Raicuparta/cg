#include "GameManager.h"

#include "Lights.h"

#define DEFAULT_CAR_SPEED 0.0008
#define DEFAULT_LOG_SPEED 0.0008

std::vector<StaticObject*> _static_objects;
std::vector<DynamicObject*> _dynamic_objects;
std::vector<TimberLog*> _timber_logs;
std::vector<Car*> _cars;
std::vector<Camera*> _cameras;

int _current_camera = 0;
float _timer = 0;
float _speed_timer = 0;
bool in_timberlog = false; //podia estar no frog
int _speed = 1;

Lights* _game_lights;


Frog* frog;
River* river;
Limit* limit;
RiverSide* river_side;

GameManager::GameManager() {
	_current_time = 0;
	_previous_time = 0;
}

GameManager::~GameManager() {

}

void GameManager::display() {
	glClearColor(31/255.f, 48/255.f, 63/255.f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	for (GameObject* obj : _static_objects)
	{
		obj->draw();
	}

	for (GameObject* obj : _dynamic_objects)
	{
		obj->draw();
	}

	frog->draw();
	glFlush();
}

void GameManager::reshape(GLsizei width, GLsizei height) {

	glViewport(0, 0, width, height);

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

		case '1':
			_current_camera = 0;
			break;
		case '2':
			_current_camera = 1;
			break;
		case '3':
			_current_camera = 2;
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
		case 'l':
			_game_lights->toggleLighting();
			break;
		case 'n':
			_game_lights->toggleAmbient();
			break;
		case 'c':
			_game_lights->toggleSpotlights();
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

	/*if (glIsEnabled(GL_LIGHT1)){
		gameLights->setDirectional();
		gameLights->setPointLights();
		gameLights->setLighting();
	}*/


	bool kill = false;

	//gerador de carros e troncos
	if (glutGet(GLUT_ELAPSED_TIME) > _timer + 3000/_speed) {
		_timer = glutGet(GLUT_ELAPSED_TIME);
		TimberLog* timber_log = new TimberLog();
		int y = rand() % 5 + 1;

		if (y % 2 == 0) {
			timber_log->setSpeed(DEFAULT_LOG_SPEED*_speed, 0, 0);
			timber_log->setPosition(-10, y, 0);
		} else {
			timber_log->setSpeed(-DEFAULT_LOG_SPEED*_speed, 0, 0);
			timber_log->setPosition(10, y, 0);
		}
		
		_dynamic_objects.push_back(timber_log);
		_timber_logs.push_back(timber_log);


		Car* car = new Car();
		y = rand() % 5 + 1;
		y *= -1;
		if (y % 2 == 0) {
			car->setSpeed(DEFAULT_CAR_SPEED*_speed, 0, 0);
			car->setPosition(-10, y, 1.1);
		} else {
			car->setSpeed(-DEFAULT_CAR_SPEED*_speed, 0, 0);
			car->setPosition(10, y, 1.1);
		}
		
		_dynamic_objects.push_back(car);
		_cars.push_back(car);

	}

	//aumentar a velocidade depois de um certo tempo
	if (glutGet(GLUT_ELAPSED_TIME) > _speed_timer + 20000) {
		_speed_timer = glutGet(GLUT_ELAPSED_TIME);
		_speed += 1;
	}

	for (int i = 0; i < (int)_dynamic_objects.size(); i++)
	{
		DynamicObject* obj = _dynamic_objects[i];
		obj->update(dt);
		if (abs(obj->getPosition()->getX()) > 10) {
			_dynamic_objects.erase(_dynamic_objects.begin() + i);
		}
	}

	if (frog->collidesWith(river)) {
		kill = true;
		for (TimberLog* obj : _timber_logs) {
			if (frog->collidesWith(obj)) {
				frog->setLog(obj);

				/*if (!in_timberlog) {
					frog->setSpeed(*frog->getSpeed() + *obj->getSpeed());
					in_timberlog = true;
				}*/
				kill = false;
				break;
			}
		}
	} else {
		frog->setLog(NULL);
	}


	for (Car* obj : _cars) {
		if (frog->collidesWith(obj)) {
			kill = true;
			break;
		}
	}

	if (kill) {
		reset();
		frog->kill();
	}


	if (frog->collidesWith(river_side)) {
		frog->kill();
		reset();
	}

	frog->update(dt);

	if (_current_camera == 2) {
		_cameras[_current_camera]->setPosition(frog->getPosition()->getX(), frog->getPosition()->getY() - 3, 5);
		_cameras[_current_camera]->setAt(frog->getPosition()->getX(), frog->getPosition()->getY() + 10, 0);
	}

	_cameras[_current_camera]->update();

}

void GameManager::init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Super Frogger 64");
	

	frog = new Frog();
	//_dynamic_objects.push_back(frog;)

	river = new River();
	_static_objects.push_back(river);

	river_side = new RiverSide();
	_static_objects.push_back(river_side);

	Road* road = new Road();
	_static_objects.push_back(road);

	RoadSide* road_side = new RoadSide();
	_static_objects.push_back(road_side);

	limit = new Limit();
	limit->setPosition(7.5, 0, 0);
	_static_objects.push_back(limit);

	OrthogonalCamera* ortho = new OrthogonalCamera(-7.5, 7.5, -7.5, 7.5, -100, 100);
	_cameras.push_back(ortho);

	PerspectiveCamera* persp1 = new PerspectiveCamera(90.0, 1.0, 20.0);
	_cameras.push_back(persp1);

	PerspectiveCamera* persp2 = new PerspectiveCamera(90.0, 1.0, 20.0);
	_cameras.push_back(persp2);

	_current_camera = 0;

	_game_lights = new Lights();


}

void GameManager::reset() {
	_speed = 1;
	_dynamic_objects.clear();
	_cars.clear();
	_timber_logs.clear();
}