/* 
 * File:   SC_MoveObj.cpp
 * Author: karsten
 * 
 * Created on 14. marts 2013, 21:08
 */

#include "SC_MoveObj.h"

SC_MoveObj::SC_MoveObj(uint32_t time, SObj* procesUnit, SPos pos):
SCommand(time,procesUnit){
	_pos = pos;
}



uint32_t SC_MoveObj::execute(){
	uint32_t speed = 10;

	if(Rangeobj(_pos, _procesUnit->getPos()) >speed){
		_procesUnit->getPos().d = (100 * Direction(_procesUnit->getPos(),this->_pos));
		_procesUnit->MovePos((VektorUnitX(_procesUnit->getPos().d/100) * speed*100) ,-((VektorUnitY(_procesUnit->getPos().d/100)* speed*100)));
		this->_time+=25;
		_procesUnit->addCommand(this); 
		return 1;
	}else{
		_procesUnit->setPos(_pos);
		return 0;
	}
	
}


SC_MoveObj::~SC_MoveObj() {
}

