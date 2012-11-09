/* 
 * File:   SPowerSpellDebuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:17
 */

#include "SPowerTypeSpellDebuff.h"
#include "../objects/SObj.h"
#include "../Command/SC_Debuff.h"
SPowerTypeSpellDebuff::SPowerTypeSpellDebuff() {
	ticksEffects t;
	t._delay = 500;
	t._effect = EffectTypes::FireDmg;
	
	t._value = 25;
	_ticks.push_back(t);
	_ticks.push_back(t);
	_ticks.push_back(t);
	t._value = 50;
	_ticks.push_back(t);
	_ticks.push_back(t);
	_ticks.push_back(t);
	t._value = 100;
	_ticks.push_back(t);
	_ticks.push_back(t);
	_ticks.push_back(t);
	_totalDamage = 2111;
}

uint32_t SPowerTypeSpellDebuff::activate(uint32_t time, SObj* caster, SObj* target) {
	cerr<<"activate type"<<endl;
	SC_Debuff* c = new SC_Debuff(time+_ticks.front()._delay,caster,target,this);
	target->addCommand(c);
}

SPowerTypeSpellDebuff::~SPowerTypeSpellDebuff() {
}

