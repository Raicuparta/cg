#include "StaticObject.h"

StaticObject::StaticObject(std::vector<GameObject*>& game_objects) : GameObject(game_objects) {
}

StaticObject::~StaticObject()
{
}

void StaticObject::draw() {
}
