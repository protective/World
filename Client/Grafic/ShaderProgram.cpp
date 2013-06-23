/* 
 * File:   ShaderProgram.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 21:27
 */

#include "ShaderProgram.h"


ShaderProgram::ShaderProgram() {
	_id = glCreateProgram();
	ExitOnGLError("ERROR: Could not create the shader program");
	getShaders()[0] = new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER);
	getShaders()[1] = new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER);
	
	glBindAttribLocation(_id,0, "in_Position");
	glBindAttribLocation(_id,1, "in_Color");
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

	getShaders()[0]->bindvars(_id,ShaderModelMatrix,"ViewMatrix");
	getShaders()[0]->bindvars(_id,ShaderViewMatrix,"ViewMatrix");
	getShaders()[0]->bindvars(_id,ShaderProjectionMatrix,"ProjectionMatrix");
}

ShaderProgram::~ShaderProgram() {
}

