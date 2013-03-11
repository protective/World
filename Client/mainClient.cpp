/* 
 * File:   main.cpp
 * Author: karsten
 *
 * Created on 23. april 2011, 09:33
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_opengl.h"
#include "GL/gl.h"
#include <pthread.h>
#include <cstdlib>
#include "Grafic/Grafic.h"
#include "UI/UIMainFrame.h"
#include "CFunctions.h"
#include "objects/CCreature.h"


#define BPP 4
#define DEPTH 32
using namespace std;

void DrawScreen(SDL_Surface* screen)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

// draw quad in screen coodinates


	mainFrame->updateUI();
	mainFrame->draw();

	for (map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
		it->second->Draw();
	}

	SDL_GL_SwapBuffers();

}


 int main(int argc, char* argv[]){

	ifstream ifile("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");
	if (!ifile) {
		cerr<<"ERROR mscorefonts arial.ttf not found"<<endl;
		exit(1);
	}

	int argteam = 1;
	cerr<<"argc"<<argc<<endl;
	string argip = "127.0.0.1";
	if(argc >= 3){
		argteam = atoi(argv[1]);
			if(argteam == 0)
				argteam = 1;
		argip = string(argv[2]);
	}else if(argc >= 2){
		argteam = atoi(argv[1]);
			if(argteam == 0)
				argteam = 1;
	}
			
	cerr<<"argip"<<argip<<endl;


	for(int i = 0 ; i< 360; i++){
		double vector = (i*PI)/180;
		MySin[i] = sin(vector);
		MyCos[i] = cos(vector);
	}

	printbufferbool = true;
	//teamlist[1] = 1; //TODO ANOTHER BIG TODO TO FIX
	//teamlist[2] = 2;


	//loadGData();
	TTF_Init();
	atexit(TTF_Quit);
	  /*fronts
	  for (int i = 16; i < 31; i++ ){
	  	front1.insert(pair<uint32_t, TTF_Font* >(i, TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeSans.ttf",i)));

	  }
	   */

    SDL_Event event;

    int keypress = 0;
    int h=0;
	SDL_EnableUNICODE(1);
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
	printf("Unable to initialize SDL: %s\n", SDL_GetError());
	return 1;
	}
	
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); // *new*
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_Surface* screen = SDL_SetVideoMode(Basewidth, Basehight, 24, SDL_OPENGL | SDL_HWSURFACE); // *changed*
	if(!screen){
		cerr<<"ERROR init SDL >"<<SDL_GetError()<<endl;
		exit(1);
	}
	glViewport(0, 0, Basewidth, Basehight);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective( 0.45f,  (GLfloat)600/(GLfloat)300,  100.0f,  10000.0f);
	glOrtho(0, Basewidth-1, Basehight-1, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	
	textures[Textures::Icons1] = loadTexture(Textures::Icons1);
	
	
	Connect(argip,argteam, 42);
	uint32_t deltaTime = 0;
	uint32_t lastTime = 0;
	cerr<<"begin loop"<<endl;
    while(!keypress){
		//main loop

		deltaTime = SDL_GetTicks() - lastTime;
		while(deltaTime < 30){
			deltaTime = SDL_GetTicks() - lastTime;
			usleep(100);
		}


		//cerr<<deltaTime<<endl;
		lastTime = SDL_GetTicks();
		pthread_mutex_lock(&lockInput);

		DrawScreen(screen);
		pthread_mutex_unlock(&lockInput);
		playerObj->procesPlayerUnit(deltaTime);
		for(map<uint32_t,CObj*>::iterator it = playerObj->getObjs().begin(); it!= playerObj->getObjs().end(); it++ ){
			it->second->Proces(deltaTime);
			
		}
		//end main loop
		// begin input

		while(SDL_PollEvent(&event)){
			pthread_mutex_lock(&lockInput);
			
			switch (event.type){
				case SDL_QUIT:
					keypress = 1;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (mainFrame->click(event.button.x,event.button.y) == 0)
						playerObj->selectObject(event.button.x,event.button.y);
					break;
				case SDL_KEYDOWN:
					cerr<<"down "<<event.key.keysym.sym<<endl;
					keydown[event.key.keysym.sym] = true;
					
					break;
				case SDL_KEYUP:
					cerr<<"up "<<event.key.keysym.sym<<endl;
					keydown[event.key.keysym.sym] = false;
					
					break;
					//if (event.key.keysym.sym == SDLK_s)
					

			}
			pthread_mutex_unlock(&lockInput);
		}
	}
	Disconnect();
	SDL_Quit();
}