/* 
 * File:   UIBaseFrame.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:15
 */

#include "UIBaseFrame.h"

UIBaseFrame::UIBaseFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height) {
	_parrent = parrent;
	_x = x;
	_y = y;
	_wight = wight;
	_height = height;
}

void UIBaseFrame::draw(){
	this->drawChilds();
}
void UIBaseFrame::drawChilds(){
	for(list<UIBaseFrame*>::iterator it = _childs.begin(); it != _childs.end();it++){
		glPushMatrix();
		(*it)->draw();
		glPopMatrix();
	}
}

uint32_t UIBaseFrame::click(uint32_t x, uint32_t y){
	return clickChilds(x,y);
}

uint32_t UIBaseFrame::clickChilds(uint32_t x, uint32_t y){
	for(list<UIBaseFrame*>::reverse_iterator it = _childs.rbegin(); it != _childs.rend();it++){
		if(x-_x >= (*it)->getX() && x-_x <= (*it)->getX()+(*it)->_wight && y-_y >= (*it)->getY() && y-_y <= (*it)->getY()+(*it)->_height){
			uint32_t result = (*it)->click(x-_x,y-_y);
			if (result)
				return result;
		}
	}
	return 0;
}


UIBaseFrame::~UIBaseFrame() {
}

