/* 
 * File:   UIPrimShader.h
 * Author: karsten
 *
 * Created on 21. september 2013, 01:16
 */

#ifndef UIPRIMSHADER_H
#define	UIPRIMSHADER_H

#include "../ShaderProgram.h"

class UIPrimShader : public ShaderProgram {
public:
	UIPrimShader();
	uint32_t init();
	void setModelMatrix(glm::mat4* modelMatrix);
	void setProjectionMatrix(glm::mat4* projectionMatrix);	
	void setColor(glm::vec4* Color);
	virtual ~UIPrimShader();
private:
	GLuint _ModelMatrix;
	GLuint _ProjectionMatrix;
	GLuint _Color;
};

#endif	/* UIPRIMSHADER_H */

