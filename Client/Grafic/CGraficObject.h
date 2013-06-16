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
class CGraficObject {
public:
	CGraficObject(Model* model);
	void draw();
	virtual ~CGraficObject();
private:
	Model* _model;
	GLuint _buffer;
	float CubeRotation;
};

#endif	/* CGRAFICOBJECT_H */
