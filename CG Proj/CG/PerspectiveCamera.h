#pragma once
#include "Camera.h"
class PerspectiveCamera : 
	public Camera
{

private:
	double _fovy;
	double _aspect;

public:
	PerspectiveCamera(double in_fovy, double in_aspect, double in_zNear, double in_zFar);
	~PerspectiveCamera(void);

	void reshape(GLsizei width, GLsizei height);
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};

