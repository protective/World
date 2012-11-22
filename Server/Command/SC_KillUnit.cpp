/* 
 * File:   SC_KillUnit.cpp
 * Author: karsten
 * 
 * Created on 16. november 2012, 23:58
 */

#include "SC_KillUnit.h"

SC_KillUnit::SC_KillUnit(uint32_t time, SObj* caster, SObj* target):
SCommand(time,caster,target) {
	
}


uint32_t SC_KillUnit::execute(){

	char message[sizeof(SerialKillUnit)];
	memset(message,0,sizeof(SerialKillUnit));
	SerialTakeDmgHeal* data = (SerialKillUnit*)(message);
	data->_type = SerialType::SerialKillUnit;
	data->_size = sizeof(SerialKillUnit);
	data->_unitId = _target->getId();
	
	for(list<Client*>::iterator it = _target->getSubscribers().begin(); it != _target->getSubscribers().end(); it++){
		sendtoC(*it,message,sizeof(SerialKillUnit));
	}
	return 0;
}

SC_KillUnit::~SC_KillUnit() {
}

