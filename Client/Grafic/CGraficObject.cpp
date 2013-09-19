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
#include "../objects/CCreature.h"
CGraficObject::CGraficObject(Model* model) {
	_model = model;
	CubeRotation = 0;
}

void CGraficObject::draw(CCreature* creature){
//glDisable(GL_TEXTURE_2D);

Matrix ModelMatrix;

	
	
	float CubeAngle;
	clock_t Now = clock();

	CubeRotation += 1;
	CubeAngle = DegreesToRadians(CubeRotation);

	ModelMatrix = IDENTITY_MATRIX;
	CPos* pos = &creature->getPos();
	//RotateAboutY(&ModelMatrix, CubeAngle);
	//cerr<<pos->x<<endl;
	RotateAboutZ(&ModelMatrix, DegreesToRadians((360-pos->d)/100));
	TranslateMatrix(&ModelMatrix,(float)pos->x/1000,(float)pos->y/1000,(float)pos->z/1000);

	//cerr<<"program "<<_model->getShader()->getProgramId()<<endl;
	glUseProgram(_model->getShader()->getProgramId());
	
	
	//Drawbox(-0.1,0,0.1,0.1,0,1,1,1);
	
	ExitOnGLError("ERROR: Could not use the shader program");

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model->get_texture());
	glUniform1i(_model->getShader()->getTextureUniform(), /*GL_TEXTURE*/0);
	ExitOnGLError("ERROR: Could not set the shader texture uniforms");

	glUniformMatrix4fv(_model->getShader()->getShaders()[0]->getVars()[ShaderModelMatrix], 1, GL_FALSE, ModelMatrix.m);
	glUniformMatrix4fv(_model->getShader()->getShaders()[0]->getVars()[ShaderViewMatrix], 1, GL_FALSE, (glm::value_ptr(*masterScreen->getViewMatrix())));
	ExitOnGLError("ERROR: Could not set the shader uniforms");

	glBindVertexArray(_model->get_vao());
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");

	glDrawElements(GL_TRIANGLES, _model->getIndicesCount(), GL_UNSIGNED_INT, (void*)0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
	
	ExitOnGLError("ERROR: Could not draw the cube");
	//cerr<<"draw vao "<<_model->get_vao()<<" "<<_model->getIndicesCount()<<endl;
	glBindVertexArray(0);
	glUseProgram(0);
//	glEnable(GL_TEXTURE_2D);
}


void CGraficObject::rayIntersect(CCreature* creature, glm::mat2x3 ray){

	//CPos* pos = ;
	
	glm::vec3 pos(creature->getPos().x/1000, creature->getPos().y/1000, creature->getPos().z/1000);
	
	cerr<<"pos "<<pos.x<<endl;
	cerr<<"pos "<<pos.y<<endl;
	cerr<<"pos "<<pos.z<<endl;
	
	glm::vec3 center =  pos;
	
	cerr<<"posray "<<ray[0].x<<endl;
	cerr<<"posray "<<ray[0].y<<endl;
	cerr<<"posray "<<ray[0].z<<endl;
	/*
	float centerDirectionDot = glm::dot(ray[1],center);

	
	cerr<<"r "<<this->_radiusSquared<<endl;
	//Compute determinat
	float d = centerDirectionDot*centerDirectionDot - glm::sqrt(center.length()) + this->_radiusSquared;
	cerr<<"d "<<d<<endl;
	//Check for intersection
	*/
	this->_radiusSquared = 100;
	
	float squaredDist = glm::dot(ray[0]-center, ray[0]-center);

	
	cerr<<"disttance "<<squaredDist<<endl;
	//If the distance is less than the squared radius of the sphere...
	if(squaredDist <= this->_radiusSquared )
	{
		//Point is in sphere, consider as no intersection existing
		//std::cout << "Point inside sphere..." << std::endl;
		//return false;
	}

	//Will hold solution to quadratic equation
	float t0, t1;

	//Calculating the coefficients of the quadratic equation
	float a = glm::dot(ray[1],ray[1]); // a = d*d
	float b = 2.0f*glm::dot(ray[1],ray[0]-center); // b = 2d(o-C)
	float c = glm::dot(ray[0]-center, ray[0]-center) - this->_radiusSquared ; // c = (o-C)^2-R^2

	//Calculate discriminant
	float d = (b*b)-(4.0f*a*c);
	
	
	
	
	
	cerr<<"d "<<d<<endl;
	if(d >= 0){
		cerr<<"HIT "<<endl;
		/*
		float distance = centerDirectionDot - sqrt(d);
		if(0 < distance && distance < computation.distance){
			computation.distance = distance;
			computation.surface = this;
		}
		*/
	}
	
}

CGraficObject::~CGraficObject() {
}

