/* 
 * File:   CCreature.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:35
 */

#include "CCreature.h"
#include "../Grafic/Grafic.h"
#include "../Grafic/screenControler.h"
#include "Buffs/CBuff.h"

CCreature::CCreature(uint32_t id, uint32_t playerId, CPos pos, Model* model) :
CObj(id,playerId,pos), CGraficObject(this,model){
	
	for(map<Attributes::Enum,int32_t>::iterator it = _attribute.begin(); it != _attribute.end();it++){
		_attribute[it->first] = 0;
	}
}

void CCreature::Proces(uint32_t DTime){
	CObj::Proces(DTime);
	CGraficObject:Proces(DTime);
	//
	//for(map<uint32_t, ParticalSystem*>::iterator it = _particalSystems.begin(); it != _particalSystems.end(); it++){
	//	if(it->second == NULL){
	//		it->second =  new ParticalSystem(masterScreen->_getParticalEngines());
	//		it->second->InitParticleSystem(this,HardPoints::AboveHead);
	//	}
	//	it->second->Update(DTime);
	//}
}

uint32_t CCreature::addBuff(CBuff* buff){
	_bufflist[buff->getId()] = buff;
	
	//create the effecplayer;
}


CCreature::~CCreature() {
}

