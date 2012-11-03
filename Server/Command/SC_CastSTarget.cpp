/* 
 * File:   SC_CastSTarget.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:39
 */

#include "SC_CastSTarget.h"
#include "../objects/SCreature.h"
SC_CastSTarget::SC_CastSTarget(uint32_t time, SObj* unit, SPower* power, SCreature* target):
SCommand(time,unit){
	_power = power;
	_target = target;
}


uint32_t SC_CastSTarget::execute(){
	if(!_unit->getCreature()){
		cerr<<"WARNING SC_CastSTarget execute not creature"<<endl;
		return 0;
	}
	cerr<<"cast target"<<endl;
	//TODO check ra nge
	SPower* p = _power; 
	if(p){
		p->activate(_time, _unit, _target);
	}
}



SC_CastSTarget::~SC_CastSTarget() {
}

