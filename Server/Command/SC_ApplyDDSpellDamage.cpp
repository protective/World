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
SC_ApplyDDSpellDamage::SC_ApplyDDSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t min, uint32_t max, uint32_t hit, uint32_t crit, DamageTypes::Enum dmgType, SPowerTypeSpellDD* power):
SCommand(time,caster,target){
	_min = min;
	_max = max;
	_hit = hit;
	_crit = crit;
	_power = power;
	_dmgType = dmgType;
}

uint32_t SC_ApplyDDSpellDamage::execute(){

	uint32_t attackerL = _caster->getCreature()->getAttibute()[Attributes::Level];
	uint32_t defenderL = _target->getCreature()->getAttibute()[Attributes::Level];
	uint32_t roll = myrandom(0,10000);
	//MIN(99,5+(MAX(0,1+B5-C6))^2)
	
	//5+MIN(75,ROUNDDOWN(  ( (B3) / (C9*4) )*100))
	uint32_t resistPoints = 0;
	
	if(_dmgType == DamageTypes::Fire)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistFire];
	if(_dmgType == DamageTypes::Frost)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistFrost];
	if(_dmgType == DamageTypes::arcane)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistArcane];
	if(_dmgType == DamageTypes::nature)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistNature];
	if(_dmgType == DamageTypes::shadow)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistShadow];
	if(_dmgType == DamageTypes::force)
		resistPoints =_target->getCreature()->getAttibute()[Attributes::ResistForce];
	
	uint32_t miss = _hit + min((uint32_t)99, (uint32_t)(PBaseSpellMiss + (pow(max((uint32_t)0,(uint32_t)1+defenderL-attackerL),2))));
	miss *=100;

	uint32_t resist = min((uint32_t)99,(uint32_t)(PBaseSpellResist + min((float)75,(float)floor(resistPoints/(_power->getSpellLevel()*4)*100 ))));
	resist *=100;
	uint32_t crit = _crit;
	crit *= 100;
	uint32_t hit = 10000;
	
	
	uint32_t damage = myrandom(_min,_max);
	cerr<<"DD DAMAGE >>"<<damage<<endl;
	
	if (roll <= miss){
		_power->callBackResult(_time,_caster,_target,EResults::SMiss,damage);
	}else if (roll <= resist){
		_power->callBackResult(_time,_caster,_target,EResults::SResist,damage);	
	}else if (roll <= crit){
		damage *= PBaseSpellCritBonus;
		_target->addCommand(new SC_ApplyDamage(_time,_caster,_target,damage,_dmgType,_power));
		_power->callBackResult(_time,_caster,_target,EResults::SCrit,damage);	
	}else if (roll <= hit){
		_target->addCommand(new SC_ApplyDamage(_time,_caster,_target,damage,_dmgType,_power));
		_power->callBackResult(_time,_caster,_target,EResults::SHit,damage);	
	}

	return 0;
}

SC_ApplyDDSpellDamage::~SC_ApplyDDSpellDamage() {
}

