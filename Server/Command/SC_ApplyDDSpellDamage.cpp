/* 
 * File:   SC_ApplyDDSpellDamage.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:49
 */

#include "SC_ApplyDDSpellDamage.h"

SC_ApplyDDSpellDamage::SC_ApplyDDSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, SPowerTypeSpellDD* power):
SCommand(time,caster,target){
	_damage = damage;
	_power = power;
}

uint32_t SC_ApplyDDSpellDamage::execute(){
	cerr<<"DD DAMAGE >>"<<_damage<<endl;
	if(_power)
		_power->callBackResult(_time,_caster,_target,EResults::SCrit,_damage);
	return 0;
}

SC_ApplyDDSpellDamage::~SC_ApplyDDSpellDamage() {
}

