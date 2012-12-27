/* 
 * File:   SC_BuffProces.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:16
 */

#include "SC_BuffProces.h"
#include "../objects/Buffs/SBuff.h"
#include "../objects/SObj.h"
#include "../objects/SCreature.h"
SC_BuffProces::SC_BuffProces(uint32_t time, SObj* caster, SObj* target, SBuff* buff):
SCommand(time,caster,target){
	_buff = buff;
}

uint32_t SC_BuffProces::execute(){
	
	_buff->procesTick(this);
	if(_buff->getTickCount()> 0){
		_time += _buff->getTickTime();
		_target->addCommand(this);
		return 1;
	}else{
		if(_target->getCreature())
			_target->getCreature()->removeBuff(_buff);
		delete _buff;
		cerr<<"delete buff"<<endl;
		return 0;
	}
}

SC_BuffProces::~SC_BuffProces() {
}

