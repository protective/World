/* 
 * File:   SC_MoveObj.cpp
 * Author: karsten
 * 
 * Created on 14. marts 2013, 21:08
 */

#include "SC_MoveObj.h"

SC_MoveObj::SC_MoveObj(uint32_t time, SObj* caster, SPos pos):
SCommand(time,caster,NULL){
	_pos = pos;
}



uint32_t SC_MoveObj::execute(){
	uint32_t speed = 10;

	if(Rangeobj(_pos, _caster->getPos()) >speed){
		_caster->getPos().d = (100 * Direction(_caster->getPos(),this->_pos));
		_caster->MovePos((VektorUnitX(_caster->getPos().d/100) * speed*100) ,-((VektorUnitY(_caster->getPos().d/100)* speed*100)));
		this->_time+=25;
		_caster->addCommand(this); 
		return 1;
	}else{
		_caster->setPos(_pos);
		return 0;
	}
	
}


SC_MoveObj::~SC_MoveObj() {
}

