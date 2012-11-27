/* 
 * File:   SBuffDot.cpp
 * Author: karsten
 * 
 * Created on 18. november 2012, 21:38
 */

#include "SBuffDot.h"

SBuffDot::SBuffDot(SC_Debuff* command, SPowerTypeSpellDebuff* power) {
	_command = command;
	_power = power;
	for(list<ticksEffects>::iterator it = _power->gettickEffects().begin(); it != _power->gettickEffects().end();it++){
		_tick+= (float_t)it->_value/100;
	}
	_damageRemaing = _power->getTotalDamage();
}

uint32_t SBuffDot::proces(uint32_t tickCount) {
	
	list<ticksEffects>::iterator it =  _power->gettickEffects().begin();
	for(int i = 0; i < _power->gettickEffects().size() - tickCount;i++){
		it++;
	}
	uint32_t a = floor((float_t)_damageRemaining/_tick * ((float_t)it->_value/100));
	_damageRemaining -=a;
	_command->getTarget()->addCommand(new SC_ApplyTickSpellDamage(_command->getTime(),_command->getCaster(),_command->getTarget(),a,_power));
	_tick -= (float_t)it->_value/100;
	
}

SBuffDot::~SBuffDot() {
}

