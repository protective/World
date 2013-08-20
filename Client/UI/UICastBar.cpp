/* 
 * File:   UICastBar.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:33
 */

#include "UICastBar.h"
#include "../objects/CCreature.h"
UICastBar::UICastBar(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height, CCreature* creature):
UIBaseFrame(parrent,x,y,wight,height){
	_creature = creature;
}

void UICastBar::draw(){
	/*
	glTranslated((GLfloat)(_x),(GLfloat)(_y),0);
	glPushMatrix();

	
	if(_creature->getCastTime() > 0){
		int32_t remaning =  _creature->getCastCompletionTime() - getTime();
		int32_t castTime = _creature->getCastCompletionTime() -_creature->getCastTime();
		Drawbox(0,0,float(_wight) * (1 - (float(remaning) / castTime)),_height ,0,1,0,0);
		Drawbox(0,0,_wight,_height ,0.9,0.9,0.9,1);
	}
	
	glPopMatrix();
	this->drawChilds();
	*/
}

UICastBar::~UICastBar() {
}

