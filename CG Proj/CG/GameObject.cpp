#include "GameObject.h"

GameObject::GameObject(std::vector<GameObject*>& game_objects)
{
	game_objects.push_back(this);
}


GameObject::~GameObject()
{
}

void GameObject::draw() {
}

