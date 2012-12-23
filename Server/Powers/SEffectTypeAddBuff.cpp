/* 
 * File:   SEffectTypeAddBuff.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:15
 */

#include "SEffectTypeAddBuff.h"
#include "../objects/Buffs/SBuffDot.h"
#include "../Command/SC_BuffProces.h"
SEffectTypeAddBuff::SEffectTypeAddBuff() {
	_tickTime = 0;
	_totalDamage = 0;
}

void SEffectTypeAddBuff::apply(uint32_t time, SCreature* caster, SCreature* target){
	cerr<<"apply buff"<<endl;
	SBuff* buffToAdd = new SBuff(_tickEffects.size(),_tickTime);
	
	SBuffDot* buffsEffects = new SBuffDot(target,this);
	
	buffToAdd->getEffects().push_back(buffsEffects);
	SC_BuffProces* command = new SC_BuffProces(time,caster,target,buffToAdd);
	target->addCommand(command);
}


SEffectTypeAddBuff::~SEffectTypeAddBuff() {
}

