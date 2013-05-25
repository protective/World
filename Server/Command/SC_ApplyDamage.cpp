/* 
 * File:   SC_ApplyDamage.cpp
 * Author: karsten
 * 
 * Created on 15. november 2012, 21:07
 */

#include "SC_ApplyDamage.h"
#include "../objects/SCreature.h"
#include "../Client.h"
SC_ApplyDamage::SC_ApplyDamage(uint32_t time, SObj* procesUnit, SObj* caster, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power):
SCommand(time,procesUnit){
	_damage = damage;
	_dmgType = dmgType;
	_power = power;
	_caster = caster;
}


uint32_t SC_ApplyDamage::execute(){

	_procesUnit->getCreature()->getAttibute()[Attributes::Hp] -= _damage;
	cerr<<"damge "<<_damage<<" type "<<_dmgType<<endl;
	
	char message[sizeof(SerialTakeDmgHeal)];
	memset(message,0,sizeof(SerialTakeDmgHeal));
	SerialTakeDmgHeal* data = (SerialTakeDmgHeal*)(message);
	data->_type = SerialType::SerialTakeDmgHeal;
	data->_size = sizeof(SerialTakeDmgHeal);
	data->_time = _time;
	data->_value = 0 - _damage;
	data->_flags = 0;
	cerr<<"id "<<_procesUnit->getCreature()->getId()<<endl;
	cerr<<"maxhp "<<_procesUnit->getCreature()->getAttibute()[Attributes::HpMax]<<endl;
	data->_unitId = _procesUnit->getId();
	data->_casterId = _caster->getId();
	data->_powerid = _power->getId();
	data->_newvalue = _procesUnit->getCreature()->getAttibute()[Attributes::Hp];
	for(list<Client*>::iterator it = _procesUnit->getSubscribers().begin(); it != _procesUnit->getSubscribers().end(); it++){
		if ((*it)->getTeamId() == _procesUnit->getTeam()){
			sendtoC(*it,message,sizeof(SerialTakeDmgHeal));
		}
	}	
	data->_newvalue = 0;
	if(_procesUnit->getCreature()->getAttibute()[Attributes::HpMax]){
		data->_newvalue = _procesUnit->getCreature()->getAttibute()[Attributes::Hp]*100 / _procesUnit->getCreature()->getAttibute()[Attributes::HpMax];
		data->_flags |= SerialTakeDmgHealBitF::ValueP;
	}
	
	for(list<Client*>::iterator it = _procesUnit->getSubscribers().begin(); it != _procesUnit->getSubscribers().end(); it++){
		if ((*it)->getTeamId() != _procesUnit->getTeam())
			sendtoC(*it,message,sizeof(SerialTakeDmgHeal));
	}	
	
	return 0;
}


SC_ApplyDamage::~SC_ApplyDamage() {
}

