/* 
 * File:   SCreature.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:52
 */

#include "SCreature.h"

SCreature::SCreature(uint32_t id, SPos pos, uint8_t team, uint32_t playerId):
SObj(id,pos,team,playerId){
	
	
}
void SCreature::addPower(SPower* power){
	_powerList[power->getId()] = power;
}

uint32_t SCreature::addBuff(SBuff* buff){
	for(int i = 0; ;i++){
		if(_bufflist.find(i) == _bufflist.end()){
			_bufflist[i] = buff;
			return i;
		}
			
	}
}

uint32_t SCreature::removeBuff(SBuff* buff){
	for(map<uint32_t,SBuff*>::iterator it = _bufflist.begin(); it != _bufflist.end();it++){
		if(it->second == buff){
			_bufflist.erase(it);
			return it->first;
		}
	}
}

SCreature::~SCreature() {
}

