/* 
 * File:   SPowerSpellDebuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:17
 */

#include "SPowerTypeSpellDebuff.h"
#include "../objects/SObj.h"
#include "../Command/SC_ApplyTickSpellDamage.h"
SPowerTypeSpellDebuff::SPowerTypeSpellDebuff() {
}

uint32_t SPowerTypeSpellDebuff::activate(uint32_t time, SObj* unit, SObj* target) {
	cerr<<"activate type"<<endl;
	SC_ApplyTickSpellDamage* c = new SC_ApplyTickSpellDamage(time, target, 10);
	target->addCommand(c);
}

SPowerTypeSpellDebuff::~SPowerTypeSpellDebuff() {
}

