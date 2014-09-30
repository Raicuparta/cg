#include <GL/glut.h>


void myDisplay(void) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	/*
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
	*/

	/*glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 2.0f);
	
	glPushMatrix();
	glTranslatef(2.1f, 0.0f, 0.0f);
	
	glPushMatrix();
	glScalef(1.2f, 0.2f, 0.2f);
	glutSolidCube(1);
	glPopMatrix();

	glTranslatef(0.5f, 0.1f, 0.0f);
	glScalef(0.1f, 0.1f, 0.1f);
	glutSolidCube(1);
	glPopMatrix;
	
	glScalef(1.5f, 1.5f, 1.5f);
	glutSolidCube(1);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(2.1f, 0.0f, 0.0f); 
	glScalef(0.2f, 0.4f, 0.4f);

	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.0f);
	glScalef(0.4f, 0.4f, 0.4f);
	glutSolidCube(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.f, 4.f, 0.0f);
	glColor3f(0.1f, 0.5f, 0.9f);
	glScalef(40.f, 2.0f, 0.2f);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glFlush();
}

void myReshape(GLsizei width, GLsizei height) {

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
	glutInitWindowSize(1200, 650);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("janela");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop(); 

}
