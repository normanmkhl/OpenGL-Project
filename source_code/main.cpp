#include "Header.h"
#include <GL/freeglut.h>
#include <stdio.h>

#ifdef _main_

float counter = 0.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glTranslatef(counter / 150.0, 0.0, -4.0);
	glRotatef(counter, 0.0, 1.0, 0.0);

	counter += 0.5;
	
	if (counter > 220)
		counter = -220.0;

	glBegin(GL_TRIANGLES);

		glColor3f(0.0, 1.0, 0.0);
		//Create a geometric point
		glVertex3f(-0.5,-0.5, 0.0);

		glColor3f(1.0, 0.0, 0.0);

		glVertex3f(0.5, -0.5, 0.0);

		glColor3f(0.0, 0.0, 1.0);

		glVertex3f(0, 0.5, 0.0);

	glEnd();
	
	//2nd triangle
	glLoadIdentity();
	glTranslatef(0.0,-0.5,-4.0);
	glRotatef(5, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);
	//Create a geometric point
	glVertex3f(-0.9, -0.1, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, -0.1, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.9, 0.0);

	glEnd();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float) w/(float) h,1.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}

void initOpenGL()
{
	glClearColor(0.8, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

int main(int argc, char **argv) 
{
	
	//start freeglut 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Learn Opengl");
	
	initOpenGL();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
#endif