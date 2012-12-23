/* 
 * File:   SPowerType.cpp
 * Author: karsten
 * 
 * Created on 3. november 2012, 18:40
 */

#include "SPowerType.h"
#include "../objects/SCreature.h"
SPowerType::SPowerType(uint32_t id) {
	_id = id;
}

uint32_t SPowerType::activate(uint32_t time, SObj* caster, SObj* target){
//TODO implement hit rolls here
	cerr<<"activate powertype"<<endl;
	EResults::Enum hitResult = EResults::SHit;
	
	for (list<SEffectType*>::iterator it = _subComponents[hitResult].begin(); it != _subComponents[hitResult].end();it++){
		cerr<<"apply powertype hit"<<endl;
		(*it)->apply(time,caster->getCreature(),target->getCreature());
	}
}

SPowerType::~SPowerType() {
}

