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
#include "../objects/Buffs/SBuffBase.h"
#include "../objects/Buffs/SBuffDot.h"
SC_Debuff::SC_Debuff(uint32_t time, SObj* caster, SObj* target, SPowerTypeSpellDebuff* power) 
:SCommand(time,caster,target){
	_power = power;
	_tickCount = _power->getTickCounts();

	
}

uint32_t SC_Debuff::execute(){
	if(_tickCount == _power->gettickEffects().size()){
		
		//_power->
		SBuffBase* sb = new SBuffDot();
		SBuff* buff = new SBuff();
		_target->getCreature()->addBuff(buff);
		_buffeffectlist.push_back(buff);
	}
	_tickCount--;
	
	for(list<SBuffBase*>::iterator it = _buffeffectlist.begin(); it != _buffeffectlist.end(); it++){
		(*it)->proces(_tickCount);
	}
	
	if(_tickCount > 0){
		_time += _power->getTickDelay();
		_target->addCommand(this);

		return 1;
	}
	return 0;
}

SC_Debuff::~SC_Debuff() {
}

