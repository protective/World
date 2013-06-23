/* 
 * File:   screenControler.h
 * Author: karsten
 *
 * Created on 16. juni 2013, 22:23
 */

#ifndef SCREENCONTROLER_H
#define	SCREENCONTROLER_H
#include "Grafic.h"
#include "Model.h"


class screenControler {
public:
	screenControler();
	void drawScreen();
	list<Model*>& getModels(){return _models;}
	Matrix* getViewMatrix(){return &_viewMatrix;}
	virtual ~screenControler();
private:
	list<Model*> _models;
	SDL_Surface* _screen;
	ShaderProgram* _shaderProgram;
	Matrix _projectionMatrix;
	Matrix _viewMatrix;
};

#endif	/* SCREENCONTROLER_H */

