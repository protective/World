/* 
 * File:   SC_Debuff.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:36
 */

#include <cmath>

#include "SC_Debuff.h"
#include "../objects/SObj.h"
#include "SC_ApplyTickSpellDamage.h"
SC_Debuff::SC_Debuff(uint32_t time, SObj* unit,uint32_t tick, uint32_t damageRemaning) 
:SCommand(time,unit){
	if(!tick)
		tick = 1;
	_tick = tick;
	_damageRemaing = damageRemaning;
}

uint32_t SC_Debuff::execute(){
	cerr<<"debuff"<<endl;
	uint32_t a = floor(_damageRemaing/_tick);
	_damageRemaing -=a;
	_unit->addCommand(new SC_ApplyTickSpellDamage(_time,_unit,a));
	_tick -= 1;
	if(_tick){
		_time += 3000;
		_unit->addCommand(this);

		return 1;
	}
	return 0;
}

SC_Debuff::~SC_Debuff() {
}

