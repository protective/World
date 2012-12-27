/* 
 * File:   SC_FirePower.cpp
 * Author: karsten
 * 
 * Created on 26. december 2012, 21:08
 */

#include "SC_FirePower.h"
#include "SC_HitPower.h"
#include "../Powers/SPower.h"
#include "../objects/SCreature.h"
SC_FirePower::SC_FirePower(uint32_t time, SObj* caster, SObj* target, SPower* power):
SCommand(time,caster,target){
	_power = power;
}

uint32_t SC_FirePower::execute(){
//TODO projectile speed
	uint32_t range = 10000;
	
	uint32_t spellDelay = 0;
	if(_power->getPowerType()->getStats()[PowerTypeStats::projectileSpeed])
		spellDelay = range / _power->getPowerType()->getStats()[PowerTypeStats::projectileSpeed];
	
	
	//TODO check if more need to be send with projectile
	SC_HitPower* hit = new SC_HitPower(_time + spellDelay, _caster,_target,_power);
	hit->getValues()[PowerProjectileMods::Shit] = _caster->getCreature()->getAttibute()[Attributes::SpellHit] + _power->getPowerType()->getStats()[PowerTypeStats::BonusHit];
	hit->getValues()[PowerProjectileMods::Scrit] = _caster->getCreature()->getAttibute()[Attributes::SpellCrit] + _power->getPowerType()->getStats()[PowerTypeStats::BonusCrit];
	hit->getValues()[PowerProjectileMods::Spower] = _caster->getCreature()->getAttibute()[Attributes::SpellPower];
	hit->getValues()[PowerProjectileMods::SpowerBonus] = 0;
	hit->getValues()[PowerProjectileMods::SpowerBonusBuff] = 0;
	hit->getValues()[PowerProjectileMods::ALevel] = _caster->getCreature()->getAttibute()[Attributes::Level];
	_target->addCommand(hit);
	return 0;
}

SC_FirePower::~SC_FirePower() {
}

