/* 
 * File:   UIPrimShader.cpp
 * Author: karsten
 * 
 * Created on 21. september 2013, 01:16
 */

#include "UIPrimShader.h"

UIPrimShader::UIPrimShader() {
}


uint32_t UIPrimShader::init() {
	cerr<<"INIT UIPrim SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/Shaders/UIPrimVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/Shaders/UIPrimFragmentShader.glsl", GL_FRAGMENT_SHADER)))
		return 3;
	
	if(finalize())
		return 4;
	_ModelMatrix = getUniformLocation("ModelMatrix");
	_ProjectionMatrix = getUniformLocation("ProjectionMatrix");
	_Color = getUniformLocation("color");	
	return 0;
}

void UIPrimShader::setModelMatrix(glm::mat4* modelMatrix){
	glUniformMatrix4fv(_ModelMatrix, 1, GL_FALSE, (glm::value_ptr(*modelMatrix)));
}

void UIPrimShader::setProjectionMatrix(glm::mat4* projectionMatrix){
	glUniformMatrix4fv(_ProjectionMatrix, 1, GL_FALSE, (glm::value_ptr(*projectionMatrix)));
}

void UIPrimShader::setColor(glm::vec4* Color){
	glUniform4f(_Color, Color->x, Color->y, Color->z, Color->w);
}

UIPrimShader::~UIPrimShader() {
}

