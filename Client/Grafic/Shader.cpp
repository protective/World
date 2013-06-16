/* 
 * File:   Shader.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 21:10
 */

#include "Shader.h"

Shader::Shader(const char* filename, GLenum shaderType) {
	_shaderid = 0;
	_shaderid = LoadShader(filename,shaderType);
	if (!_shaderid)
		cerr<<"ERROR loading shader"<<endl;
}

void Shader::bindvars(GLuint programID, shaderVars var, string name){
	//get the locationID from the shader
	_vars[var] = glGetUniformLocation(programID, name.c_str());
	ExitOnGLError("ERROR: Could not get the shader uniform locations");

}


Shader::~Shader() {
}

