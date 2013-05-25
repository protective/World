/* 
 * File:   SC_HitPower.cpp
 * Author: karsten
 * 
 * Created on 26. december 2012, 21:09
 */

#include "SC_HitPower.h"
#include "../Powers/SPower.h"
SC_HitPower::SC_HitPower(uint32_t time, SObj* procesUnit, SObj* caster, SPower* power):
SCommand(time,procesUnit){
	_power = power;
	_caster = caster;
}

uint32_t SC_HitPower::execute(){
	_power->getPowerType()->activate(_time,_caster,_procesUnit,_values);
	return 0;
}

SC_HitPower::~SC_HitPower() {
}

