/* 
 * File:   SWorld.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 16:24
 */

#include "SWorld.h"

SWorld::SWorld() {
	_allDone = 0;
	_procesTime = SDL_GetTicks();
}

void SWorld::addGrid(SGrid* grid){
	this->grids[grid->_id] = grid;
}

map<uint32_t, SGrid*>& SWorld::getGrids(){
	return this->grids;
}
map<uint32_t, SObj*>& SWorld::getObjs(){
	return this->objInWorld;
}

void SWorld::proces(uint32_t thead_id){
	
	//wait until all here
	pthread_barrier_wait(&procesBar);
	//distribute the threads to objects
	SObjI it = this->objInWorld.begin();
	for (int i = 0; i < thead_id;i++){
		if(it == this->objInWorld.end())
			break;
		it++;
	}
	//check that we have an object to work on if len(obj) < noThreads
	if(it != this->objInWorld.end()){
		
		//set threads state to looking for work
		pthread_mutex_lock(&this->_lockAllDone);
			_allDone |= 1 << thead_id;
		pthread_mutex_unlock(&this->_lockAllDone);
	

		SObjI start = it;
		bool foundOne = true;
		bool breaknow = false;
		while(true){//begin looking for work
			if(start == it){
				pthread_mutex_lock(&this->_lockAllDone);
				if (foundOne == false)
					_allDone &= ~(1 << thead_id); //set zero no work found
				else
					_allDone |= 1 << thead_id;//set one
				if (_allDone == 0)//all threads have set there bit  all work is done
					breaknow = true; 
				pthread_mutex_unlock(&this->_lockAllDone);
				if(breaknow)
					break;
				foundOne = false;
			}

			if (it != this->objInWorld.end()){
				SCommand* command = it->second->procesFirstReadyCommand();//get the first command from object
				if (command){//DO The proces
					uint32_t ret = command->execute();
					if(ret==0) //Check if the command wants to be deleted
						delete command;
					foundOne = true; //recheck that no new command have been added
				}
				it->second->releaseProcesCommand(); //we are done procesing the command make ready the next

				it++;
			}else{
				it = this->objInWorld.begin();
			}
			

		}
	}
	pthread_barrier_wait(&procesBar); //object proces done begin proces grids

	if(thead_id == 0){
		
		for (SGridI it = this->grids.begin(); it != this->grids.end();it++){
			it->second->Proces(thead_id);
			//it->second->SendObjInfoToClients();
		}
	}
	pthread_barrier_wait(&procesBar);
}

SWorld::~SWorld() {
}

