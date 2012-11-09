/* 
 * File:   SPower.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 17:40
 */

#include "SPower.h"

SPower::SPower(uint32_t id, SPowerType* powertype) {
	_powertype = powertype;
	_id = id;
}

uint32_t SPower::activate(uint32_t time, SObj* caster,SObj* target){
	cerr<<"activate power "<<endl;
	 _powertype->activate(time,caster,target);
}



SPower::~SPower() {
}

