/* 
 * File:   UIShader.cpp
 * Author: karsten
 * 
 * Created on 20. september 2013, 00:15
 */

#include "UIShader.h"

UIShader::UIShader() {
}


uint32_t UIShader::init() {
	cerr<<"INIT UI SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/Shaders/UIVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/Shaders/UIFragmentShader.glsl", GL_FRAGMENT_SHADER)))
		return 3;
	
	if(finalize())
		return 4;
	cerr<<"hest1"<<endl;
	_ModelMatrix = getUniformLocation("ModelMatrix");
	cerr<<"hest2"<<endl;
	_ProjectionMatrix = getUniformLocation("ProjectionMatrix");	
	cerr<<"hest3"<<endl;
	return 0;
}

void UIShader::setModelMatrix(glm::mat4* modelMatrix){
	glUniformMatrix4fv(_ModelMatrix, 1, GL_FALSE, (glm::value_ptr(*modelMatrix)));
}

void UIShader::setProjectionMatrix(glm::mat4* projectionMatrix){
	glUniformMatrix4fv(_ProjectionMatrix, 1, GL_FALSE, (glm::value_ptr(*projectionMatrix)));
}

UIShader::~UIShader() {
}

