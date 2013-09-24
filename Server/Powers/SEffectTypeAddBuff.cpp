/* 
 * File:   SEffectTypeAddBuff.cpp
 * Author: karsten
 * 
 * Created on 20. december 2012, 22:15
 */

#include "SEffectTypeAddBuff.h"
#include "../objects/Buffs/SBuffDot.h"
#include "../objects/Buffs/SBuffStat.h"
#include "../Command/SC_BuffProces.h"
SEffectTypeAddBuff::SEffectTypeAddBuff() {
	_tickTime = 0;
	_totalDamage = 0;
}

void SEffectTypeAddBuff::apply(uint32_t time,SPowerType* type, SCreature* caster, SCreature* target,map<PowerProjectileMods::Enum, int32_t> values, EResults::Enum result){
	cerr<<"apply buff"<<endl;
	SBuff* buffToAdd = new SBuff(type,_tickEffects.size(),_tickTime);
	
	for(map<BuffVisualEffects::Enum,uint32_t>::iterator it = _visualEffects.begin(); it != _visualEffects.end(); it++){
		buffToAdd->getVIsualEffects()[it->first] = it->second;
	
	}
	
	if(_totalDamage > 0){
		SBuffDot* buffsEffects = new SBuffDot(buffToAdd,target,this);
		buffToAdd->getEffects().push_back(buffsEffects);
	}
	for (map<StatsMods::Enum, int32_t>::iterator it = _statsMods.begin(); it != _statsMods.end(); it++){
		SBuffStat* buffsEffects = new SBuffStat(buffToAdd,it->first, it->second);
		buffToAdd->getEffects().push_back(buffsEffects);
	}
	target->addBuff(buffToAdd);
	SC_BuffProces* command = new SC_BuffProces(time,caster,target,buffToAdd);
	target->addCommand(command);
	
	/*NETWORK ADD BUFF*/
	uint32_t Xvisual = buffToAdd->getVIsualEffects().size();
	uint32_t BSize = sizeof(SerialBuff)+(Xvisual*sizeof(SerialBuffVisualEffect));
	char message[BSize];
	memset(message,0,BSize);
	SerialBuff* data = (SerialBuff*)(message);
	data->_type = SerialType::SerialBuff;
	data->_size = BSize;
	data->_time = time;
	data->_unitId = target->getId();
	data->_duration = time;
	data->_maxDuration = time + (buffToAdd->getTickCount() * buffToAdd->getTickTime());	//data->_playerId = this->_playerId;
	data->_XVisualEffects = Xvisual;
	data->_iconId = 1;
	
	uint32_t i = 0;
	for(map<BuffVisualEffects::Enum,uint32_t>::iterator it = _visualEffects.begin(); it != _visualEffects.end(); it++){
		SerialBuffVisualEffect* data2 = (SerialBuffVisualEffect*)(message+(sizeof(SerialBuff))+(sizeof(SerialBuffVisualEffect)*i));
		data2->_effect = it->first;
		data2->_value = it->second;
		
		i++;
	}
	
	for(list<Client*>::iterator it = target->getSubscribers()[0].begin(); it != target->getSubscribers()[0].end(); it++){

		sendtoC(*it,message,BSize);
	}
	
	
}


SEffectTypeAddBuff::~SEffectTypeAddBuff() {
}

