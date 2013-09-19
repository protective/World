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

	if(!ShaderProgram::init())
		return 1;
	
	if(!addShader(new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(!addShader(new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER)))
		return 3;
	
	if(!finalize())
		return 4;
	
	_ModelMatrix = getUniformLocation("ModelMatrix");
	_ViewMatrix = getUniformLocation("ViewMatrix");
	_ProjectionMatrix = getUniformLocation("ProjectionMatrix");	
	return 0;
}




ObjectShader::~ObjectShader() {
}

