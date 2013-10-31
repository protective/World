/* 
 * File:   SEffectTypeAddBuff.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:15
 */

#include "SEffectTypeAddBuff.h"
#include "../objects/Buffs/SBuffDot.h"
#include "../objects/Buffs/SBuffStat.h"
#include "../Command/SC_BuffProces.h"
SEffectTypeAddBuff::SEffectTypeAddBuff() {
	_tickTime = 0;
	_totalDamage = 0;
}

void SEffectTypeAddBuff::apply(uint32_t time,SPowerType* type, SCreature* caster, SCreature* target,map<PowerProjectileMods::Enum, int32_t> values, EResults::Enum result){
	//only target is legal to use as procesunit 
	
	//cerr<<"apply buff"<<endl;
	SBuff* buffToAdd = new SBuff(type,_tickEffects.size(),_tickTime);
	
	for(map<BuffVisualEffects::Enum,uint32_t>::iterator it = _visualEffects.begin(); it != _visualEffects.end(); it++){
		buffToAdd->getVIsualEffects()[it->first] = it->second;
	}
	
	if(_totalDamage > 0){
		SBuffDot* buffsEffects = new SBuffDot(buffToAdd,target,this);
		buffToAdd->getEffects().push_back(buffsEffects);
	}
	for (map<StatsMods::Enum, int32_t>::iterator it = _statsMods.begin(); it != _statsMods.end(); it++){
		SBuffStat* buffsEffects = new SBuffStat(buffToAdd,it->first, it->second);
		buffToAdd->getEffects().push_back(buffsEffects);
	}
	target->addBuff(buffToAdd);
	SC_BuffProces* command = new SC_BuffProces(time,target,caster,buffToAdd);
	target->addCommand(command);
	
	/*NETWORK ADD BUFF*/
	
	
}


SEffectTypeAddBuff::~SEffectTypeAddBuff() {
}

