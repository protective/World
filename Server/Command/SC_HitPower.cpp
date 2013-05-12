/* 
 * File:   SC_HitPower.cpp
 * Author: karsten
 * 
 * Created on 26. december 2012, 21:09
 */

#include "SC_HitPower.h"
#include "../Powers/SPower.h"
SC_HitPower::SC_HitPower(uint32_t time, SObj* caster, SObj* target, SPower* power):
SCommand(time,caster,target){
	_power = power;
}

uint32_t SC_HitPower::execute(){
	_power->getPowerType()->activate(_time,_caster,_target,_values);
	return 0;
}

SC_HitPower::~SC_HitPower() {
}

