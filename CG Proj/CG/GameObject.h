#pragma once
#include "Entity.h"
#include "Draw.h"

class GameObject :
	public Entity
{
protected:
	double _width, _height;
	int _bmpWidth;
    int _bmpHeight;
    int _bmpSize;
	GLubyte * _imageData;
	GLuint _texture;

public:
	GameObject();
	~GameObject();
	virtual void draw();
	bool collidesWith(GameObject* obj);
	double getXMin();
	double getYMin();
	double getXMax();
	double getYMax();
};

