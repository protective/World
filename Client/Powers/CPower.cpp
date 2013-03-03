/* 
 * File:   CPower.cpp
 * Author: karsten
 * 
 * Created on 31. januar 2013, 14:32
 */

#include "CPower.h"

CPower::CPower(uint32_t id, CObj* owner, uint32_t iconId, uint32_t castTime) {
	_id = id;
	_owner = owner;
	_iconId = iconId;
	_castTime = castTime;
}

 void CPower::activate(CObj* target){
	 cerr<<"activate"<<endl;
	 playerObj->ServerReqActivatePower(this,target);
 }

CPower::~CPower() {
}

