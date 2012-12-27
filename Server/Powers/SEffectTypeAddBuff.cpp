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

void SEffectTypeAddBuff::apply(uint32_t time,SPowerType* type, SCreature* caster, SCreature* target,map<PowerProjectileMods::Enum, int32_t> values){
	cerr<<"apply buff"<<endl;
	SBuff* buffToAdd = new SBuff(type,_tickEffects.size(),_tickTime);
	
	target->addBuff(buffToAdd);
	SBuffDot* buffsEffects = new SBuffDot(buffToAdd,target,this);
	
	buffToAdd->getEffects().push_back(buffsEffects);

	SC_BuffProces* command = new SC_BuffProces(time,caster,target,buffToAdd);
	target->addCommand(command);
}


SEffectTypeAddBuff::~SEffectTypeAddBuff() {
}

