#include "DynamicObject.h"

DynamicObject::DynamicObject() : GameObject() {
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

Vector3* DynamicObject::getSpeed() {
	return &_speed;
}

void DynamicObject::update(double dt) {
	//setPosition(getPosition()->operator+(*getSpeed()));
	Vector3 speed = *getSpeed();
	Vector3 position = *getPosition();
	setPosition(speed*dt + position);
}