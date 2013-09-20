/* 
 * File:   UIShader.h
 * Author: karsten
 *
 * Created on 20. september 2013, 00:15
 */

#ifndef UISHADER_H
#define	UISHADER_H
#include "../ShaderProgram.h"

class UIShader : public ShaderProgram {
public:
	UIShader();
	uint32_t init();
	void setModelMatrix(glm::mat4* modelMatrix);
	void setProjectionMatrix(glm::mat4* projectionMatrix);
	virtual ~UIShader();
private:
	GLuint _ModelMatrix;
	GLuint _ProjectionMatrix;
};

#endif	/* UISHADER_H */

