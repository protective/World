/* 
 * File:   BillboardShader.cpp
 * Author: karsten
 * 
 * Created on 20. september 2013, 23:32
 */

#include "BillboardShader.h"

BillboardShader::BillboardShader() {
}

uint32_t BillboardShader::init(){
	cerr<<"INIT Billboard SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/Shaders/BillboardVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/Shaders/BillboardGeometryShader.glsl", GL_GEOMETRY_SHADER)))
		return 3;
	
	if(addShader(new Shader("../../../Grafic/Shaders/BillboardFragmentShader.glsl", GL_FRAGMENT_SHADER)))
		return 4;
	
	if(finalize())
		return 5;
	
	_VPLocation = getUniformLocation("gVP");
	_cameraPosLocation = getUniformLocation("gCameraPos");	
	return 0;
}

void BillboardShader::SetVP(glm::mat4* VP){
	glUniformMatrix4fv(_VPLocation, 1, GL_FALSE, (glm::value_ptr(*VP)));
}
void BillboardShader::SetCameraPosition(glm::vec3* pos){

	glUniform3f(_cameraPosLocation, pos->x, pos->y, pos->z);
}

BillboardShader::~BillboardShader() {
}


