/* 
 * File:   SC_Debuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:36
 */

#include "SC_Debuff.h"
#include "../objects/SObj.h"
SC_Debuff::SC_Debuff(uint32_t time, SObj* unit,uint32_t tick, uint32_t damageRemaning) 
:SCommand(time,unit){
	_tick = tick;
	_damageRemaing = damageRemaning;
}

uint32_t SC_Debuff::execute(){
	cerr<<"debuff"<<endl;
	_time += 1000;
	_unit->addCommand(this);
	return 1;
}

SC_Debuff::~SC_Debuff() {
}

