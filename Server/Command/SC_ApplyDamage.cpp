/* 
 * File:   SC_ApplyDamage.cpp
 * Author: karsten
 * 
 * Created on 15. november 2012, 21:07
 */

#include "SC_ApplyDamage.h"
#include "../objects/SCreature.h"
#include "../Client.h"
SC_ApplyDamage::SC_ApplyDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power):
SCommand(time,caster,target){
	_damage = damage;
	_dmgType = dmgType;
	_power = power;
	
}


uint32_t SC_ApplyDamage::execute(){

	_target->getCreature()->getAttibute()[Attributes::Hp] -= _damage;
	cerr<<"damge "<<_damage<<" type "<<_dmgType<<endl;
	
	char message[sizeof(SerialTakeDmgHeal)];
	memset(message,0,sizeof(SerialTakeDmgHeal));
	SerialTakeDmgHeal* data = (SerialTakeDmgHeal*)(message);
	data->_type = SerialType::SerialTakeDmgHeal;
	data->_size = sizeof(SerialTakeDmgHeal);
	data->_time = _time;
	data->_value = 0 - _damage;
	data->_flags = 0;
	cerr<<"id "<<_target->getCreature()->getId()<<endl;
	cerr<<"maxhp "<<_target->getCreature()->getAttibute()[Attributes::HpMax]<<endl;
	data->_unitId = _target->getId();
	data->_casterId = _caster->getId();
	data->_powerid = _power->getId();
	data->_newvalue = _target->getCreature()->getAttibute()[Attributes::Hp];
	for(list<Client*>::iterator it = _target->getSubscribers().begin(); it != _target->getSubscribers().end(); it++){
		cerr<<"temp "<<(*it)->getTeamId()<<" "<<_target->getTeam()<<endl;
		if ((*it)->getTeamId() == _target->getTeam()){
			cerr<<"send nromal"<<endl;
			sendtoC(*it,message,sizeof(SerialTakeDmgHeal));
		}
	}	
	data->_newvalue = 0;
	if(_target->getCreature()->getAttibute()[Attributes::HpMax]){
		data->_newvalue = _target->getCreature()->getAttibute()[Attributes::Hp]*100 / _target->getCreature()->getAttibute()[Attributes::HpMax];
		data->_flags |= SerialTakeDmgHealBitF::ValueP;
	}
	
	for(list<Client*>::iterator it = _target->getSubscribers().begin(); it != _target->getSubscribers().end(); it++){
		if ((*it)->getTeamId() != _target->getTeam())
			sendtoC(*it,message,sizeof(SerialTakeDmgHeal));
	}	
	
	return 0;
}


SC_ApplyDamage::~SC_ApplyDamage() {
}

