/* 
 * File:   UIUnitBox.cpp
 * Author: karsten
 * 
 * Created on 20. april 2013, 20:26
 */

#include "UIUnitBox.h"
#include "../objects/CCreature.h"
UIUnitBox::UIUnitBox(UIBaseFrame* parrent,CCreature* creature, uint32_t x, uint32_t y):
UIBaseFrame(parrent,x,y,200,60) {
	_creature = creature;
			
}


void UIUnitBox::draw(){
	glTranslated((GLfloat)(_x),(GLfloat)(_y),0);
	glPushMatrix();
	
	float php = 0;
	if(_creature->getAttibute()[Attributes::HpMax]){
		int32_t maxhp = _creature->getAttibute()[Attributes::HpMax];
		int32_t hp = _creature->getAttibute()[Attributes::Hp];
		php =  ((float)hp / maxhp);
	}else{
		php = (float)_creature->getAttibute()[Attributes::HpP]/100;
	}
	Drawbox(0,0,float(_wight) * (php),20 ,0,1,0,1);
	
	
	float pmana = 0;
	if(_creature->getAttibute()[Attributes::ManaMax]){
		int32_t maxmana = _creature->getAttibute()[Attributes::ManaMax];
		int32_t mana = _creature->getAttibute()[Attributes::Mana];
		pmana = ((float)mana / maxmana); 
	}else{
		pmana = (float)_creature->getAttibute()[Attributes::ManaP]/100;
	}
	Drawbox(0,20,float(_wight) * (pmana),20 ,0,0,1,1);


	float pfocus = 0;
	if(_creature->getAttibute()[Attributes::FocusMax]){
		int32_t maxfocus = _creature->getAttibute()[Attributes::FocusMax];
		int32_t focus = _creature->getAttibute()[Attributes::Focus];
		pfocus = ((float)focus / maxfocus); 
	}else{	
		pfocus = (float)_creature->getAttibute()[Attributes::FocusP]/100;
	}
	Drawbox(0,40,float(_wight) * (pfocus),20 ,1,1,0,1);
	Drawbox(0,0,_wight,_height ,0.9,0.9,0.9,1);	
	
	glPopMatrix();
	this->drawChilds();
}

UIUnitBox::~UIUnitBox() {
}

