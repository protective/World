/* 
 * File:   ShaderProgram.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 21:27
 */

#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(uint32_t programType) {
	_id = glCreateProgram();
	ExitOnGLError("ERROR: Could not create the shader program");
	if(programType == 1){
		getShaders()[0] = new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER);
		getShaders()[1] = new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER);
	}else if(programType == 2){
		getShaders()[0] = new Shader("../../../Grafic/Shaders/UIVertexShader.glsl", GL_VERTEX_SHADER);
		getShaders()[1] = new Shader("../../../Grafic/Shaders/UIFragmentShader.glsl", GL_FRAGMENT_SHADER);
	
	}
	glBindAttribLocation(_id,0, "in_Position");
	glBindAttribLocation(_id,1, "in_Texcoord");
	ExitOnGLError("ERROR: Could not bind attri");
	
	
	glAttachShader(_id, getShaders()[1]->getId());
	glAttachShader(_id, getShaders()[0]->getId());
	
	glLinkProgram(_id);
	GLint result;
	glGetProgramiv(_id,GL_LINK_STATUS,&result);
	if (result)
		cerr<<"SHADER LINKING OK"<<endl;
	else
		cerr<<"SHADER LINKING ERROR"<<endl;
	ExitOnGLError("ERROR: Could not link the shader program");
	
	ExitOnGLError("ERROR: Could not get the shader uniform locations");

	if(programType == 1){
		getShaders()[0]->bindvars(_id,ShaderModelMatrix,"ModelMatrix");
		getShaders()[0]->bindvars(_id,ShaderViewMatrix,"ViewMatrix");
		getShaders()[0]->bindvars(_id,ShaderProjectionMatrix,"ProjectionMatrix");
	}else if(programType == 2){
		getShaders()[0]->bindvars(_id,ShaderModelMatrix,"ModelMatrix");
		getShaders()[0]->bindvars(_id,ShaderProjectionMatrix,"ProjectionMatrix");
	}
	_textureUniform = glGetUniformLocation(_id,"mytexture");
}

ShaderProgram::~ShaderProgram() {
}

