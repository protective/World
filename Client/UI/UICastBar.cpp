/* 
 * File:   UICastBar.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:33
 */

#include "UICastBar.h"

UICastBar::UICastBar(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height,CCreature* creature):
UIBaseFrame(parrent,x,y,wight,height){
	_creature = creature;
}

void UICastBar::draw(){

}

UICastBar::~UICastBar() {
}

