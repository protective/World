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


#include "CFunctions.h"

#define Basewidth 1366
#define Basehight 768

#define BPP 4
#define DEPTH 32
using namespace std;

void DrawScreen(SDL_Surface* screen)
{
	glClear(GL_COLOR_BUFFER_BIT);



	//mainFrame->Draw();

	//for (CobjI it = playerObj->getObjs().begin(); it != playerObj->getObjs().end();it++){
	//	it->second->Draw();
	//}



 

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

	SDL_Surface* screen = SDL_SetVideoMode(Basewidth, Basehight, 24, SDL_OPENGL); // *changed*
	if(!screen){
		cerr<<"ERROR init SDL >"<<SDL_GetError()<<endl;
		exit(1);
	}
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND); //Enable blending.
	glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.5);
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glViewport( 0, 0, Basewidth, Basehight );
	glClear( GL_COLOR_BUFFER_BIT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0.0f, Basewidth, Basehight, 0.0f, -1.0f, 1.0f);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	
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
		
		//end main loop
		// begin input

		while(SDL_PollEvent(&event)){
			pthread_mutex_lock(&lockInput);
			
			switch (event.type){
				case SDL_QUIT:
					keypress = 1;
					break;
				
					//if (event.key.keysym.sym == SDLK_s)
					

			}
			pthread_mutex_unlock(&lockInput);
		}
	}
	Disconnect();
	SDL_Quit();
}