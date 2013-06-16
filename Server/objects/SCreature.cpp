/* 
 * File:   SCreature.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 22:52
 */

#include <sys/types.h>

#include "SCreature.h"
#include "Buffs/SBuffStat.h"
#include "../Client.h"

SCreature::SCreature(uint32_t id, SPos pos, uint32_t team, uint32_t playerId):
SObj(id,pos,team,playerId){
	
	SC_ObjProcesTask::Enum task[4] = {SC_ObjProcesTask::Mana,SC_ObjProcesTask::Focus,SC_ObjProcesTask::ManaContinue,SC_ObjProcesTask::ManaPFS};
	
	for (uint32_t i = 0; i< 4; i++){
		_procesTask[task[i]] = new SC_ObjProces(SDL_GetTicks(),this,task[i]);
		this->addCommand(_procesTask[task[i]]);
	}
	//_procesTask[SC_ObjProcesTask::ManaContinue] = new SC_ObjProces(SDL_GetTicks(),this,SC_ObjProcesTask::ManaContinue);
	//_procesTask[SC_ObjProcesTask::Mana] = new SC_ObjProces(SDL_GetTicks(),this,SC_ObjProcesTask::Mana);
	//_procesTask[SC_ObjProcesTask::Mana] = new SC_ObjProces(SDL_GetTicks(),this,SC_ObjProcesTask::Mana);
	
}

void SCreature::sendToClient(Client* cli){
	char message[sizeof(SerialCreature)];
	memset(message,0,sizeof(SerialCreature));
	SerialCreature* data = (SerialCreature*)(message);
	data->_type = SerialType::SerialCreature;
	data->_size = sizeof(SerialCreature);
	data->_unitId = this->_id;
	data->_playerId = this->_playerId;
	data->_x = this->_pos.x;
	data->_y = this->_pos.y;
	data->_z = this->_pos.z;
	data->_d = this->_pos.d;
	sendtoC(cli,message,sizeof(SerialCreature));

	for(map<Attributes::Enum , int32_t>::iterator it = _attribute.begin(); it != _attribute.end(); it++){
		if(it->second)
			this->transmitAttribute(it->first);
	}
	
	for(map<uint32_t,SPower*>::iterator it = _powerList.begin(); it != _powerList.end(); it++){
		it->second->sendToClient(cli);
	}
	
}

void SCreature::SetAttributes(Attributes::Enum attri,int32_t value){
	
	if (attri == Attributes::HpP || attri == Attributes::ManaP || attri == Attributes::FocusP){
		cerr<<"WARNING SCreature::SetAttributes do not set P"<<endl;
		return;
	}
	
	this->_attribute[attri] = value;
	this->transmitAttribute(attri);
}

void SCreature::setCasting(SPower* casting){
	_casting = casting;
	if (_procesTask[SC_ObjProcesTask::Mana]){
		_procesTask[SC_ObjProcesTask::Mana]->resetTime(SDL_GetTicks()+5000);
	}
}

int32_t SCreature::modMana(int32_t mana){
	if (_attribute[Attributes::Mana] + mana <= _attribute[Attributes::ManaMax]){
		SetAttributes(Attributes::Mana,_attribute[Attributes::Mana] + mana);
		return mana;
	}else{
		int32_t diff = _attribute[Attributes::ManaMax] -_attribute[Attributes::Mana];
		SetAttributes(Attributes::Mana,_attribute[Attributes::ManaMax]);
		return diff;
	}
}

int32_t SCreature::modFocus(int32_t focus){
	if (_attribute[Attributes::Focus] + focus <= _attribute[Attributes::FocusMax]){
		SetAttributes(Attributes::Focus,_attribute[Attributes::Focus] + focus);
		return focus;
	}else{
		int32_t diff = _attribute[Attributes::FocusMax] -_attribute[Attributes::Focus];
		SetAttributes(Attributes::Focus,_attribute[Attributes::FocusMax]);
		return diff;
	}
}


void SCreature::transmitAttribute(Attributes::Enum attri){
	
	
	char message[sizeof(SerialAttribute)];
	memset(message,0,sizeof(SerialAttribute));
	SerialAttribute* data = (SerialAttribute*)(message);
	data->_type = SerialType::SerialAttribute;
	data->_size = sizeof(SerialAttribute);
	data->_time = 0;
	data->_unitId = this->getId();
	data->_attribute = attri;
	data->_value = _attribute[attri];
	
	for(list<Client*>::iterator it = this->getSubscribers().begin(); it != this->getSubscribers().end(); it++){
		if ((*it)->getTeamId() == this->getTeam())
			sendtoC(*it,message,sizeof(SerialAttribute));
	}	
	
	if(attri == Attributes::Hp || attri == Attributes::Mana || attri == Attributes::Focus ||
	attri == Attributes::HpMax || attri == Attributes::ManaMax || attri == Attributes::FocusMax){
		Attributes::Enum temp;
		int32_t tempP = 0;
		switch(attri){
			case Attributes::Hp:
			case Attributes::HpMax:
				temp = Attributes::HpP;
				if(_attribute[Attributes::HpMax])
					tempP = (_attribute[Attributes::Hp]* 100) / _attribute[Attributes::HpMax];
				break;
			case Attributes::Mana:
			case Attributes::ManaMax:
				temp = Attributes::ManaP;
				if(_attribute[Attributes::ManaMax])
					tempP = (_attribute[Attributes::Mana]* 100) / _attribute[Attributes::ManaMax];
				break;
			case Attributes::Focus:
			case Attributes::FocusMax:
				temp = Attributes::FocusP;
				if(_attribute[Attributes::FocusMax])
					tempP = (_attribute[Attributes::Focus]* 100) / _attribute[Attributes::FocusMax];
				break;
		}
		
		char message2[sizeof(SerialAttribute)];
		memset(message2,0,sizeof(SerialAttribute));
		SerialAttribute* data2 = (SerialAttribute*)(message2);
		data2->_type = SerialType::SerialAttribute;
		data2->_size = sizeof(SerialAttribute);
		data2->_time = 0;
		data2->_unitId = this->getId();
		data2->_attribute = temp;
		data2->_value = tempP;


		for(list<Client*>::iterator it = this->getSubscribers().begin(); it != this->getSubscribers().end(); it++){
			if ((*it)->getTeamId() != this->getTeam())
				sendtoC(*it,message,sizeof(SerialAttribute));
		}
	}
}

void SCreature::addPower(SPower* power){
	_powerList[power->getId()] = power;
	
	for(list<Client*>::iterator it = _subscribers.begin(); it != _subscribers.end(); it++){
		power->sendToClient(*it);
	}
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
	//_attribute.clear();
	for (map<Attributes::Enum, int32_t>::iterator it = _BaseAttribute.begin(); it != _BaseAttribute.end();it++){
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

