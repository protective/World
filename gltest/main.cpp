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
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "SDL/SDL.h"
//#include "SDL/SDL_opengl.h"
//#include "GL/gl.h"
//#include "GL/glu.h"

#include "C_X_Loader.h"
#include "CMesh.h"
using namespace std;

/*
 * 
 */
int main(int argc, char *argv[])
{
	
	glm::quat amatureRot(-0.698709, 0.715406, 0.000000, 0.000000);
	glm::quat bone1Rot(0.000000,-0.000000,-0.707107, 0.707107);	
	glm::quat bone2Rot(-1.000000,-0.400000, 0.000000,-0.000000);

	cerr<<amatureRot.x<<endl;
	cerr<<amatureRot.y<<endl;
	cerr<<amatureRot.z<<endl;
	cerr<<amatureRot.w<<endl;		
	
	glm::quat temp = amatureRot* bone1Rot* bone2Rot;
	cerr<<temp.x<<endl;
	cerr<<temp.y<<endl;
	cerr<<temp.z<<endl;
	cerr<<temp.w<<endl;
	
	//cerr<<temp[3]<<endl;
	//glm::mat4 mat;

	
	
	//glm::mat4_cast(temp);
	//mat = glm::toMat4(temp);
	return 0;

	
	SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER);
	SDL_Event event;
	float theta = 0.0f;
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8 );
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32 );

	SDL_SetVideoMode(600, 300, 0, SDL_OPENGL | SDL_HWSURFACE );

	if (initiateShaders("test.vert","test.frag"))
		cerr<<"ERROR init shaders"<<endl;

	
	
	glViewport(0, 0, 600, 300);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 0.45f,  (GLfloat)600/(GLfloat)300,  100.0f,  10000.0f) ;
	glMatrixMode(GL_MODELVIEW);

	
	

	CMesh* mymesh =  Lload("amatureTest2.x");
	int done;
	cerr<<"DONE LOAD"<<endl;

	for(done = 0; !done;)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		//glLoadIdentity(); 
		//glRotatef(0.5, 0.0f, 1.0f, 0.0f);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		GLfloat lightpos[] = {0.0, 0.0, -100.0f, 1};
	    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
		
		glLoadIdentity();
		glTranslatef(0.0f,0.0f,-1800.0f);
		glRotatef(theta, 1.0f, 1.0f, 1.0f);
		
		mymesh->Render();	
		theta += .5f;
		SDL_GL_SwapBuffers();

	}
}

