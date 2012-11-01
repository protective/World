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
	//cerr<<"hellow<<"<<thead_id<<endl;
	pthread_barrier_wait(&procesBar);
	
	//proces object internal //create shots!!!
	SObjI it = this->objInWorld.begin();
	for (int i = 0; i < thead_id;i++){
		if(it == this->objInWorld.end())
			break;
		it++;
	}
	if(it != this->objInWorld.end()){
		
		pthread_mutex_lock(&this->_lockAllDone);
			_allDone |= 1 << thead_id;
		pthread_mutex_unlock(&this->_lockAllDone);
	

		SObjI start = it;
		bool foundOne = true;
		bool breaknow = false;
		while(true){
			if(start == it){
				pthread_mutex_lock(&this->_lockAllDone);
				if (foundOne == false)
					_allDone &= ~(1 << thead_id); //set zero no work found
				else
					_allDone |= 1 << thead_id;//set one
				if (_allDone == 0)//all threads have set there bit done
					breaknow = true;
				pthread_mutex_unlock(&this->_lockAllDone);
				if(breaknow)
					break;
				foundOne = false;
			}

			if (it != this->objInWorld.end()){
				SCommand* command = it->second->procesFirstReadyCommand();
				if (command){//DO The proces
					uint32_t ret = command->execute();
					if(ret==0)
						delete command;
					foundOne = true;
					
				}
				it->second->releaseProcesCommand();

				it++;
			}else{
				it = this->objInWorld.begin();
			}
			

		}
	}
	pthread_barrier_wait(&procesBar);

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

