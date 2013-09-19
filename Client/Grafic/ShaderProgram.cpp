/* 
 * File:   ShaderProgram.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 21:27
 */

#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(uint32_t programType) {
	/*
	//_id = glCreateProgram();
	//ExitOnGLError("ERROR: Could not create the shader program");
	if(programType == 1){
		//getShaders()[0] = new Shader("../../../Grafic/Shaders/ObjVertexShader.glsl", GL_VERTEX_SHADER);
		//getShaders()[1] = new Shader("../../../Grafic/Shaders/ObjFragmentShader.glsl", GL_FRAGMENT_SHADER);
	}else if(programType == 2){
		//getShaders()[0] = new Shader("../../../Grafic/Shaders/UIVertexShader.glsl", GL_VERTEX_SHADER);
		//getShaders()[1] = new Shader("../../../Grafic/Shaders/UIFragmentShader.glsl", GL_FRAGMENT_SHADER);
	
	}
	//glBindAttribLocation(_id,0, "in_Position");
	//glBindAttribLocation(_id,1, "in_Texcoord");
	//ExitOnGLError("ERROR: Could not bind attri");
	
	
	//glAttachShader(_id, getShaders()[1]->getId());
	//glAttachShader(_id, getShaders()[0]->getId());
	
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

	 * */
}

uint32_t ShaderProgram::init(){
	_id = glCreateProgram();
	if(!_id){
		ExitOnGLError("ERROR: Could not create the shader program");
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
		return 0;
	}else
		cerr<<"SHADER LINKING ERROR"<<endl;
	ExitOnGLError("ERROR: Could not link the shader program");
	return 1;
}

void ShaderProgram::enable()
{
    glUseProgram(m_shaderProg);
}


GLint ShaderProgram::getUniformLocation(const char* pUniformName)
{
    GLuint Location = glGetUniformLocation(m_shaderProg, pUniformName);

    if (Location == INVALID_OGL_VALUE) {
        fprintf(stderr, "Warning! Unable to get the location of uniform '%s'\n", pUniformName);
    }

    return Location;
}

GLint ShaderProgram::getProgramParam(GLint param)
{
    GLint ret;
    glGetProgramiv(m_shaderProg, param, &ret);
    return ret;
}

ShaderProgram::~ShaderProgram() {
}

