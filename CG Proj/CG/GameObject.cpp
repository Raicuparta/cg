#include "GameObject.h"

GameObject::GameObject() : Entity()
{
	_bmpWidth = -1;
    _bmpHeight = -1;
    _bmpSize = -1;
}


GameObject::~GameObject()
{
}

void GameObject::draw() {
}

bool GameObject::collidesWith(GameObject* obj) {
	return
		getXMax() > obj->getXMin() &&
		getXMin() < obj->getXMax() && 
		getYMax() > obj->getYMin() &&
		getYMin() < obj->getYMax();
}

double GameObject::getXMax() {
	return _position->getX() + _width/2;
}

double GameObject::getXMin() {
	return _position->getX() - _width/2;
}

double GameObject::getYMax() {
	return _position->getY() + _height/2;
}

double GameObject::getYMin() {
	return _position->getY() - _height/2;
}
