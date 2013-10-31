/* 
 * File:   SEffectTypeDD.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:15
 */

#include "SEffectTypeDD.h"
#include "SPowerType.h"
#include "../Command/SC_ApplyDamage.h"
#include "../objects/SCreature.h"
SEffectTypeDD::SEffectTypeDD() {
}

void SEffectTypeDD::apply(uint32_t time, SPowerType* type, SCreature* caster, SCreature* target, map<PowerProjectileMods::Enum, int32_t> values, EResults::Enum result){
	//cerr<<"apply dd"<<endl;
	
	//
	uint32_t totalDamage = myrandom(_minDamage,_maxDamage);
	//cerr<<"a "<<totalDamage<<endl; 
	totalDamage+=  values[PowerProjectileMods::Spower] * type->getStats()[PowerTypeStats::CD] / 3000;
	//cerr<<"b "<<totalDamage<<endl; 
	totalDamage = (totalDamage * values[PowerProjectileMods::SpowerBonus])/100;
	//cerr<<"c "<<totalDamage<<endl; 
	totalDamage = (totalDamage * values[PowerProjectileMods::SpowerBonusBuff])/100;
	//cerr<<"d "<<totalDamage<<endl; 
	if(result == EResults::SCrit)
		totalDamage = (totalDamage * _critMod) / 100;
	//cerr<<"e "<<totalDamage<<endl; 		
	SC_ApplyDamage* command = new SC_ApplyDamage(time,caster,target,totalDamage,_damageType,type);
	target->addCommand(command);
}

SEffectTypeDD::~SEffectTypeDD() {
}

