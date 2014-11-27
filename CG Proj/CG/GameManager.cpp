#include "GameManager.h"

#include "Lights.h"

#define DEFAULT_CAR_SPEED 0.0008
#define DEFAULT_LOG_SPEED 0.0008

std::vector<StaticObject*> _static_objects;
std::vector<DynamicObject*> _dynamic_objects;
std::vector<TimberLog*> _timber_logs;
std::vector<Car*> _cars;
std::vector<Camera*> _cameras;
std::vector<Frog *> _lives;

int _current_camera = 0;
float _timer = 0;
float _speed_timer = 0;
int _speed = 1;
int _livesN = 5;
bool _running = true;
bool _paused = false;
bool _game_over = false;


Lights* _game_lights;


Frog* frog;
River* river;
Limit* limit;
RiverSide* river_side;

GLuint _pause_texture;
GLuint _end_texture;

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

	if (!_game_over) {
		frog->draw();
	}
	overlay();
	glFlush();


}

void GameManager::reshape(GLsizei width, GLsizei height) {

	glViewport(0, 0, width, height);

}

void GameManager::keyPressed(unsigned char key, int x, int y)
{
	if (_running) {
		switch(key) {
		case 'q': // Q - up
		case 'k':
			frog->moveUp();
			frog->setAngle(0);
			break;
		case 'a':// A - down
		case ',':
			frog->moveDown();
			frog->setAngle(180);
			break;
		case 'o': // O - left
		case 'm':
			frog->moveLeft();
			frog->setAngle(90);
			break;
		case 'p': // P - right
		case '.':
			frog->moveRight();
			frog->setAngle(270);
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
	}
	
}

void GameManager::keyReleased(unsigned char key, int x, int y) {
	if (_running) {
		switch(key) {
		case 'q': // Q - up
		case 'k':
			frog->setSpeed(0, 0, 0);
			break;
		case 'a': // A - down
		case ',':
			frog->setSpeed(0, 0, 0);
			break;
		case 'o': // O - left
		case 'm':
			frog->setSpeed(0, 0, 0);
			break;
		case 'p': // P - right
		case '.':
			frog->setSpeed(0, 0, 0);
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
		case 'h':
			_game_lights->toggleFrogLight();
			break;

		default: break;
		}
	}

	if (key == 's') {
		if (!_game_over) {
			togglePause();
		}
	} else if (key == 'r') {
		if (_game_over) {
				reset();
		}
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
}

void GameManager::update(double dt) {

	if (_running) {

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
			if (_livesN == 1) {
				gameOver();
			}
			die();
			frog->kill();

		}


		frog->update(dt);

		if (_current_camera == 2) {
			_cameras[_current_camera]->setPosition(frog->getPosition()->getX(), frog->getPosition()->getY() - 3, 5);
			_cameras[_current_camera]->setAt(frog->getPosition()->getX(), frog->getPosition()->getY() + 10, 0);
		}

		_game_lights->updateFrogLight(frog->getPosition()->getX(), frog->getPosition()->getY(), frog->getPosition()->getZ(), frog->getAngle());

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

	float x = -6;
	for (int i = 0; i < _livesN; i++){
		_lives.push_back(new Frog());
		_lives[i]->setPosition(x, -7.f, 1.f);
		_lives[i]->faceCamera();
		x = x + 1;
	}

	/*for (int i = 0; i < _livesN; i++)  {
		_lives.push_back(new Frog());
	}*/

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

	_game_lights->toggleFrogLight();
	glEnable(GL_TEXTURE_2D);	int bmpWidth, bmpHeight, bmpSize;
	GLubyte * imageData;
	
	Draw::loadTexture("gameover.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);
	glGenTextures(1, &_end_texture);
	
    glBindTexture(GL_TEXTURE_2D, _end_texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpWidth, bmpHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imageData);	Draw::loadTexture("pause.bmp", &bmpWidth, &bmpHeight, &bmpSize, (unsigned char**)&imageData);
	glGenTextures(1, &_pause_texture);
	
    glBindTexture(GL_TEXTURE_2D, _pause_texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpWidth, bmpHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, imageData);	glDisable(GL_TEXTURE_2D);

}

void GameManager::gameOver() {
	_game_over = true;
	_running = false;
}

void GameManager::reset() {
	_livesN = 5;
	_running = true;
	_speed = 1;
	_dynamic_objects.clear();
	_cars.clear();
	_timber_logs.clear();
	_game_over = false;
	frog->setSpeed(0, 0, 0);
	frog->setAngle(0);
}

void GameManager::die() {
	_livesN--;
}

void GameManager::togglePause() {
	if (_running) {
		_paused = true;
		_running = false;
	} else {
		_paused = false;
		_running = true;
		frog->setSpeed(0, 0, 0);
	}

}

void GameManager::overlay(){

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	(*_cameras[0]).computeProjectionMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	(*_cameras[0]).computeVisualizationMatrix();

	glPushMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);

	glPushMatrix();

	//glColor3f(0.f, 0.f, 0.f);

	glColor3f(1, 1, 1);
	GLfloat um[]={1,1,1,1};
	GLfloat shine=0;

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,um);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,um);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,um);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);


	if (_game_over) {
		glPushMatrix();
		glTranslatef(-4, -4, 3);
		Draw::texturedPlane(1, 1, 8, 8, _end_texture);
		glPopMatrix();
	}
	if (_paused) {
		glPushMatrix();
		glTranslatef(-4, -4, 3);
		Draw::texturedPlane(1, 1, 8, 8, _pause_texture);
		glPopMatrix();
	}
	
	
	GLfloat zero[]={0,0,0,1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,zero);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,zero);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,zero);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
	glColor3f(0.f, 0.f, 0.f);

	glTranslatef(0, -7, 0.5);
	glScalef(15, 1 , 1);
	glutSolidCube(1);
	glPopMatrix();

	int i = 0;
	for (i; i < _livesN; i++){
		glPushMatrix();
		//glScalef(.4, .4, .4);
		_lives[i]->draw();
		glPopMatrix();
	}

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glPopMatrix();

	//glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glutSwapBuffers();
}