#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double in_fovy, double in_aspect, double in_zNear, double in_zFar) :
	Camera(in_zNear, in_zFar)
{
	_fovy = in_fovy;
	_aspect = in_aspect;
}


PerspectiveCamera::~PerspectiveCamera(void)
{
}



void PerspectiveCamera::update() {

}

void PerspectiveCamera::reshape(GLsizei width, GLsizei height) {


	gluPerspective(_fovy, _aspect, _near, _far);
	
	/*float ratio = (_right - _left) / (_top - _bottom);
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
	}*/
}

void PerspectiveCamera::computeProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void PerspectiveCamera::computeVisualizationMatrix() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
