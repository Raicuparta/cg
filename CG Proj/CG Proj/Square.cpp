#include <GL/glut.h>

class Square {
	int main(int argc, char ** argv) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(10, 10);
		glutCreateWindow("janela");
	}
};