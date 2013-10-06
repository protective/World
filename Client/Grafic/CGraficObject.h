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
class CCreature;
class CGraficObject {
public:
	CGraficObject(Model* model);
	virtual void draw(CCreature* creature);
	virtual void rayIntersect(CCreature* creature, glm::mat2x3 ray);
	virtual ~CGraficObject();
protected:
	Model* _model;
	GLuint _buffer;
	float CubeRotation;
	float _radiusSquared;
	list<ParticalSystem*> _particalSystems;
};

#endif	/* CGRAFICOBJECT_H */

