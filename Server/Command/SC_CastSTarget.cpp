/* 
 * File:   SC_CastSTarget.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:39
 */

#include "SC_CastSTarget.h"
#include "../objects/SCreature.h"
SC_CastSTarget::SC_CastSTarget(uint32_t time, SObj* procesUnit, SObj* target, SPower* power):
SCommand(time,procesUnit){
	_power = power;
	_target = target;
	
}


uint32_t SC_CastSTarget::execute(){
	if(!_target->getCreature()){
		cerr<<"WARNING SC_CastSTarget execute not creature"<<endl;
		return 0;
	}
	
	//TODO check range
	SPower* p = _power; 
	if(p && _procesUnit->readyCast()){
		if(p->getPowerType()->getStats()[PowerTypeStats::ManaCost] <= _procesUnit->getCreature()->getAttibute()[Attributes::Mana]){
			if(_procesUnit->getCreature())
				_procesUnit->getCreature()->setCasting(_power);
			p->activate(_time, _procesUnit, _target);
		}
	}else{
		//cerr<<"cast target Fail"<<endl;
	}
	return 0;
}



SC_CastSTarget::~SC_CastSTarget() {
}

