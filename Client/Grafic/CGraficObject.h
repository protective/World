/* 
 * File:   CGraficObject.h
 * Author: karsten
 *
 * Created on 9. juni 2013, 19:15
 */

#ifndef CGRAFICOBJECT_H
#define	CGRAFICOBJECT_H
#include "../GLutil.h"
#include "../CFunctions.h"
#include "Model.h"
#include "ParticalSystems/ParticalSystem.h"
#include "GraficEffectPlayer.h"
class CObj;
class CCreature;
class CGraficObject {
public:
	CGraficObject(CObj*obj, Model* model);
	//virtual void addParticalsystem(uint32_t index){_particalSystems[index]= NULL;}
	virtual void draw(CCreature* creature);
	
	void ProcesGrafic(uint32_t DTime);
	virtual void rayIntersect(CCreature* creature, glm::mat2x3 ray);
	Model* getModel(){return _model;}
	virtual ~CGraficObject();
protected:
	CObj* _obj;
	void AddEffectPlayer(uint32_t id);
	void RemoveEffectPlayer(uint32_t id);
	Model* _model;
	GLuint _buffer;
	float CubeRotation;
	float _radiusSquared;
	
	map<uint32_t, GraficEffectPlayer*> _effects;
	//map<uint32_t, ParticalSystem*> _particalSystems;
};

#endif	/* CGRAFICOBJECT_H */

