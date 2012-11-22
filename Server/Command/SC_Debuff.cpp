/* 
 * File:   SC_Debuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:36
 */

#include <cmath>

#include "SC_Debuff.h"
#include "../objects/SObj.h"
#include "SC_ApplyTickSpellDamage.h"
SC_Debuff::SC_Debuff(uint32_t time, SObj* caster, SObj* target, SPowerTypeSpellDebuff* power) 
:SCommand(time,caster,target){
	_power = power;
	_tick = 0;
	_tickCount = _power->gettickEffects().size();
	for(list<ticksEffects>::iterator it = _power->gettickEffects().begin(); it != _power->gettickEffects().end();it++){
		_tick+= (float_t)it->_value/100;
	}
	_damageRemaing = _power->getTotalDamage();
}

uint32_t SC_Debuff::execute(){
	if(_tickCount == _tick)
		_buffIndex = _target->getCreature()->addBuff(new SBuffDot());
	list<ticksEffects>::iterator it =  _power->gettickEffects().begin();
	for(int i = 0; i < _power->gettickEffects().size() - _tickCount;i++){
		it++;
	}
	
	cerr<<"debuff"<<endl;
	//cerr<<(_tick * ((float_t)it->_value/100))<<endl;
	uint32_t a = floor((float_t)_damageRemaing/_tick * ((float_t)it->_value/100));
	_damageRemaing -=a;
	_target->addCommand(new SC_ApplyTickSpellDamage(_time,_caster,_target,a,_power));
	_tick -= (float_t)it->_value/100;
	_tickCount--;
	if(_tick > 0){
		_time += it->_delay;
		_target->addCommand(this);

		return 1;
	}
	return 0;
}

SC_Debuff::~SC_Debuff() {
}

