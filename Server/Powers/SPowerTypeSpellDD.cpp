/* 
 * File:   SPowerTypeSpellDD.cpp
 * Author: karsten
 * 
 * Created on 7. november 2012, 20:57
 */

#include "SPowerTypeSpellDD.h"
#include "../Command/SC_ApplyDDSpellDamage.h"
#include "../objects/SObj.h"
#include "../objects/SCreature.h"
SPowerTypeSpellDD::SPowerTypeSpellDD(uint32_t min, uint32_t max,  DamageTypes::Enum dmgType) {
	_min = min;
	_max = max;
	_dmgType = dmgType;
}

uint32_t SPowerTypeSpellDD::activate(uint32_t time, SObj* caster, SObj* target){
	target->addCommand(new SC_ApplyDDSpellDamage(time,caster,target,_min,_max,caster->getCreature()->getAttibute()[Attributes::Hit],caster->getCreature()->getAttibute()[Attributes::Crit] ,_dmgType,this));
}

void SPowerTypeSpellDD::addResultPowerType(EResults::Enum event, SPowerType* power){
	_resultsList[event].push_back(power);
}

void SPowerTypeSpellDD::callBackResult(uint32_t time, SObj* caster, SObj* target,EResults::Enum result, uint32_t value){
	map<EResults::Enum, list<SPowerType*> >::iterator it = _resultsList.find(result);
	if(it != _resultsList.end()){	
		for(list<SPowerType*>::iterator it2 = it->second.begin(); it2 != it->second.end();it2++){
			(*it2)->activate(time,caster,target);
		}
	}
}




SPowerTypeSpellDD::~SPowerTypeSpellDD() {
}

