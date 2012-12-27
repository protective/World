/* 
 * File:   SPower.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:40
 */

#include "SPower.h"
#include "../Command/SC_FirePower.h"
#include "../objects/SObj.h"
SPower::SPower(uint32_t id, SPowerType* powertype) {
	_powertype = powertype;
	_id = id;
}

uint32_t SPower::activate(uint32_t time, SObj* caster,SObj* target){
	cerr<<"activate power "<<endl; //CHECK MANA ENERGY and regent costs
	SC_FirePower* cmd = new SC_FirePower(time+_powertype->getStats()[PowerTypeStats::CastTime],caster,target,this);
	caster->addCommand(cmd);
	//TODO send begin cast info to client
}



SPower::~SPower() {
}

