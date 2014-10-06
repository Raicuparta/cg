#pragma once
#include "Entity.h"
class Camera :
	public Entity
{
public:
	Camera(double near, double far);
	~Camera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();

};

