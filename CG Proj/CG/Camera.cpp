#include "Camera.h"


Camera::Camera(double near, double far)
{
	_near = near;
	_far = far;
}


Camera::~Camera()
{
}

void Camera::reshape(GLsizei width, GLsizei height) {}
void Camera::update() {}
void Camera::computeProjectionMatrix() {}
void Camera::computeVisualizationMatrix() {}
