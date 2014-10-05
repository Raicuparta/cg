#pragma once
#include "DynamicObject.h"
class Car :
	public DynamicObject
{
public:
	Car(std::vector<GameObject*>& game_objects);
	~Car();
	void draw();
};

