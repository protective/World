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

SCreature::~SCreature() {
}

