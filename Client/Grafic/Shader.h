/* 
 * File:   Shader.h
 * Author: karsten
 *
 * Created on 9. juni 2013, 21:10
 */

#ifndef SHADER_H
#define	SHADER_H
#include "../GLutil.h"
#include "../CFunctions.h"
enum shaderVars{
	ShaderModelMatrix,
	ShaderViewMatrix,
	ShaderProjectionMatrix
};
class Shader {
public:
	Shader(const char* filename, GLenum shaderType);
	
	map<shaderVars, GLuint>& getVars(){return _vars;}
	GLuint getId(){return _shaderid;}
	void setId(GLuint id){_shaderid = id;}
	void bindvars(GLuint programID, shaderVars var, string name);
	virtual ~Shader();
private:
	
	GLuint _shaderid;
	map<shaderVars, GLuint> _vars;
};

#endif	/* SHADER_H */

