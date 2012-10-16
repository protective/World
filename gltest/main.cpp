/* 
 * File:   main.cpp
 * Author: karsten
 *
 * Created on 26. april 2011, 21:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "C_X_Loader.h"
using namespace std;

/*
 * 
 */
int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER);
	SDL_Event event;
	float theta = 0.0f;
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8 );
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32 );

	SDL_SetVideoMode(600, 300, 0, SDL_OPENGL | SDL_HWSURFACE );

	glViewport(0, 0, 600, 300);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 0.45f,  (GLfloat)600/(GLfloat)300,  1.0f,  1000.0f) ;
	glMatrixMode(GL_MODELVIEW);


	Lload("amatureTest2.x");
	int done;
	for(done = 0; !done;)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		//glLoadIdentity(); 
		//glRotatef(0.5, 0.0f, 1.0f, 0.0f);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		glTranslatef(0.0f,0.0f,-400.0f);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3i(1, 0,0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3i(0, -1, 0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3i(0, 1, 0);
		glEnd();

		theta += .5f;
		SDL_GL_SwapBuffers();

	}
}

