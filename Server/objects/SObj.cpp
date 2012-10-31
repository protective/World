/* 
 * File:   GObj.cpp
 * Author: karsten
 * 
 * Created on 15. maj 2011, 21:23
 */

#include <stdint.h>

#include "SObj.h"
#include "../World/SWorld.h"
SObj::SObj(uint32_t id, SPos pos, uint8_t team, uint32_t playerId) {
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

uint32_t SObj::addCommand(SCommand* cmd){
	pthread_mutex_lock(&this->_lockCommands);
	_commands.push_back(cmd);
	pthread_mutex_unlock(&this->_lockCommands);
}


SObj::~SObj() {
}

