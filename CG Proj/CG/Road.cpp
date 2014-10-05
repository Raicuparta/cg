#include "Road.h"

Road::Road(std::vector<GameObject*>& game_objects) : StaticObject(game_objects) {
}

Road::~Road() {

}

void Road::draw() {
	glColor3f(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	glTranslatef(0.f, -3.f, 0.f);
	glScalef(15.f, 5.f, 1.f);
	glutSolidCube(1);
	glPopMatrix();
}