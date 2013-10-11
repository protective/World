/* 
 * File:   GObj.cpp
 * Author: karsten
 * 
 * Created on 15. maj 2011, 21:23
 */

#include <stdint.h>

#include "CObj.h"

CObj::CObj(uint32_t id, uint32_t playerId, CPos pos) {
	this->_id = id;
	this->_team = teamlist[playerId];
	this->_playerId = playerId;
	this->_pos = pos;
	this->_actualPos = pos;

	

	
	this->_lastUpdate = 0 - 1;
	this->_procedTime = getTime();

}

CPos& CObj::getPos(){
	return this->_pos;
}

glm::vec3 CObj::getGraficPos(){
	return glm::vec3(_pos.x/1000,(_pos.y/1000),(_pos.z/1000));
}

void CObj::ResivePosUpdate(CPos& pos, uint32_t btime,  uint32_t etime){
	this->_actualPos.x = pos.x;
	this->_actualPos.y = pos.y;
	this->_actualPos.d = pos.d;
	this->_lastUpdate = btime;
	this->_procedTime = getTime();
	this->_etime = etime;
	
	float x, y = 0;
	
	uint32_t remaningTime = _etime > _lastUpdate ? _etime - _lastUpdate: 0;
	if (remaningTime){
		
		x = (_actualPos.x - _pos.x)/ (float)remaningTime; 
		y = (_actualPos.y - _pos.y)/ (float)remaningTime; 
	}
	_moveX = x;
	_moveY = y;
		
}



void CObj::Proces(uint32_t DTime){
	MovePos(_moveX*DTime,_moveY*DTime);
	this->_lastUpdate += DTime;
}



void CObj::MovePos(int32_t x, int32_t y){
	this->_pos.x+= x;
	this->_pos.y+= y;
}


CObj::~CObj() {
}

