/* 
 * File:   SCreature.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:52
 */

#include "SCreature.h"
#include "Buffs/SBuffStat.h"

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
			updateAttribute();
			return i;
		}
			
	}
}

uint32_t SCreature::removeBuff(SBuff* buff){
	for(map<uint32_t,SBuff*>::iterator it = _bufflist.begin(); it != _bufflist.end();it++){
		if(it->second == buff){
			_bufflist.erase(it);
			updateAttribute();
			return it->first;
		}
	}
}

void SCreature::updateAttribute(){
	_attribute.clear();
	for (map<Attributes::Enum, uint32_t>::iterator it = _BaseAttribute.begin(); it != _BaseAttribute.end();it++){
		_attribute[it->first] = it->second;
	}
	
	for(map<uint32_t,SBuff*>::iterator it = _bufflist.begin(); it != _bufflist.end(); it++){
		for (list<SBuffBase*>::iterator it2 = it->second->getEffects().begin(); it2 != it->second->getEffects().end(); it2++){
			if ((*it2)->getBuffStat()){
				switch((*it2)->getBuffStat()->getStat()){
					case StatsMods::SpellHit:
						_attribute[Attributes::SpellHit] += (*it2)->getBuffStat()->getValue();
						break;
					case StatsMods::SpellCrit:
						_attribute[Attributes::SpellCrit] += (*it2)->getBuffStat()->getValue();
						
						break;
					case StatsMods::SpellPower:
						_attribute[Attributes::SpellPower] += (*it2)->getBuffStat()->getValue();
						break;
					default:
						break;
				}
			}
		}
	}
	
	
}

SCreature::~SCreature() {
}

