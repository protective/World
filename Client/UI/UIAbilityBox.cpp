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
	TranslateMatrix(masterScreen->getUIStack()->top(),getX(),getY(),0);
	if(this->_power){
		masterScreen->getUIStack()->push();
		glUseProgram(masterScreen->getUIShaderProgram()->getProgramId());
		ExitOnGLError("ERROR: Could not use the shader program");
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);
		glUniform1i(masterScreen->getUIShaderProgram()->getTextureUniform(), /*GL_TEXTURE*/0);
		ExitOnGLError("ERROR: Could not set the shader texture uniforms");
		
		glUniformMatrix4fv(masterScreen->getUIShaderProgram()->getShaders()[0]->getVars()[ShaderModelMatrix], 1, GL_FALSE, masterScreen->getUIStack()->top()->m);
		//glUniformMatrix4fv(masterScreen->getUIShaderProgram()->getShaders()[0]->getVars()[ShaderModelMatrix], 1, GL_FALSE, IDENTITY_MATRIX.m);
		ExitOnGLError("ERROR: Could not set the shader uniforms");
		glBindVertexArray(_vao);
		ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
		glDrawArrays(GL_TRIANGLE_FAN,0,4);
		ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
		glBindVertexArray(0);
		glUseProgram(0);
		masterScreen->getUIStack()->pop();
	}
	this->drawChilds();
}


UIAbilityBox::~UIAbilityBox() {
}

