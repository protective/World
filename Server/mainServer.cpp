/* 
 * File:   main.cpp
 * Author: karsten
 *
 * Created on 23. april 2011, 09:32
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>

#include <math.h>

#include "SFunctions.h"
#include "World/SWorld.h"
#include "Client.h"

#include "SDatabase.h"
using namespace std;


	pthread_mutex_t  procesLock = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  procesConBegin = PTHREAD_COND_INITIALIZER;
	pthread_cond_t  procesConallReady = PTHREAD_COND_INITIALIZER;
	pthread_t procesThreads[NRTHREADS];
	int threadsReady;
void* procesworldThread(uint32_t id);

int main(int argc, char** argv) {
	for(int i = 0 ; i< 360; i++){
		double vector = (i*PI)/180;
		MySin[i] = sin(vector);
		MyCos[i] = cos(vector);
	}

	teamlist[1] = 1;
	teamlist[2] = 2;
	teamlist[3] = 3;
	teamlist[4] = 1;
	allteams.push_back(1);
	allteams.push_back(2);
	allteams.push_back(3);
	printbufferbool = true;
	
	SDL_Init(SDL_INIT_TIMER);

	pthread_t listenThread;
	pthread_create(&listenThread, NULL, (void*(*)(void*))thread_Listen, NULL);
	srand((unsigned)time(0));
        cerr<<"hello world"<<endl;
	//LOAD GAME DATA

	SDatabase data;
	
	//data.LoadAllItems();
	//cerr<<"done load data"<<endl;

	//WORLD
	
	
	SGrid* g = new SGrid(1);
	world->addGrid(g);
	SPos p(0,0,0);
	SObj* o = new SObj(1,p,0,0);
	g->addObj(o);
	for(uint32_t i = 0 ; i< 100; i++){
		//cerr<<SDL_GetTicks()+(i*100)<<endl;
		o->addCommand(new SCommand(SDL_GetTicks()+(i*1000)));
	}
	//data.LoadGame();
	//cerr<<"done load game"<<endl;

	SPos* temppos =  NULL;


	//temppos =  new SPos(-40000,-90000,0);
	//temppos->grid = world->getGrids()[1];
	//SAstoroidBelt* astob = new SAstoroidBelt(getFreeID(), *temppos);
	//world->getGrids()[1]->addObj(astob);
	//astob->AddRoid(astoroidTypes[8],220);
	//astob->AddRoid(astoroidTypes[8],220);
	cerr<<"done init"<<endl;
	//INIT GAME

	//tempU->ActivateAI();

	pthread_barrier_init(&procesBar,NULL,NRTHREADS);

	for (int i = 0 ; i< NRTHREADS; i++){
		pthread_create(&procesThreads[i], NULL, (void*(*)(void*))procesworldThread, (void*)i);
	}
	//GAME LOOP************************
	uint32_t timer;
	uint32_t fpstimer = 0;
	uint32_t fpscounter= 0;
	uint32_t fpswait = 1000/FRAMERATE; // 25 fps men korigere lidt for skeduleren
	pthread_mutex_lock(&lockClientList);
	while(true){

		timer = SDL_GetTicks();
		
			for (list<Client*>::iterator ci = clients.begin(); ci != clients.end(); ++ci){
				ReadBuffer((*ci));
				(*ci)->proces();
			}
				//world->prepairProces();

			
			pthread_mutex_lock(&procesLock);

			while(threadsReady != NRTHREADS){

				pthread_cond_wait(&procesConallReady, &procesLock);
			}

		pthread_mutex_unlock(&lockClientList);
		//************
		if ( SDL_GetTicks() > fpstimer +10000){
			fpstimer = SDL_GetTicks();
			cerr<<"fps "<<fpscounter/10<<endl;
			fpscounter = 0;
		}

		while (SDL_GetTicks() < timer+fpswait)
			usleep(100);
		//*************


			threadsReady = 0;

			world->setProcesTime(SDL_GetTicks());
			cerr<<"world time"<<SDL_GetTicks()<<endl;
			//cerr<<"done"<<endl;
			pthread_mutex_lock(&lockClientList);
			pthread_cond_broadcast(&procesConBegin);

			pthread_mutex_unlock(&procesLock);
		
		

		fpscounter +=1;


	}
	pthread_mutex_unlock(&lockClientList);

	//END GAME LOOP********************
	pthread_join(listenThread, NULL);
	cerr<<"SERVER EXIT"<<endl;
	return 0;
}

void* procesworldThread(uint32_t id){

	while (true){
		pthread_mutex_lock(&procesLock);
		threadsReady++;
		pthread_cond_signal(&procesConallReady);

		pthread_cond_wait(&procesConBegin, &procesLock);
		pthread_mutex_unlock(&procesLock);
		world->proces(id);
		

	}
}

