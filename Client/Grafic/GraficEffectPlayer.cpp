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
	_signal = 0;
	_refs = 0;
}

void GraficEffectPlayer::draw(Camera* camera){
	//cerr<<"draw par"<<endl;
	for(map<uint32_t, ParticalSystem*>::iterator it2 = _particalS.begin(); it2 != _particalS.end(); it2++){
		if(it2->second)
			it2->second->draw(camera);
	}
	//cerr<<"end draw par"<<endl;
}
void GraficEffectPlayer::Proces(uint32_t DTime){

	if(_signal & GEP::Term){//destroy system

		if(_signal & GEP::Init){//force remove if we are reinitiating
			checkDeleteAllParticalSystems(true);
		}else{				
			for (map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin() ; it != _particalS.end();it++){
				if(_particalS[it->first]){
					_particalS[it->first]->TermParticleSystem(); 
				}
			}
		}
	}

	if(_signal & GEP::Init){ //Create system
		for (map<uint32_t, GraficEffectDataBlock*>::iterator it = _typeData->getData().begin() ; it != _typeData->getData().end();it++){
			if(_particalS[it->first] && (it->second->getTermOnInit() || _particalS[it->first]->IsTerminating())){ //clear we need to restart PS
				delete _particalS[it->first];
				_particalS[it->first] = NULL;
			}
			if(!_particalS[it->first]){//No system exist Create one
				_particalS[it->first] = new ParticalSystem(it->second);
				_particalS[it->first]->InitParticleSystem(_obj,it->second->getHardPoint());
			}

		}

	}
	_signal = 0; //clear all signals


	//cerr<<"update par"<<endl;

	for(map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin(); it != _particalS.end(); it++){
		if(it->second){
			it->second->Update(DTime);
		}
	}
	
	//check particalsystem if ready for delete
	checkDeleteAllParticalSystems(false);
}


void GraficEffectPlayer::checkDeleteAllParticalSystems(bool force){
	for(map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin(); it != _particalS.end(); it++){
		if(it->second && (_particalS[it->first]->SystemDone() || force)){
			delete _particalS[it->first];
			_particalS[it->first] = NULL;
		}
	}
}
/*
 signal = 0x01 Init Effect
 signal = 0x02 Term Effect
 */
uint32_t GraficEffectPlayer::signal(uint32_t signal){
	_signal = _signal | signal;
}
bool GraficEffectPlayer::canBeRemoved(){
	uint32_t i = 0;
	for(map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin(); it != _particalS.end(); it++){
		if(it->second != NULL)
			i++;
	}
	return i == 0;
}

GraficEffectPlayer::~GraficEffectPlayer() {
	//kill all particalsystems
	for(map<uint32_t, ParticalSystem*>::iterator it = _particalS.begin(); it != _particalS.end(); it++){
		delete it->second;
	}
}

