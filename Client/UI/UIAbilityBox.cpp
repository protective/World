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
	_shader = masterScreen->getUIShaderProgram();
	
	_shader->enable();
	cerr<<"load texture "<<power->getIconId()<<endl;;
	_texture = masterScreen->getIconTextures()->getTexture(_power->getIconId());

	glGenVertexArrays(1, &_vao);
	ExitOnGLError("ERROR: Could not generate the VAO");
	glBindVertexArray(_vao);
	ExitOnGLError("ERROR: Could not bind the VAO");

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	ExitOnGLError("ERROR: Could not enable vertex attributes");

	glGenBuffers(1, &_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (GL_FLOAT)*4));
	ExitOnGLError("ERROR: Could not set VAO attributes");

	glBindVertexArray(0);

	glUseProgram(0);
	
	
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
	masterScreen->getUIStack()->translate(glm::vec3(getX(),getY(),0));

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

void UIAbilityBox::bind(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glUniform1i(masterScreen->getUIShaderProgram()->getTextureUniform(), /*GL_TEXTURE*/0);
	ExitOnGLError("ERROR: Could not set the shader texture uniforms");
	glBindVertexArray(this->_vao);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
}
void UIAbilityBox::unbind(){
	glBindVertexArray(0);
	glUseProgram(0);
}


UIAbilityBox::~UIAbilityBox() {
}

