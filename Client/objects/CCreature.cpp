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

	CObj::Proces(DTime); //Basic movement
	ProcesGrafic(DTime); //do the grafic

}

uint32_t CCreature::addBuff(CBuff* buff){
	cerr<<"ADD Buff"<<endl;
	_bufflist[buff->getId()] = buff;
	for(list<GraficEffectType*>::iterator it2 = buff->getEffects().begin(); it2 != buff->getEffects().end(); it2++){
		if((*it2)){
			AddEffectPlayer((*it2)->getId());
			_effects[(*it2)->getId()]->signal(GEP::Init);
		}
		cerr<<"DONE ADD EP"<<endl;
	}
	
	cerr<<"DONE ADD Buff"<<endl;
}
uint32_t CCreature::removeBuff(CBuff* buff){
	_bufflist.erase(buff->getId());
	for(list<GraficEffectType*>::iterator it2 = buff->getEffects().begin(); it2 != buff->getEffects().end(); it2++){
		if((*it2)){
			RemoveEffectPlayer((*it2)->getId());
		}
		cerr<<"DONE ADD EP"<<endl;
	}
	
	//TODO delete buff??
}


CCreature::~CCreature() {
}

