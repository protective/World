/* 
 * File:   ShaderProgram.h
 * Author: karsten
 *
 * Created on 9. juni 2013, 21:27
 */

#ifndef SHADERPROGRAM_H
#define	SHADERPROGRAM_H
#include "../CFunctions.h"
#include "../GLutil.h"
#include "Shader.h"
class ShaderProgram {
public:
	ShaderProgram();
	map<int32_t,Shader*>& getShaders(){return _shaders;}
	GLuint getProgramId(){return _id;}
	GLint& getTextureUniform(){return _textureUniform;}
	void setId(GLuint id){_id = id;}
	virtual ~ShaderProgram();
private:
	map<int32_t,Shader*> _shaders;
	GLuint _id;
	GLint _textureUniform;
};

#endif	/* SHADERPROGRAM_H */

