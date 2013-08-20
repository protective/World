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
#include "../UI/TransformStack.h"

class screenControler {
public:
	screenControler();
	void initScreen();
	void drawScreen();
	void clickScreen(uint32_t x, uint32_t y);
	list<Model*>& getModels(){return _models;}
	Matrix* getViewMatrix(){return &_viewMatrix;}
	ShaderProgram* getUIShaderProgram(){return _UIShaderProgram;}
	TransformStack* getUIStack(){return &_UIStack;}
	virtual ~screenControler();
private:
	list<Model*> _models;
	SDL_Surface* _screen;
	ShaderProgram* _ObjShaderProgram;
	ShaderProgram* _UIShaderProgram;
	Matrix _projectionMatrix;
	Matrix _viewMatrix;
	TransformStack _UIStack;
};

#endif	/* SCREENCONTROLER_H */

