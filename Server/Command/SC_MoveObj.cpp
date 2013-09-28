/* 
 * File:   SC_MoveObj.cpp
 * Author: karsten
 * 
 * Created on 14. marts 2013, 21:08
 */

#include "SC_MoveObj.h"
#include "../World/SWorld.h"
SC_MoveObj::SC_MoveObj(uint32_t time, SObj* procesUnit, SPos pos, uint32_t btime, uint32_t etime):
SCommand(time,procesUnit){
	_pos = pos;
	
	_btime = btime;
	_etime = etime;
	_initTime = time;
	_active = false;
}



uint32_t SC_MoveObj::execute(){
	uint32_t speed = 10;
	//Obj is free to move or we are the active moving command
	if(_time > _procesUnit->_posUpdateTime || _active){
		
		//reserve the requested timeframe to execute move. We are now active
		_procesUnit->_posUpdateTime = _initTime + (_etime - _btime);
		_active = true;
		//calculate the remaning time 
		int32_t delta = _procesUnit->_posUpdateTime - _time;
		//if no more reserved time we are still not at target abort
		if( delta <= 0){
			cerr<<"SC_MoveObj::execute WARNING INCOMPLETE MOVE COMMAND NOT ENORTH TIME"<<endl;
			return 0;
		}
		
		//move remaning time or max 25 ms of time
		speed = speed * min(delta,25);
		//perform the move and check if we are at target pos
		if(Rangeobj(_pos, _procesUnit->getPos())*100 > speed){
			_procesUnit->getPos().d = (100 * Direction(_procesUnit->getPos(),this->_pos));
			_procesUnit->MovePos((VektorUnitX(_procesUnit->getPos().d/100) * speed) ,-((VektorUnitY(_procesUnit->getPos().d/100)* speed)));
			this->_time+=25;
			_procesUnit->addCommand(this);
			world->getObjs()[1]->setPos(_procesUnit->getPos());
			return 1;
		}else{
			_procesUnit->setPos(_pos);
			world->getObjs()[1]->setPos(_procesUnit->getPos());
			return 0;
		}
	}else{
		this->_time = _procesUnit->_posUpdateTime +1;
		_procesUnit->addCommand(this); 
		return 1;
	}
}


SC_MoveObj::~SC_MoveObj() {
}

