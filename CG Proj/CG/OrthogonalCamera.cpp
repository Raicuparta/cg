#include "OrthogonalCamera.h"


OrthogonalCamera::OrthogonalCamera(double in_left, double in_right, double in_bottom, double in_top, double in_near, double in_far) :
	Camera(in_near, in_far)
{
	_left = in_left;
	_right = in_right;
	_bottom = in_bottom;
	_top = in_top;
}


OrthogonalCamera::~OrthogonalCamera(void)
{
}

void OrthogonalCamera::update() {
		
}

void OrthogonalCamera::reshape(GLsizei width, GLsizei height) {


	float ratio = (_right - _left) / (_top - _bottom);
	float aspect = (float)width / height;
	glViewport(0, 0, width, height);

	if (ratio < aspect)
	{
		float delta = ((_top - _bottom) * aspect - (_right - _left)) / 2;
		gluOrtho2D(_left - delta, _right + delta, _bottom, _top);
	}
	else
	{
		float delta = ((_right - _left) / aspect - (_top - _bottom)) / 2;
		gluOrtho2D(_left, _right, _bottom - delta, _top + delta);
	}
}

void OrthogonalCamera::computeProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void OrthogonalCamera::computeVisualizationMatrix() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
