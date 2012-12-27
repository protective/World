/* 
 * File:   SC_ApplyDDSpellDamage.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:49
 */

#include <cmath>

#include "SC_ApplyDDSpellDamage.h"
#include "../objects/SCreature.h"
#include "SC_ApplyDamage.h"
SC_ApplyDDSpellDamage::SC_ApplyDDSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t min, uint32_t max, uint32_t hit, uint32_t crit, DamageTypes::Enum dmgType, SPowerType* power):
SCommand(time,caster,target){
	_min = min;
	_max = max;
	_hit = hit;
	_crit = crit;
	_power = power;
	_dmgType = dmgType;
}

uint32_t SC_ApplyDDSpellDamage::execute(){


	return 0;
}

SC_ApplyDDSpellDamage::~SC_ApplyDDSpellDamage() {
}

