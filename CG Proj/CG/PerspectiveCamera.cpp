#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(double in_fovy, double in_zNear, double in_zFar) :
	Camera(in_zNear, in_zFar)
{
	_fovy = in_fovy;
	_position = new Vector3(0, -10, 5);
	_at = new Vector3(0, 0, 0);
}

PerspectiveCamera::~PerspectiveCamera(void)
{
}

void PerspectiveCamera::update() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);

	gluPerspective(_fovy, aspect, _near, _far);
	gluLookAt(
		_position->getX(), _position->getY(), _position->getZ(),
		_at->getX(), _at->getY(), _at->getZ(),
		0, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void PerspectiveCamera::computeProjectionMatrix() {

}

void PerspectiveCamera::computeVisualizationMatrix() {

}