/* 
 * File:   UIUnitBox.cpp
 * Author: karsten
 * 
 * Created on 20. april 2013, 20:26
 */

#include "UIUnitBox.h"
#include "../objects/CCreature.h"
#include "../Grafic/screenControler.h"
UIUnitBox::UIUnitBox(UIBaseFrame* parrent,CCreature* creature, uint32_t x, uint32_t y):
UIBaseFrame(parrent,x,y,200,60) {
	_creature = creature;
	_hpBar = new UIPrimitiveBox(this,0,0,0,10,glm::vec4(1,0,0,1));
	_manaBar = new UIPrimitiveBox(this,0,12,0,10,glm::vec4(0,0,1,1));
	_EnergyBar = new UIPrimitiveBox(this,0,24,0,10,glm::vec4(0,1,0,1));
	_Bagground = new UIPrimitiveBox(this,0,00,200,60,glm::vec4(1,1,1,1));
	
	this->addChild(_EnergyBar);
	this->addChild(_hpBar);
	this->addChild(_manaBar);
	this->addChild(_Bagground);
}


void UIUnitBox::draw(){
	masterScreen->getUIStack()->translate(glm::vec3(getX(),getY(),0));
	
	float php = 0;
	if(_creature->getAttibute()[Attributes::HpMax]){
		int32_t maxhp = _creature->getAttibute()[Attributes::HpMax];
		int32_t hp = _creature->getAttibute()[Attributes::Hp];
		php =  ((float)hp / maxhp);
	}else{
		php = (float)_creature->getAttibute()[Attributes::HpP]/100;
	}
	float pmana = 0;
	if(_creature->getAttibute()[Attributes::ManaMax]){
		int32_t maxmana = _creature->getAttibute()[Attributes::ManaMax];
		int32_t mana = _creature->getAttibute()[Attributes::Mana];
		pmana = ((float)mana / maxmana); 
	}else{
		pmana = (float)_creature->getAttibute()[Attributes::ManaP]/100;
	}


	float pfocus = 0;
	if(_creature->getAttibute()[Attributes::FocusMax]){
		int32_t maxfocus = _creature->getAttibute()[Attributes::FocusMax];
		int32_t focus = _creature->getAttibute()[Attributes::Focus];
		pfocus = ((float)focus / maxfocus); 
	}else{	
		pfocus = (float)_creature->getAttibute()[Attributes::FocusP]/100;
	}
	
	_hpBar->setWight(float(getWight()) * (php));
	_manaBar->setWight(float(getWight()) * (pmana));
	_EnergyBar->setWight(float(getWight()) * (pfocus));

	this->drawChilds();	

}

UIUnitBox::~UIUnitBox() {
}

