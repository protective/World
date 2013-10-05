/* 
 * File:   CCreature.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:35
 */

#include "CCreature.h"
#include "../Grafic/Grafic.h"


CCreature::CCreature(uint32_t id, uint32_t playerId, CPos pos, Model* model) :
CObj(id,playerId,pos), CGraficObject(model){
	
	for(map<Attributes::Enum,int32_t>::iterator it = _attribute.begin(); it != _attribute.end();it++){
		_attribute[it->first] = 0;
	}
}

void CCreature::Proces(uint32_t DTime){
	CObj::Proces(DTime);
	
	for(list<ParticalSystem*>::iterator it = _particalSystems.begin(); it != _particalSystems.end(); it++){
		(*it)->Update(DTime);
	}
}

CCreature::~CCreature() {
}

