/* 
 * File:   ObjectShader.cpp
 * Author: karsten
 * 
 * Created on 19. september 2013, 19:41
 */

#include "ObjectShader.h"

ObjectShader::ObjectShader() {
}


uint32_t ObjectShader::init(){
	cerr<<"INIT OBJECT SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER)))
		return 3;
	
	if(finalize())
		return 4;
	
	_ModelMatrix = getUniformLocation("ModelMatrix");
	_ViewMatrix = getUniformLocation("ViewMatrix");
	_ProjectionMatrix = getUniformLocation("ProjectionMatrix");	
	return 0;
}

void ObjectShader::setModelMatrix(glm::mat4* modelMatrix){
	glUniformMatrix4fv(_ModelMatrix, 1, GL_FALSE, (glm::value_ptr(*modelMatrix)));
}
void ObjectShader::setViewMatrix(glm::mat4* viewMatrix){
	glUniformMatrix4fv(_ViewMatrix, 1, GL_FALSE, (glm::value_ptr(*viewMatrix)));
}
void ObjectShader::setProjectionMatrix(glm::mat4* projectionMatrix){
	glUniformMatrix4fv(_ProjectionMatrix, 1, GL_FALSE, (glm::value_ptr(*projectionMatrix)));
}



ObjectShader::~ObjectShader() {
}

