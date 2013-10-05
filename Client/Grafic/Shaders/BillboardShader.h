/* 
 * File:   BillboardShader.h
 * Author: karsten
 *
 * Created on 20. september 2013, 23:32
 */

#ifndef BILLBOARDSHADER_H
#define	BILLBOARDSHADER_H
#include "../ShaderProgram.h"

class BillboardShader : public ShaderProgram {
public:
	BillboardShader();
	uint32_t init();
	
    void SetVP(glm::mat4* VP);
    void SetCameraPosition(glm::vec3* Pos);
	virtual ~BillboardShader();
private:
    GLuint _VPLocation;
    GLuint _cameraPosLocation;
};

#endif	/* BILLBOARDSHADER_H */

