/* 
 * File:   CGraficObject.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 19:15
 */

#include "CGraficObject.h"

CGraficObject::CGraficObject(Model* model) {
	_model = Model;
	CubeRotation = 0;
}

void CGraficObject::draw(){
	float CubeAngle;
	clock_t Now = clock();

	CubeRotation += 1;
	CubeAngle = DegreesToRadians(CubeRotation);

	ModelMatrix = IDENTITY_MATRIX;
	RotateAboutY(&ModelMatrix, CubeAngle);
	RotateAboutX(&ModelMatrix, CubeAngle);

	glUseProgram(ShaderIds[0]);
	ExitOnGLError("ERROR: Could not use the shader program");

	glUniformMatrix4fv(ModelMatrixUniformLocation, 1, GL_FALSE, ModelMatrix.m);
	glUniformMatrix4fv(ViewMatrixUniformLocation, 1, GL_FALSE, ViewMatrix.m);
	ExitOnGLError("ERROR: Could not set the shader uniforms");

	glBindVertexArray(BufferIds[0]);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (GLvoid*)0);
	ExitOnGLError("ERROR: Could not draw the cube");

	glBindVertexArray(0);
	glUseProgram(0);
}

CGraficObject::~CGraficObject() {
}

