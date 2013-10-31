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
SC_FirePower::SC_FirePower(uint32_t time, SObj* procesUnit, SObj* target, SPower* power):
SCommand(time,procesUnit){
	_power = power;
	_target = target;
}

uint32_t SC_FirePower::execute(){
//TODO projectile speed
	uint32_t range = 10000;
	
	uint32_t spellDelay = 0;
	if(_power->getPowerType()->getStats()[PowerTypeStats::projectileSpeed])
		spellDelay = range / _power->getPowerType()->getStats()[PowerTypeStats::projectileSpeed];
	
	
	int32_t a = _procesUnit->getCreature()->getAttibute()[Attributes::Mana];
	
	_procesUnit->getCreature()->SetAttributes(Attributes::Mana, a - _power->getPowerType()->getStats()[PowerTypeStats::ManaCost]);
	//TODO check if more need to be send with projectile
	SC_HitPower* hit = new SC_HitPower(_time + spellDelay,_target ,_procesUnit,_power);
	hit->getValues()[PowerProjectileMods::Shit] = _procesUnit->getCreature()->getAttibute()[Attributes::SpellHit] + _power->getPowerType()->getStats()[PowerTypeStats::BonusHit];
	hit->getValues()[PowerProjectileMods::Scrit] = _procesUnit->getCreature()->getAttibute()[Attributes::SpellCrit] + _power->getPowerType()->getStats()[PowerTypeStats::BonusCrit];
	hit->getValues()[PowerProjectileMods::Spower] = _procesUnit->getCreature()->getAttibute()[Attributes::SpellPower];
	hit->getValues()[PowerProjectileMods::SpowerBonus] = 100 +  _procesUnit->getCreature()->getAttibute()[Attributes::SpellPowerBonus];
	hit->getValues()[PowerProjectileMods::SpowerBonusBuff] = 100 + _procesUnit->getCreature()->getAttibute()[Attributes::SpellPowerBonusBuff];
	hit->getValues()[PowerProjectileMods::ALevel] = _procesUnit->getCreature()->getAttibute()[Attributes::Level];
	
	char message[sizeof(SerialCast)];
	memset(message,0,sizeof(SerialCast));
	SerialCast* data = (SerialCast*)(message);
	data->_type = SerialType::SerialCast;
	data->_size = sizeof(SerialCast);
	data->_time = _time;
	data->_unitId = this->_procesUnit->getId();
	data->_powerid = this->_power->getId();
	data->_targetId = _target->getId();
	for(list<Client*>::iterator it = this->_procesUnit->getSubscribers()[0].begin(); it != this->_procesUnit->getSubscribers()[0].end(); it++){
		sendtoC(*it,message,sizeof(SerialCast));
	}
	
	_target->addCommand(hit);
	
	if (_procesUnit->getCreature())
		_procesUnit->getCreature()->setCasting(NULL);

	return 0;
}

SC_FirePower::~SC_FirePower() {
}

