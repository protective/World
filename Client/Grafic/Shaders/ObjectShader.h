/* 
 * File:   ObjectShader.h
 * Author: karsten
 *
 * Created on 19. september 2013, 19:41
 */

#ifndef OBJECTSHADER_H
#define	OBJECTSHADER_H
#include "../ShaderProgram.h"

class ObjectShader : public ShaderProgram {
public:
	ObjectShader();
	uint32_t init();
	void setModelMatrix(glm::mat4* modelMatrix);
	void setViewMatrix(glm::mat4* viewMatrix);
	void setProjectionMatrix(glm::mat4* projectionMatrix);
	virtual ~ObjectShader();
private:

	GLuint _ModelMatrix;
	GLuint _ViewMatrix;
	GLuint _ProjectionMatrix;
};

#endif	/* OBJECTSHADER_H */

