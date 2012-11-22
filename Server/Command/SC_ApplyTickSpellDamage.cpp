/* 
 * File:   SC_ApplyTickSpellDamage.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:49
 */

#include "SC_ApplyTickSpellDamage.h"
#include "SC_ApplyDamage.h"
#include "../objects/SCreature.h"
SC_ApplyTickSpellDamage::SC_ApplyTickSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, DamageTypes::Enum dmgType, SPowerTypeSpellDD* power):
SCommand(time,caster,target){
	_damage = damage;
	_power = power;
	_dmgType = dmgType;
}

uint32_t SC_ApplyTickSpellDamage::execute(){
	
	
	_target->addCommand(new SC_ApplyDamage(_time,_caster,_target,_damage,_dmgType,_power));
	return 0;
}

SC_ApplyTickSpellDamage::~SC_ApplyTickSpellDamage() {
}

