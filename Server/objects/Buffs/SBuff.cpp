/* 
 * File:   SBuff.cpp
 * Author: karsten
 * 
 * Created on 17. november 2012, 21:31
 */

#include "SBuff.h"

SBuff::SBuff(SPowerType* type, uint32_t maxTick, uint32_t tickTime) {
	_maxtickCount = maxTick;
	_tickCount = maxTick;
	_tickTime = tickTime;
	_type = type;
}

uint32_t SBuff::procesTick(SC_BuffProces* cmd){
	
	for (list<SBuffBase*>::iterator it = _effects.begin(); it != _effects.end();it++){
		(*it)->proces(cmd,_tickCount);
	}
	_tickCount--;
}

SBuff::~SBuff() {
}

