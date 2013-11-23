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
CGraficObject::CGraficObject(CObj* obj,Model* model) {
	_model = model;
	CubeRotation = 0;
	_obj = obj;
	_effects[1] = NULL;
	
	//cerr<<"ADD EFP"<<endl;

		
}

void CGraficObject::draw(CCreature* creature){
	glm::mat4 modelMatrix = glm::mat4() ;
	CPos* pos = &creature->getPos();

	//model translate and rotate
	modelMatrix = glm::translate(modelMatrix, glm::vec3((float)pos->x/1000,(float)pos->y/1000,(float)pos->z/1000));
	modelMatrix = glm::rotate(modelMatrix,((float)pos->d)/100,glm::vec3(0,0,1));
	_model->getShader()->enable(); //enable object shader
	_model->bind(); //bind this model for rendering

	//set object specific variables for drawing
	_model->getShader()->setModelMatrix(&modelMatrix);
	_model->getShader()->setViewMatrix(masterScreen->getCamera()->getViewMatrix());
	
	//draw
	glDrawElements(GL_TRIANGLES, _model->getIndicesCount(), GL_UNSIGNED_INT, (void*)0);
	ExitOnGLError("ERROR: Could not draw the cube");

	_model->unbind();
	
	
	//draw all assosiated particalsystems
	for(map<uint32_t, GraficEffectPlayer*>::iterator it = _effects.begin(); it != _effects.end(); it++){
		if(it->second)
			it->second->draw(masterScreen->getCamera());

	}
	

	
}


void CGraficObject::rayIntersect(CCreature* creature, glm::mat2x3 ray){

	//CPos* pos = ;
	
	glm::vec3 pos(creature->getPos().x/1000, creature->getPos().y/1000, creature->getPos().z/1000);

	glm::vec3 center =  pos;

	this->_radiusSquared = 16;
	
	float squaredDist = glm::dot(ray[0]-center, ray[0]-center);

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
	
	
	if(d >= 0){
		cerr<<"Click "<<creature->getId()<<endl;
		playerTarget = creature;
		/*
		float distance = centerDirectionDot - sqrt(d);
		if(0 < distance && distance < computation.distance){
			computation.distance = distance;
			computation.surface = this;
		}
		*/
	}
	
}


void CGraficObject::ProcesGrafic(uint32_t DTime){

	//update all partical systems
	for(map<uint32_t, GraficEffectPlayer*>::iterator it = _effects.begin(); it != _effects.end(); it++){
		if(it->second)
			it->second->Proces(DTime);
	}

}

void CGraficObject::AddEffectPlayer(uint32_t id){
	cerr<<"begin add EP"<<endl;
	GraficEffectType* effectdata = masterScreen->getEffectData(id);
	if (!effectdata){
		cerr<<"ERROR CGraficObject::AddEffectPlayer no effect data"<<endl;
		return;
	}
	cerr<<"new GEP"<<endl;
	if(_effects.find(id) == _effects.end() || _effects[id] == NULL)
		_effects[id] = new GraficEffectPlayer(_obj->getCreature(),effectdata);
	_effects[id]->incRef();
	
	cerr<<"done add EP"<<endl;
	
}
void CGraficObject::RemoveEffectPlayer(uint32_t id){
	
	GraficEffectPlayer* eplayer = _effects.find(id) != _effects.end() ? _effects[id] : NULL;
	cerr<<"RM EP"<<eplayer<<" unitid "<<_obj->getId()<<endl;
	if(eplayer){
		eplayer->decRef();
		if(eplayer->refZero()){
			eplayer->signal(GEP::Term);

		}
		if(eplayer->canBeRemoved()){
			delete eplayer;
			_effects.erase(id);
		}
	}
}

CGraficObject::~CGraficObject() {
}

