#include <GL/glut.h>


void myDisplay(void) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

	glFlush();
}

void myReshape(GLsizei width, GLsizei height) {

	/*glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
	float ratio = (xmax - xmin) / (ymax - ymin);
	float aspect = (float) width / height; 
	glViewport( 0, 0, width, height);
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	if ( ratio < aspect )
	{
		float delta = ((ymax-ymin) * aspect - (xmax - xmin)) / 2;
		gluOrtho2D( xmin-delta, xmax+delta, ymin, ymax); 
	} else
	{ 
		float delta = ((xmax-xmin) / aspect - (ymax - ymin)) / 2;
		gluOrtho2D( xmin, xmax, ymin-delta, ymax+delta);
	}

}


void main(int argc, char ** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("janela");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop(); 

}
