/* 
 * File:   CCreature.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:35
 */

#include "CCreature.h"

CCreature::CCreature(uint32_t id, uint32_t playerId, CPos& pos) :
CObj(id,playerId,pos){
}

CCreature::~CCreature() {
}

