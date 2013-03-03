/* 
 * File:   SPowerType.cpp
 * Author: karsten
 * 
 * Created on 3. november 2012, 18:40
 */

#include "SPowerType.h"
#include "../objects/SCreature.h"
SPowerType::SPowerType(uint32_t id, uint32_t iconId) {
	_id = id;
	_iconId = iconId;
	_stats[PowerTypeStats::CD]  = 10000;
	_stats[PowerTypeStats::CastTime] = 10000;
	_stats[PowerTypeStats::EnergyCost] = 0;
	_stats[PowerTypeStats::projectileSpeed] = 100000;
	_stats[PowerTypeStats::SpellLevel] = 4;
	_stats[PowerTypeStats::ResistDmgType] = 2;
	_stats[PowerTypeStats::ManaCost] = 0;
	_stats[PowerTypeStats::BonusHit] = 0;
	_stats[PowerTypeStats::BonusCrit] = 0;
	
}

uint32_t SPowerType::activate(uint32_t time, SObj* caster, SObj* target, map<PowerProjectileMods::Enum,int32_t> values){
//TODO implement hit rolls here

	uint32_t attackerL =values[PowerProjectileMods::ALevel];
	uint32_t defenderL = target->getCreature()->getAttibute()[Attributes::Level];
	uint32_t roll = myrandom(0,10000);
	//MIN(99,5+(MAX(0,1+B5-C6))^2)
	
	//5+MIN(75,ROUNDDOWN(  ( (B3) / (C9*4) )*100))
	uint32_t resistPoints = 0;
	DamageTypes::Enum _dmgType = (DamageTypes::Enum)_stats[PowerTypeStats::ResistDmgType];
	if(_dmgType == DamageTypes::Fire)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistFire];
	if(_dmgType == DamageTypes::Frost)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistFrost];
	if(_dmgType == DamageTypes::arcane)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistArcane];
	if(_dmgType == DamageTypes::nature)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistNature];
	if(_dmgType == DamageTypes::shadow)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistShadow];
	if(_dmgType == DamageTypes::force)
		resistPoints =target->getCreature()->getAttibute()[Attributes::ResistForce];
	
	uint32_t miss = values[PowerProjectileMods::Shit] + min((uint32_t)99, (uint32_t)(PBaseSpellMiss + (pow(max((uint32_t)0,(uint32_t)1+defenderL-attackerL),2))));
	miss *=100;

	uint32_t resist = min((uint32_t)99,(uint32_t)(PBaseSpellResist + min((float)75,(float)floor(resistPoints/(_stats[PowerTypeStats::SpellLevel]*4)*100 ))));
	resist *=100;
	uint32_t crit = values[PowerProjectileMods::Scrit];
	crit *= 100;
	uint32_t hit = 10000;
	
	cerr<<"crit "<<crit<<endl;
	
	EResults::Enum hitResult;
	

	if (roll <= miss){
		hitResult = EResults::SMiss;
		//_power->callBackResult(_time,_caster,_target,EResults::SMiss,damage);
	}else if (roll <= resist){
		hitResult = EResults::SResist;
		//_power->callBackResult(_time,_caster,_target,EResults::SResist,damage);	
	}else if (roll <= crit){
		hitResult = EResults::SCrit;
		//damage *= PBaseSpellCritBonus;
		//_target->addCommand(new SC_ApplyDamage(_time,_caster,_target,damage,_dmgType,_power));
		//_power->callBackResult(_time,_caster,_target,EResults::SCrit,damage);	
	}else if (roll <= hit){
		hitResult = EResults::SHit;
		//_target->addCommand(new SC_ApplyDamage(_time,_caster,_target,damage,_dmgType,_power));
		//_power->callBackResult(_time,_caster,_target,EResults::SHit,damage);	
	}

	cerr<<"hitresult >>"<<hitResult<<endl;
	for (list<SEffectType*>::iterator it = _subComponents[hitResult].begin(); it != _subComponents[hitResult].end();it++){
		(*it)->apply(time,this,caster->getCreature(),target->getCreature(),values);
	}
}

SPowerType::~SPowerType() {
}

