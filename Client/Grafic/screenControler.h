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
#include "Camera.h"
#include "ParticalSystems/ParticalEngine.h"
#include "GraficEffectType.h"
#include "TextureControler.h"
class screenControler {
public:
	screenControler();
	void initScreen();
	void drawScreen();
	void clickScreen(uint32_t x, uint32_t y);
        void keydown(SDLKey key);
        void mouseDown();
        void mouseMove(int32_t x, int32_t y);
        void mouseUp(uint32_t x, uint32_t y);
        list<Model*>& getModels(){return _models;}
	Camera* getCamera(){return _camera;}
	UIShader* getUIShaderProgram(){return _UIShaderProgram;}
	UIPrimShader* getUIPrimShaderProgram(){return _UIPrimShader;}
	TransformStack* getUIStack(){return &_UIStack;}
	ParticalEngine* _getParticalEngines(){return _particalEngine;};
	GraficEffectType* getEffectData(uint32_t id){return _effetsData.find(id) != _effetsData.end() ? _effetsData[id] : NULL;}
	TextureControler* getIconTextures(){return _iconTextures;}
	virtual ~screenControler();
private:
        bool _mouseDown;
	list<Model*> _models;
	SDL_Surface* _screen;
	ObjectShader* _ObjShaderProgram;
	UIShader* _UIShaderProgram;
	UIPrimShader* _UIPrimShader;
	glm::mat4 _projectionMatrix;
	Camera*  _camera;
	TransformStack _UIStack;
	ParticalEngine* _particalEngine;
	map<uint32_t, GraficEffectType*> _effetsData;
	TextureControler* _iconTextures;
};

#endif	/* SCREENCONTROLER_H */

