/* 
 * File:   SC_ApplyTickSpellDamage.cpp
 * Author: karsten
 * 
 * Created on 1. november 2012, 08:49
 */

#include "SC_ApplyTickSpellDamage.h"

SC_ApplyTickSpellDamage::SC_ApplyTickSpellDamage(uint32_t time, SObj* unit,uint32_t damage):
SCommand(time,unit){
	_damage = damage;
}

uint32_t SC_ApplyTickSpellDamage::execute(){
	cerr<<"DAMAGE >>"<<_damage<<endl;
	return 0;
}

SC_ApplyTickSpellDamage::~SC_ApplyTickSpellDamage() {
}

