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
SC_BuffProces::SC_BuffProces(uint32_t time, SObj* procesUnit, SObj* caster, SBuff* buff):
SCommand(time,procesUnit){
	_buff = buff;
	_caster = caster;
}

uint32_t SC_BuffProces::execute(){
	
	_buff->procesTick(this);
	cerr<<"sizebuff "<<_procesUnit->getCreature()->getBuffList().size()<<endl;
	if(_buff->getTickCount()> 0){
		_time += _buff->getTickTime();
		_procesUnit->addCommand(this);
		return 1;
	}else{
		if(_procesUnit->getCreature())
			cerr<<"remove res>"<<_procesUnit->getCreature()->removeBuff(_buff)<<endl;
		delete _buff;
		return 0;
	}
}

SC_BuffProces::~SC_BuffProces() {
}

