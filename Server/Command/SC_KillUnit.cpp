/* 
 * File:   SC_KillUnit.cpp
 * Author: karsten
 * 
 * Created on 16. november 2012, 23:58
 */

#include "SC_KillUnit.h"
#include "../objects/SObj.h"
SC_KillUnit::SC_KillUnit(uint32_t time, SObj* procesUnit, SObj* caster):
SCommand(time,procesUnit) {
	_caster = caster;
}


uint32_t SC_KillUnit::execute(){

	char message[sizeof(SerialKillUnit)];
	memset(message,0,sizeof(SerialKillUnit));
	SerialKillUnit* data = (SerialKillUnit*)(message);
	data->_type = SerialType::SerialKillUnit;
	data->_size = sizeof(SerialKillUnit);
	data->_unitId = _procesUnit->getId();
	
	for(list<Client*>::iterator it = _procesUnit->getSubscribers()[0].begin(); it != _procesUnit->getSubscribers()[0].end(); it++){
		sendtoC(*it,message,sizeof(SerialKillUnit));
	}
	return 0;
}

SC_KillUnit::~SC_KillUnit() {
}

