/* 
 * File:   CGraficObject.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 19:15
 */

#include "CGraficObject.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "screenControler.h"
CGraficObject::CGraficObject(Model* model) {
	_model = model;
	CubeRotation = 0;
}

void CGraficObject::draw(){
glDisable(GL_TEXTURE_2D);

Matrix ModelMatrix;

	
	
	float CubeAngle;
	clock_t Now = clock();

	CubeRotation += 1;
	CubeAngle = DegreesToRadians(CubeRotation);

	ModelMatrix = IDENTITY_MATRIX;
	RotateAboutY(&ModelMatrix, CubeAngle);
	RotateAboutX(&ModelMatrix, CubeAngle);
	//cerr<<"program "<<_model->getShader()->getProgramId()<<endl;
	glUseProgram(_model->getShader()->getProgramId());
	
	
	//Drawbox(-0.1,0,0.1,0.1,0,1,1,1);
	
	ExitOnGLError("ERROR: Could not use the shader program");

	//glUniformMatrix4fv(_model->getShader()->getShaders()[0]->getVars()[ShaderModelMatrix], 1, GL_FALSE, ModelMatrix.m);
	//glUniformMatrix4fv(_model->getShader()->getShaders()[0]->getVars()[ShaderViewMatrix], 1, GL_FALSE, (*masterScreen->getViewMatrix()).m);
	ExitOnGLError("ERROR: Could not set the shader uniforms");

	glBindVertexArray(_model->get_vao());
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");

	//glDrawElements(GL_TRIANGLES, _model->getIndicesCount(), GL_UNSIGNED_INT, _model->get_ibo());
	glDrawArrays(GL_TRIANGLES, 0, 6);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
	
	ExitOnGLError("ERROR: Could not draw the cube");
	//cerr<<"draw vao "<<_model->get_vao()<<" "<<_model->getIndicesCount()<<endl;
	glBindVertexArray(0);
	glUseProgram(0);
	glEnable(GL_TEXTURE_2D);
}

CGraficObject::~CGraficObject() {
}

