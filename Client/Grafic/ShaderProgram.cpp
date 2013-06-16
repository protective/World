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

	getShaders()[0] = new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER);
	getShaders()[1] = new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER);
	glAttachShader(_id, getShaders()[0]->getId());
	glAttachShader(_id, getShaders()[1]->getId());
	glLinkProgram(_id);
	GLint result;
	glGetProgramiv(_id,GL_LINK_STATUS,&result);
	if (result)
		cerr<<"SHADER LINKING OK"<<endl;
	else
		cerr<<"SHADER LINKING ERROR"<<endl;
	ExitOnGLError("ERROR: Could not link the shader program");
	
	ExitOnGLError("ERROR: Could not get the shader uniform locations");

	getShaders()[1]->bindvars(_id,ModelMatrix,"ViewMatrix");
	getShaders()[1]->bindvars(_id,ViewMatrix,"ViewMatrix");
	getShaders()[1]->bindvars(_id,ProjectionMatrix,"ProjectionMatrix");
}

ShaderProgram::~ShaderProgram() {
}

