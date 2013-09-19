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
	ShaderProgram(uint32_t programType);
	GLuint getProgramId(){return _id;}
	GLint& getTextureUniform(){return _textureUniform;}
	virtual uint32_t init();
	void enable();
	uint32_t addShader(Shader* shader);
	virtual ~ShaderProgram();
protected:

    uint32_t finalize();
    GLint getUniformLocation(const char* pUniformName);
    GLint getProgramParam(GLint param);
	GLuint _id;
	list<Shader*> _shaders;
private:
	
	
	GLint _textureUniform;
};

#endif	/* SHADERPROGRAM_H */

