/* 
 * File:   SBuffStat.cpp
 * Author: karsten
 * 
 * Created on 22. november 2012, 20:02
 */

#include "SBuffStat.h"

SBuffStat::SBuffStat(SBuff* buff, StatsMods::Enum stat, int32_t value):
SBuffBase(buff){
	
	_stat = stat;
	_value = value;
}


SBuffStat::~SBuffStat() {
}

