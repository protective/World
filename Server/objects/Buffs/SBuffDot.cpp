/* 
 * File:   SBuffDot.cpp
 * Author: karsten
 * 
 * Created on 18. november 2012, 21:38
 */

#include "SBuffDot.h"
#include "../../objects/SObj.h"
#include "../../Command/SC_ApplyDamage.h"
#include "SBuff.h"
#include "../../Command/SC_BuffProces.h"
SBuffDot::SBuffDot(SBuff* buff, SCreature* owner, SEffectTypeAddBuff* power) :
SBuffBase(buff){
	owner = owner;
	_power = power;
	_tick = 0;
	for(list<ticksEffects>::iterator it = _power->gettickEffects().begin(); it != _power->gettickEffects().end();it++){
		_tick+= (float_t)it->_value/100;
	}
	_damageRemaining = _power->getTotalDamage();
	_damageType = power->getDamageType();
	//_damageType = _power->
	
}

uint32_t SBuffDot::proces(SC_BuffProces* cmd, uint32_t tickCount) {
	list<ticksEffects>::iterator it =  _power->gettickEffects().begin();
	for(int i = 0; i < _power->gettickEffects().size() - tickCount;i++){
		it++;
	}
	uint32_t a = floor((float_t)_damageRemaining/_tick * ((float_t)it->_value/100));
	_damageRemaining -=a;

	cmd->getTarget()->addCommand(new SC_ApplyDamage(cmd->getTime(),cmd->getCaster(),cmd->getTarget(),a,_damageType, _buff->getPowerType()));
	_tick -= (float_t)it->_value/100;
	return 0;
}

SBuffDot::~SBuffDot() {
}

