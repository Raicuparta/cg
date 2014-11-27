#include <GL/glut.h>

class Lights {

private:
	double l0_x, l0_y, l0_z;

public:
	Lights();
	~Lights();

	void toggleSpotlights();
	void toggleLighting();
	void toggleAmbient();
	void updateFrogLight(float x, float y, float z, float angle);
	void toggleFrogLight();

};