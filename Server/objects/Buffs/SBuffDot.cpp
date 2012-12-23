/* 
 * File:   SBuffDot.cpp
 * Author: karsten
 * 
 * Created on 18. november 2012, 21:38
 */

#include "SBuffDot.h"
#include "../../objects/SObj.h"
#include "../../Command/SC_ApplyTickSpellDamage.h"
#include "SBuff.h"
SBuffDot::SBuffDot(SCreature* owner, SEffectTypeAddBuff* power) {
	owner = owner;
	_power = power;
	for(list<ticksEffects>::iterator it = _power->gettickEffects().begin(); it != _power->gettickEffects().end();it++){
		_tick+= (float_t)it->_value/100;
	}
	_damageRemaining = _power->getTotalDamage();
	//_damageType = _power->
	
}

uint32_t SBuffDot::proces(uint32_t tickCount) {
	cerr<<"proces buffdot"<<endl;
	list<ticksEffects>::iterator it =  _power->gettickEffects().begin();
	for(int i = 0; i < _power->gettickEffects().size() - tickCount;i++){
		it++;
	}
	uint32_t a = floor((float_t)_damageRemaining/_tick * ((float_t)it->_value/100));
	_damageRemaining -=a;
	//_owner->addCommand(new SC_ApplyTickSpellDamage(_command->getTime(),_command->getCaster(),_command->getTarget(),a,_damageType, _power));
	cerr<<"add damage "<<a<<endl;
	_tick -= (float_t)it->_value/100;
	return 0;
}

SBuffDot::~SBuffDot() {
}

