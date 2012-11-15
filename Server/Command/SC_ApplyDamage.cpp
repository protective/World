/* 
 * File:   SC_ApplyDamage.cpp
 * Author: karsten
 * 
 * Created on 15. november 2012, 21:07
 */

#include "SC_ApplyDamage.h"

SC_ApplyDamage::SC_ApplyDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power):
SCommand(time,caster,target){
	_damage = damage;
	_dmgType = dmgType;
	_power = power;
	
}


uint32_t SC_ApplyDamage::execute(){

	_target->getCreature()->getAttibute()[Attributes::Hp] -= damage;
	
	return 0;
}


SC_ApplyDamage::~SC_ApplyDamage() {
}

