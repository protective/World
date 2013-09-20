/* 
 * File:   UIAbilityBox.cpp
 * Author: karsten
 * 
 * Created on 26. februar 2013, 21:56
 */

#include "UIAbilityBox.h"
#include "../Powers/CPower.h"
#include "TransformStack.h"
#include "../Grafic/screenControler.h"

UIAbilityBox::UIAbilityBox(UIBaseFrame* parrent, uint32_t x, uint32_t y, CCreature* creature, CPower* power) :
UIBaseFrame(parrent,x,y,parrent->getWight(),parrent->getHeight()){
	
	this->_creature = creature;
	_power = power;
	setIcon(power->getIconId());
	
	
}

uint32_t UIAbilityBox::click(uint32_t x, uint32_t y){
	cerr<<"click abi"<<endl;
	if(_power){
		_power->activate(playerTarget);
		return 1;
	}
	return 0;
}

void UIAbilityBox::draw(){
	glm::translate(*masterScreen->getUIStack()->top(),glm::vec3(getX(),getY(),0));
	if(this->_power){
		masterScreen->getUIStack()->push();
		
		masterScreen->getUIShaderProgram()->enable();
		masterScreen->getUIShaderProgram()->setModelMatrix(masterScreen->getUIStack()->top());
		this->bind();
		glDrawArrays(GL_TRIANGLE_FAN,0,4);
		ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
		this->unbind();
		
		masterScreen->getUIStack()->pop();
	}
	this->drawChilds();
}


UIAbilityBox::~UIAbilityBox() {
}

