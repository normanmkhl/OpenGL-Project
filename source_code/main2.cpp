#include "Header.h"
#ifdef _main2_

#define GLEW_STATIC 

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint VBOID;

GLfloat vertices[] = { -0.5, -0.5, 0.0,
							1.0, 0.0, 0.0, //col p1
					   0.5, -0.5, 0.0,
							0.5, 1.0, 0.0, //col p2
					   0.0,  0.5, 0.0,
							0.0, 0.0, 1.0, //col p3	

						-0.7, -0.2, -0.8,
							0.0, 0.0, 1.0, //col p1
					   0.1, -0.3, 0.8,
							0.0, 0.0, 1.0, //col p2
					   -0.4,  0.7, -0.8,
							0.0, 0.0, 1.0 }; // col p3


/*GLfloat colors[] = {   1.0, 0.0, 0.0,
					   0.5, 1.0, 0.0,
					   0.0, 0.0, 1.0 };*/

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//start draw
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBOID);

			glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), 0);
			glColorPointer(3, GL_FLOAT, 24, (GLfloat*)0+3);
			
			glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

void initOpengl()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glewInit();

	//copy data to graphics card
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Learn Opengl");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	initOpengl();

	glutMainLoop();

	return 0;
}
#endif