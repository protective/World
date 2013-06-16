/* 
 * File:   UISocket.cpp
 * Author: karsten
 * 
 * Created on 3. marts 2013, 16:40
 */

#include "UISocket.h"

UISocket::UISocket(UIBaseFrame* parrent, uint32_t x, uint32_t y):
UIBaseFrame(parrent,x,y,40,40){
}

uint32_t UISocket::drop(UIAbilityBox* abilityBox){
	_abilityBox = abilityBox;
	addChild(abilityBox);
	
}

uint32_t UISocket::click(uint32_t x, uint32_t y){
	return this->clickChilds(x,y);
}

void UISocket::draw(){
	
	glTranslated((GLfloat)(_x),(GLfloat)(_y),0);
	glPushMatrix();

	
	glPopMatrix();
	this->drawChilds();
	
}
UISocket::~UISocket() {
}

