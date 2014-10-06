#include "DynamicObject.h"

DynamicObject::DynamicObject(std::vector<GameObject*>& game_objects) : GameObject(game_objects) {
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::draw() {
}

void DynamicObject::setSpeed(const Vector3& speed) {
	_speed = speed;
}

void DynamicObject::setSpeed(double x, double y, double z) {
	_speed.set(x, y, z);
}

Vector3 DynamicObject::getSpeed() {
	return _speed;
}

