/* 
 * File:   ShaderProgram.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 21:27
 */

#include "ShaderProgram.h"


ShaderProgram::ShaderProgram() {
	/*

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

	 * */
}

uint32_t ShaderProgram::init(){
	_id = glCreateProgram();
	
	ExitOnGLError("ERROR: Could not create the shader program");
	if(!_id){
		return 1;
	}
	return 0;

}
uint32_t ShaderProgram::addShader(Shader* shader){
	_shaders.push_back(shader);
	glAttachShader(_id, shader->getId());
	return 0;
}

uint32_t ShaderProgram::finalize(){
	glLinkProgram(_id);
	GLint result;
	glGetProgramiv(_id,GL_LINK_STATUS,&result);
	if (result){
		cerr<<"SHADER LINKING OK"<<endl;
		
		_textureUniform = glGetUniformLocation(_id,"mytexture");

		return 0;
	}else
		cerr<<"SHADER LINKING ERROR"<<endl;
	ExitOnGLError("ERROR: Could not link the shader program");
	
	
	return 1;
}

void ShaderProgram::enable()
{
    glUseProgram(_id);
	ExitOnGLError("ERROR: Enable program");
}


GLint ShaderProgram::getUniformLocation(const char* pUniformName)
{
    GLuint Location = glGetUniformLocation(_id, pUniformName);


    return Location;
}

GLint ShaderProgram::getProgramParam(GLint param)
{
    GLint ret;
    glGetProgramiv(_id, param, &ret);
    return ret;
}

ShaderProgram::~ShaderProgram() {
}

