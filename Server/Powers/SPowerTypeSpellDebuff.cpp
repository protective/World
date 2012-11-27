/* 
 * File:   SPowerSpellDebuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:17
 */

#include "SPowerTypeSpellDebuff.h"
#include "../objects/SObj.h"
#include "../Command/SC_Debuff.h"
#include "SPowerTypeDot.h"
SPowerTypeSpellDebuff::SPowerTypeSpellDebuff(uint32_t id):
SPowerSpellType(id){
	_subComponents.push_back(new SPowerTypeDot());
}

uint32_t SPowerTypeSpellDebuff::activate(uint32_t time, SObj* caster, SObj* target) {
	cerr<<"activate type speed debuff"<<endl;
	SC_Debuff* c = new SC_Debuff(time,caster,target,this);
	target->addCommand(c);
}

SPowerTypeSpellDebuff::~SPowerTypeSpellDebuff() {
}

