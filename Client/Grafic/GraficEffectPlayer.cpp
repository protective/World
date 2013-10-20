/* 
 * File:   GraficEffectPlayer.cpp
 * Author: karsten
 * 
 * Created on 20. oktober 2013, 16:17
 */

#include "GraficEffectPlayer.h"
#include "screenControler.h"

GraficEffectPlayer::GraficEffectPlayer(CCreature* obj, GraficEffectType* typeData) {
	_typeData = typeData;		
	_obj = obj;
}

void GraficEffectPlayer::draw(Camera* camera){
	for(map<uint32_t, ParticalSystem*>::iterator it2 = _particalS.begin(); it2 != _particalS.end(); it2++){
		if(it2->second)
			it2->second->draw(camera);
	}
}
void GraficEffectPlayer::Proces(uint32_t DTime){
		for(map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin(); it != _particalS.end(); it++){
			it->second->Update(DTime);
		}
}

uint32_t GraficEffectPlayer::signal(uint32_t signal){
	if(signal == 1){ //Create system
		for (map<uint32_t, GraficEffectDataBlock*>::iterator it = _typeData->getData().begin() ; it != _typeData->getData().end();it++){
				_particalS[it->first] = new ParticalSystem(masterScreen->_getParticalEngines());
				_particalS[it->first]->InitParticleSystem(_obj,HardPoints::AboveHead);
		}

	}else if(signal == 2){//destroy system
		
		
	}
}

GraficEffectPlayer::~GraficEffectPlayer() {
}

