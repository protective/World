/* 
 * File:   SCommand.cpp
 * Author: karsten
 * 
 * Created on 31. oktober 2012, 16:01
 */

#include "SCommand.h"
#include "../objects/SObj.h"
SCommand::SCommand(uint32_t time, SObj* procesUnit) {
	_time = time;
	_procesUnit = procesUnit;
	
}

uint32_t SCommand::remove(){
	this->_procesUnit->removeCommand(this);
}

uint32_t SCommand::resetTime(uint32_t newtime){
	this->remove();
	_time = newtime;
	this->_procesUnit->addCommand(this);
}


SCommand::~SCommand() {
}

