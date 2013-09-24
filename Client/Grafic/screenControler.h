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
#include "Shaders/UIShader.h"
#include "Shaders/UIPrimShader.h"

class screenControler {
public:
	screenControler();
	void initScreen();
	void drawScreen();
	void clickScreen(uint32_t x, uint32_t y);
	list<Model*>& getModels(){return _models;}
	glm::mat4* getViewMatrix(){return &_viewMatrix;}
	UIShader* getUIShaderProgram(){return _UIShaderProgram;}
	UIPrimShader* getUIPrimShaderProgram(){return _UIPrimShader;}
	TransformStack* getUIStack(){return &_UIStack;}
	virtual ~screenControler();
private:
	list<Model*> _models;
	SDL_Surface* _screen;
	ObjectShader* _ObjShaderProgram;
	UIShader* _UIShaderProgram;
	UIPrimShader* _UIPrimShader;
	glm::mat4 _projectionMatrix;
	glm::mat4 _viewMatrix;
	TransformStack _UIStack;
};

#endif	/* SCREENCONTROLER_H */

