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

	glm::mat4 modelMatrix = glm::mat4() ;

	float CubeAngle;
	clock_t Now = clock();

	CubeRotation += 1;
	CubeAngle = DegreesToRadians(CubeRotation);

	CPos* pos = &creature->getPos();

	//RotateAboutZ(&ModelMatrix, DegreesToRadians((360-pos->d)/100));
	//TranslateMatrix(&ModelMatrix,(float)pos->x/1000,(float)pos->y/1000,(float)pos->z/1000);
	
	//glUseProgram(_model->getShader()->getProgramId());
	_model->getShader()->enable(); //enable object shader
	_model->bind(); //bind this model for rendering

	//set object specific variables for drawing
	_model->getShader()->setModelMatrix(&modelMatrix);
	_model->getShader()->setViewMatrix(masterScreen->getViewMatrix());
	
	//draw
	glDrawElements(GL_TRIANGLES, _model->getIndicesCount(), GL_UNSIGNED_INT, (void*)0);
	ExitOnGLError("ERROR: Could not draw the cube");

	_model->unbind();
	
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

