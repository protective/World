/* 
 * File:   SPower.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:40
 */

#include "SPower.h"
#include "../Command/SC_FirePower.h"
#include "../objects/SObj.h"
SPower::SPower(uint32_t id, SObj* owner, SPowerType* powertype) {
	_powertype = powertype;
	_id = id;
	_owner = owner;
}

void SPower::sendToClient(Client* cli){
	char message[sizeof(SerialPower)];
	memset(message,0,sizeof(SerialPower));
	SerialPower* data = (SerialPower*)(message);
	data->_type = SerialType::SerialPower;
	data->_size = sizeof(SerialPower);
	data->_unitId = this->_owner->getId();
	data->_powerId = this->_id;
	data->_iconId = this->_powertype->getIconId();
	data->_cd = this->_cd;
	
	sendtoC(cli,message,sizeof(SerialPower));
}

uint32_t SPower::activate(uint32_t time, SObj* caster,SObj* target){
	cerr<<"activate power "<<endl; //CHECK MANA ENERGY and regent costs
	
	
	char message[sizeof(SerialBeginCast)];
	memset(message,0,sizeof(SerialBeginCast));
	SerialBeginCast* data = (SerialBeginCast*)(message);
	data->_type = SerialType::SerialBeginCast;
	data->_size = sizeof(SerialBeginCast);
	data->_time = time;
	data->_unitId = this->_owner->getId();
	data->_powerid = this->getId();
	data->_castTime = this->_powertype->getStats()[PowerTypeStats::CastTime];
	
	for(list<Client*>::iterator it = this->_owner->getSubscribers().begin(); it != this->_owner->getSubscribers().end(); it++){
		sendtoC(*it,message,sizeof(SerialBeginCast));
	}
	
	SC_FirePower* cmd = new SC_FirePower(time+_powertype->getStats()[PowerTypeStats::CastTime],caster,target,this);
	caster->addCommand(cmd);
	//TODO send begin cast info to client
}



SPower::~SPower() {
}

