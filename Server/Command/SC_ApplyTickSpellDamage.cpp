/* 
 * File:   SC_ApplyTickSpellDamage.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:49
 */

#include "SC_ApplyTickSpellDamage.h"
#include "SC_ApplyDamage.h"
#include "../objects/SCreature.h"
SC_ApplyTickSpellDamage::SC_ApplyTickSpellDamage(uint32_t time, SObj* procesUnit, SObj* caster, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power):
SCommand(time,procesUnit){
	_damage = damage;
	_power = power;
	_dmgType = dmgType;
	_caster = caster;
}

uint32_t SC_ApplyTickSpellDamage::execute(){
	
	
	_procesUnit->addCommand(new SC_ApplyDamage(_time,_procesUnit,_caster,_damage,_dmgType,_power));
	return 0;
}

SC_ApplyTickSpellDamage::~SC_ApplyTickSpellDamage() {
}

