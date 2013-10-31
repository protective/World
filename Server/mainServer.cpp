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
#include "Powers/SPowerTypeSpellDD.h"
#include "Command/SC_CastSTarget.h"

#include <math.h>

#include "SFunctions.h"
#include "World/SWorld.h"
#include "Client.h"

#include "SDatabase.h"
#include "Command/SC_Debuff.h"
#include "objects/SCreature.h"
#include "Powers/SPowerTypeSpellDebuff.h"
#include "Powers/SPowerTypeLoader.h"
#include "Powers/SEffectTypeAddBuff.h"
#include "Powers/SEffectTypeDD.h"
using namespace std;


	pthread_mutex_t  procesLock = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  procesConBegin = PTHREAD_COND_INITIALIZER;
	pthread_cond_t  procesConallReady = PTHREAD_COND_INITIALIZER;
	pthread_t procesThreads[NRTHREADS];
	int threadsReady;
void* procesworldThread(uint32_t id);

int main(int argc, char** argv){
	for(int j = 0; j < 100;j++){
		printbufferSerial[(SerialType::Enum)j] = false;
	}
	for(int i = 0; i < argc;i++){
		if ((string)argv[i]=="-p"){
			i++;
			SPrintBuff = true;
			for(int j = 0; j < 100;j++){
				printbufferSerial[(SerialType::Enum)j] = true;
			}
			cerr<<"print "<<endl;
		}else if ((string)argv[i]=="-pB"){
			i++;
			SPrintBuff = true;
			printbufferSerial[SerialType::SerialBuff] = true;
			cerr<<"print buffer Buff"<<endl;
		}	
	}
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
	SPowerTypeLoader* pt =  new SPowerTypeLoader();
	
	
	//EFFECTS
	//SEffectTypeAddBuff* buff = new SEffectTypeAddBuff();
	//buff->setTotalDamage(100);
	//buff->setDamageType(DamageTypes::arcane);
	//buff->setTickTime(2000);
	//buff->gettickEffects().push_back(ticksEffects(25));
	//buff->gettickEffects().push_back(ticksEffects(50));
	//buff->gettickEffects().push_back(ticksEffects(100));
	//buff->getStatsMods()[StatsMods::SpellCrit] = 100;
	
	//SEffectTypeDD* DD = new SEffectTypeDD();
	//DD->setCritMod(150);
	//DD->setMinDamage(50);
	//DD->setMaxDamage(60);
	//DD->setDamageType(DamageTypes::Fire);
	
	
	//powerTypes
	//SPowerType* powert = new SPowerType(1,1);
	//powert->getSubComponents()[EResults::SHit].push_back(buff);
	//powert->getSubComponents()[EResults::SCrit].push_back(buff);
	//powert->getStats()[PowerTypeStats::CastTime] = 3000;
	//powert->getStats()[PowerTypeStats::ManaCost] = 0;
	
	
	//SPowerType* powert2 = new SPowerType(2,2);
	//powert2->getSubComponents()[EResults::SHit].push_back(DD);
	//powert2->getSubComponents()[EResults::SCrit].push_back(DD);	
	//powert2->getStats()[PowerTypeStats::CastTime] = 1000;
	//powert2->getStats()[PowerTypeStats::ManaCost] = 50;
	
	//WORLD
	SGrid* g = new SGrid(1);
	world->addGrid(g);
	
	data.LoadFromPostgres();
	
	
	//for(int i = 1 ; i< 20 ; i++){
	//	o->addCommand(new SC_CastSTarget(SDL_GetTicks()+(2000*i),o,o,o->getCreature()->getPower(1)));
	//}

	//data.LoadGame();
	//cerr<<"done load game"<<endl;

	SPos* temppos =  NULL;


	cerr<<"done init"<<endl;
	//INIT GAME

	//tempU->ActivateAI();

	pthread_barrier_init(&procesBar,NULL,NRTHREADS);

	for (uint64_t i = 0 ; i< NRTHREADS; i++){
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
			//cerr<<"fps "<<fpscounter/10<<endl;
			fpscounter = 0;
		}

		while (SDL_GetTicks() < timer+fpswait)
			usleep(100);
		//*************


			threadsReady = 0;
			
			pthread_mutex_lock(&lockServerTick);
			serverTick++;
			pthread_mutex_unlock(&lockServerTick);
			
			world->setProcesTime(SDL_GetTicks());
			//cerr<<"world time"<<SDL_GetTicks()<<endl;
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

