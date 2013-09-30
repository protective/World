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

void CObj::ResivePosUpdate(CPos& pos, uint32_t btime,  uint32_t etime){
	this->_actualPos.x = pos.x;
	this->_actualPos.y = pos.y;
	this->_actualPos.d = pos.d;
	cerr<<"RESIVED BTIME "<<btime<<" ETIME "<<etime<<endl;
	this->_lastUpdate = btime;
	this->_procedTime = getTime();
	this->_etime = etime;
	
	float x, y = 0;
	
	uint32_t remaningTime = _etime > _lastUpdate ? _etime - _lastUpdate: 0;

	cerr<<"Time " <<remaningTime<<endl;
	if (remaningTime){
		cerr<<"actual x "<<_actualPos.x<<" y "<<_actualPos.y<<endl;
		cerr<<"pos x "<<_pos.x<<" y "<<_pos.y<<endl;
		
		x = (_actualPos.x - _pos.x)/ (float)remaningTime; 
		y = (_actualPos.y - _pos.y)/ (float)remaningTime; 
	}
	cerr<<"RECIVED mx "<<x<<" my "<<y<<endl;
	_moveX = x;
	_moveY = y;
		
}



void CObj::Proces(uint32_t DTime){
	
	float speed = 0;
	uint32_t remaningTime = _etime > _lastUpdate ? _etime - _lastUpdate: 0;
	
	cerr<<"move x "<<_moveX<<" y "<<_moveY<<endl;
	MovePos(_moveX*DTime,_moveY*DTime);
	
	if (remaningTime){
		uint32_t distance = Rangeobj(_actualPos,_pos);

		//cerr<<"REM >"<<remaningTime<<endl;
		//cerr<<"Dis >"<<distance<<endl;
		
		speed = ((float)distance / remaningTime)*1000;
		//cerr<<"Speed "<<speed<<endl;
		uint32_t d =  Direction(_pos,_actualPos);
		//this->MovePos(VektorUnitX(d) * speed ,-(VektorUnitY(d) * speed));

			
		//while(this->_procedTime<= getTime()){
		//	this->_procedTime += 1000/25;

		//}

		this->_lastUpdate += DTime;
	}
}



void CObj::MovePos(int32_t x, int32_t y){
	this->_pos.x+= x;
	this->_pos.y+= y;
}


CObj::~CObj() {
}

