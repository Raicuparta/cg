#pragma once
#include "Camera.h"
#include "Vector3.h"
class PerspectiveCamera : 
	public Camera
{

private:
	double _fovy;

public:
	PerspectiveCamera(double in_fovy, double in_zNear, double in_zFar);
	~PerspectiveCamera(void);
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

