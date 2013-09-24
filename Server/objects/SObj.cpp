/* 
 * File:   GObj.cpp
 * Author: karsten
 * 
 * Created on 15. maj 2011, 21:23
 */

#include <stdint.h>

#include "SObj.h"
#include "../World/SWorld.h"
#include "../Command/SC_MoveObj.h"
SObj::SObj(uint32_t id, SPos pos, uint32_t team, uint32_t playerId) {
	this->_id = id;

	this->_team = team;
	this->_playerId = playerId;
	this->_pos = pos;

	this->_updateCounter = 0;
	this->_size = 120000;
	this->_commandAccessLocked = false;
	pthread_mutex_init(&this->_lockCommandAccess,NULL);
	pthread_mutex_init(&this->_lockCommands,NULL);
}

SPos& SObj::getPos(){
	return this->_pos;
}

SPos& SObj::getOldPos(){
	return this->_oldPos;
}

uint32_t SObj::getId(){
	return this->_id;
}

uint32_t SObj::setPos(SPos pos){
	uint32_t i = SDL_GetTicks();
	_pos = pos;
	_posUpdateTime = i;
	return i;
}

uint32_t SObj::reqMove(SPos pos){
	uint32_t delta = SDL_GetTicks() - _posUpdateTime;
	bool found = false;
	this->lockProcesCommand();
	for (list<SCommand*>::iterator it =  _commands.begin(); it!= _commands.end();it++){
		if((*it)->isMoveObj()){
			(*it)->isMoveObj()->setPos(pos);
			found = true;
			break;
		}
	}
	if(!found){
		this->addCommand(new SC_MoveObj(SDL_GetTicks(),this,pos));
	}
	
	this->releaseProcesCommand();
}

void SObj::MovePos(int32_t x, int32_t y){
	//cerr<<"x "<<x<<" y "<<y<<endl;
	this->_pos.x+= x;
	this->_pos.y+= y;
}


SCommand* SObj::procesFirstReadyCommand(){

	bool access = false;
	
	
	pthread_mutex_lock(&this->_lockCommandAccess);
	if(!_commandAccessLocked){
		access = true;
		_commandAccessLocked = true;
	}
	pthread_mutex_unlock(&this->_lockCommandAccess);
	if(access){
		SCommand* temp = NULL;	
		
		pthread_mutex_lock(&this->_lockCommands);
		
		if(_commands.size()){
			if(_commands.front()->getTime() <= world->getprocesTime()){
				temp = _commands.front();
				_commands.pop_front();
			}
		}
		pthread_mutex_unlock(&this->_lockCommands);
		
		return temp;
	}
	return NULL;
}


void SObj::releaseProcesCommand(){
	pthread_mutex_lock(&this->_lockCommandAccess);
	_commandAccessLocked = false;
	pthread_mutex_unlock(&this->_lockCommandAccess);
}

void SObj::lockProcesCommand(){
	pthread_mutex_lock(&this->_lockCommandAccess);
	_commandAccessLocked = true;
	pthread_mutex_unlock(&this->_lockCommandAccess);
}


uint32_t SObj::addCommand(SCommand* cmd){
	pthread_mutex_lock(&this->_lockCommands);
	list<SCommand*>::iterator it = _commands.begin();
	while (true){
		if(it != _commands.end()){
			if (cmd->getTime() <= (*it)->getTime()){
				_commands.insert(it,cmd);
				break;
			}else{
				it++;
			}
		}else{
			_commands.push_back(cmd);
			break;
		}
	}
	pthread_mutex_unlock(&this->_lockCommands);
}

uint32_t SObj::removeCommand(SCommand* cmd){
	pthread_mutex_lock(&this->_lockCommands);
	list<SCommand*>::iterator it = _commands.begin();
	while(it != _commands.end()){
		if(*it == cmd){
			_commands.remove(cmd);
			pthread_mutex_unlock(&this->_lockCommands);
			return 1;
		}
		it++;
	}
	pthread_mutex_unlock(&this->_lockCommands);
	return 0;
}


SObj::~SObj() {
}

