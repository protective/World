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

//#include "GL/gl.h"
#include <pthread.h>
#include <cstdlib>
#include "Grafic/Grafic.h"
#include "UI/UIMainFrame.h"
#include "CFunctions.h"
#include "objects/CCreature.h"
#include "Grafic/screenControler.h"
//#include "SDL/SDL_opengl.h"

#define BPP 4
#define DEPTH 32
using namespace std;




 int main(int argc, char* argv[]){
	for(int j = 0; j < 100;j++){
		printbufferSerial[(SerialType::Enum)j] = false;
	}
	//glutInit(&argc, argv);
	
	ifstream ifile("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");
	if (!ifile) {
		cerr<<"ERROR mscorefonts arial.ttf not found"<<endl;
		exit(1);
	}

	int argteam = 2;
	
	cerr<<"argc"<<argc<<endl;
	string argip = "127.0.0.1";
	
	for(int i = 0; i < argc;i++){
		if ((string)argv[i]=="-p"){
			i++;
			for(int j = 0; j < 100;j++){
				printbufferSerial[(SerialType::Enum)j] = true;
			}
			CPrintBuff = true;
			cerr<<"print "<<endl;
		}else if ((string)argv[i]=="-pB"){
			i++;
			CPrintBuff = true;
			printbufferSerial[SerialType::SerialBuff] = true;
			printbufferSerial[SerialType::SerialRMBuff] = true;
			cerr<<"print buffer Buff"<<endl;
			
		}else if((string)argv[i]=="-t"){
			i++;
			argteam = atoi(argv[i]);
			i++;
		}else if((string)argv[i]=="-ip"){
			i++;
			argip = string(argv[i]);
			i++;
		}
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

	
	
	cerr<<"create screen"<<endl;

	screenControler* screen = new screenControler();
	masterScreen = screen;

	screen->initScreen();
	cerr<<"done create screen"<<endl;
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
		screen->drawScreen();
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
					masterScreen->clickScreen(event.button.x,event.button.y);
					//if (mainFrame->click(event.button.x,event.button.y) == 0)
					//	playerObj->selectObject(event.button.x,event.button.y);
					break;
				case SDL_KEYDOWN:
					keydown[event.key.keysym.sym] = true;
					
					break;
				case SDL_KEYUP:
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