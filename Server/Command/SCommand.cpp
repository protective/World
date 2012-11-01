/* 
 * File:   SCommand.cpp
 * Author: karsten
 * 
 * Created on 31. oktober 2012, 16:01
 */

#include "SCommand.h"
#include "../objects/SObj.h"
SCommand::SCommand(uint32_t time, SObj* unit) {
	_time = time;
	_unit = unit;
}


SCommand::~SCommand() {
}

