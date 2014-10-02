#include <GL/glut.h>


void myDisplay(void) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// calcada
	glColor3f(0.4f, 0.1f, 0.7f);
	glPushMatrix();
		glTranslatef(0.f, -6.f, 0.f);
		glScalef(15.f, 1.f, 1.f);
		glutSolidCube(1);
		glTranslatef(0.f, 6.f, 0.f);
		glutSolidCube(1);
	glPopMatrix();

	// estrada
	glColor3f(0.1f, 0.1f, 0.1f);
		glPushMatrix();
		glTranslatef(0.f, -3.f, 0.f);
		glScalef(15.f, 5.f, 1.f);
		glutSolidCube(1);
	glPopMatrix();

	// estrada
	glColor3f(0.1f, 0.3f, 0.9f);
		glPushMatrix();
		glTranslatef(0.f, 3.f, 0.f);
		glScalef(15.f, 5.f, 1.f);
		glutSolidCube(1);
	glPopMatrix();

	// outro lado do rio
	glColor3f(0.3f, 0.7f, 0.1f);
		glPushMatrix();
		glTranslatef(0.f, 6.5f, 0.f);
		glScalef(15.f, 2.f, 1.f);
		glutSolidCube(1);
	glPopMatrix();

	glFlush();
}

void myReshape(GLsizei width, GLsizei height) {

	// O ecra tem as dimensoes 15x15
	// Cada unidade corresponde a um 'bloco' do jogo
	// Por exemplo, a estrada tem uma largura de 5 unidades
	float xmin = -7.5, xmax = 7.5, ymin = -7.5, ymax = 7.5;

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
