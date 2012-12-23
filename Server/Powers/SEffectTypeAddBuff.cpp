/* 
 * File:   SEffectTypeAddBuff.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:15
 */

#include "SEffectTypeAddBuff.h"

SEffectTypeAddBuff::SEffectTypeAddBuff() {
}

void SEffectTypeAddBuff::apply(uint32_t time, SCreature* caster, SCreature* target){
	
	SBuffDot* buffDotToAdd = new SBuffDot(this);
	SC_BuffProces* command = new SC_BuffProces(time,caster,target,buffDotToAdd);
	target->addCommand(command);
}


SEffectTypeAddBuff::~SEffectTypeAddBuff() {
}

