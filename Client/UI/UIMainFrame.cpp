/* 
 * File:   UIMainFrame.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:15
 */

#include "UIMainFrame.h"
#include "../Grafic/Grafic.h"
#include "../objects/CCreature.h"

UIMainFrame::UIMainFrame():
UIBaseFrame(NULL,0,0,Basewidth,Basehight){
	_castbar = NULL;
}

void UIMainFrame::updateUI(){
	if(!_castbar && playerObj->player()){
		_castbar = new UICastBar(this,20,20,100,20,playerObj->player());
		_childs.push_back(_castbar);
	}
	if(playerObj->player()){
		for (map<uint32_t, CPower*>::iterator it = playerObj->player()->getPowers().begin(); it != playerObj->player()->getPowers().end(); it++){
			if (_sockets[it->first] == NULL){
				_sockets[it->first] = new UISocket(this,40*it->first,40);
				UIAbilityBox* abbox = new UIAbilityBox(_sockets[it->first],0,0,playerObj->player(),it->second);
				_sockets[it->first]->drop(abbox);
				_childs.push_back(_sockets[it->first]);
				cerr<<"create sockets"<<endl;
				
			}
		}
	}
}

uint32_t UIMainFrame::click(uint32_t x, uint32_t y){

	return clickChilds(x,y);
}

UIMainFrame::~UIMainFrame() {
}

