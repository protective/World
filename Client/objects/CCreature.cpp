/* 
 * File:   CCreature.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:35
 */

#include "CCreature.h"
#include "../Grafic/Grafic.h"
#include "../Grafic/screenControler.h"

CCreature::CCreature(uint32_t id, uint32_t playerId, CPos pos, Model* model) :
CObj(id,playerId,pos), CGraficObject(model){
	
	for(map<Attributes::Enum,int32_t>::iterator it = _attribute.begin(); it != _attribute.end();it++){
		_attribute[it->first] = 0;
	}
	if(id == 2)
			addParticalsystem(0);
}

void CCreature::Proces(uint32_t DTime){
	CObj::Proces(DTime);
	
	for(map<uint32_t, ParticalSystem*>::iterator it = _particalSystems.begin(); it != _particalSystems.end(); it++){
		if(it->second == NULL){
			it->second =  new ParticalSystem(masterScreen->_getParticalEngines());
			it->second->InitParticleSystem(glm::vec3(_pos.x/1000,(_pos.y/1000)-3,(_pos.z/1000)-5));
		}
		it->second->Update(DTime);
	}
}

CCreature::~CCreature() {
}

