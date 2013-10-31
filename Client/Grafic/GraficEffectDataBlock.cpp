/* 
 * File:   GraficEffectDataBlock.cpp
 * Author: karsten
 * 
 * Created on 20. oktober 2013, 16:19
 */

#include "GraficEffectDataBlock.h"

GraficEffectDataBlock::GraficEffectDataBlock() {

	_hp = HardPoints::AboveHead;
	_engine = NULL;
	_deltaV = glm::vec3(0,0,0);
	_termOnInit = false;
	_termTime = 5000;
	
	_blocks[PSStates::Default] = new GraficEffectDataBlockState();
	_blocks[PSStates::Init] = _blocks[PSStates::Default];
	_blocks[PSStates::Run] = _blocks[PSStates::Default];
	_blocks[PSStates::Term] = _blocks[PSStates::Default];
}
void GraficEffectDataBlock::SetDataBlockState(PSStates::Enum state, GraficEffectDataBlockState* data){
	_blocks[state] = data;
}



GraficEffectDataBlock::~GraficEffectDataBlock() {
}

