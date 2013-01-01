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
	for(list<UIBaseFrame*>::iterator it = _childs.begin(); it != _childs.end();it++){
		(*it)->draw();
	}
}

UIBaseFrame::~UIBaseFrame() {
}

