#include "Turtle.h"

Turtle::Turtle() : DynamicObject() {
	_position = new Vector3(0, 0, 0);
}

Turtle::~Turtle()
{
}

void Turtle::draw() {
}
