/* 
 * File:   SC_CastSTarget.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:39
 */

#include "SC_CastSTarget.h"
#include "../objects/SCreature.h"
SC_CastSTarget::SC_CastSTarget(uint32_t time, SObj* caster, SObj* target, SPower* power):
SCommand(time,caster,target){
	_power = power;
	_caster = caster;
	_target = target;
	
}


uint32_t SC_CastSTarget::execute(){
	if(!_target->getCreature()){
		cerr<<"WARNING SC_CastSTarget execute not creature"<<endl;
		return 0;
	}
	
	//TODO check ra nge
	SPower* p = _power; 
	if(p && _caster->readyCast()){
		if(_caster->getCreature())
			_caster->getCreature()->setCasting(_power);
		cerr<<"cast target"<<endl;
		p->activate(_time, _caster, _target);
	}else{
		//cerr<<"cast target Fail"<<endl;
	}
	return 0;
}



SC_CastSTarget::~SC_CastSTarget() {
}

