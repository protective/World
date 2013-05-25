/* 
 * File:   SC_ObjProces.cpp
 * Author: karsten
 * 
 * Created on 14. maj 2013, 21:26
 */

#include <sys/types.h>

#include "SC_ObjProces.h"
#include "../objects/SCreature.h"
SC_ObjProces::SC_ObjProces(uint32_t time, SObj* procesUnit, SC_ObjProcesTask::Enum task):
SCommand(time,procesUnit){
	_task = task;
}

uint32_t SC_ObjProces::execute(){
	if(_procesUnit->getId() == 3)
		cerr<<"proces "<<_task<<endl;
	if(_task == SC_ObjProcesTask::Mana){
		int32_t mana = _procesUnit->getCreature()->getAttibute()[Attributes::Mana];
		int32_t maxmana = _procesUnit->getCreature()->getAttibute()[Attributes::ManaMax];
		int32_t spirit = _procesUnit->getCreature()->getAttibute()[Attributes::Spirit];
		int32_t RegenOFSRP = _procesUnit->getCreature()->getAttibute()[Attributes::RegenOFSRP];

		_procesUnit->getCreature()->modMana(max(0,(spirit * (100-RegenOFSRP))/100));
		_time+= 2000;

		_procesUnit->addCommand(this);
		return 1;
	}else if(_task == SC_ObjProcesTask::ManaContinue){
		int32_t mana = _procesUnit->getCreature()->getAttibute()[Attributes::Mana];
		int32_t maxmana = _procesUnit->getCreature()->getAttibute()[Attributes::ManaMax];
		int32_t spirit = _procesUnit->getCreature()->getAttibute()[Attributes::Spirit];
		int32_t RegenOFSRP = _procesUnit->getCreature()->getAttibute()[Attributes::RegenOFSRP];

		_procesUnit->getCreature()->modMana((spirit * (min(100,RegenOFSRP)))/100);
		_time+= 2000;

		_procesUnit->addCommand(this);
		return 1;	
	}else if(_task == SC_ObjProcesTask::ManaPFS){
		int32_t mana = _procesUnit->getCreature()->getAttibute()[Attributes::ManaPrF];

		_procesUnit->getCreature()->modMana(mana);
		_time+= 5000;

		_procesUnit->addCommand(this);
		return 1;
	}else if(_task == SC_ObjProcesTask::Focus){
		int32_t mana = _procesUnit->getCreature()->getAttibute()[Attributes::Mana];
		int32_t maxmana = _procesUnit->getCreature()->getAttibute()[Attributes::ManaMax];
		int32_t spirit = _procesUnit->getCreature()->getAttibute()[Attributes::Spirit];
		int32_t RegenOFSRP = _procesUnit->getCreature()->getAttibute()[Attributes::RegenOFSRP];

		_procesUnit->getCreature()->modFocus(10);
		_time+= 2000;

		_procesUnit->addCommand(this);
		return 1;	
	}
}



SC_ObjProces::~SC_ObjProces() {
}

