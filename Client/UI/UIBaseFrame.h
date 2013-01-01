/* 
 * File:   UIBaseFrame.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:15
 */

#ifndef UIBASEFRAME_H
#define	UIBASEFRAME_H
#include "../CFunctions.h"

class UIBaseFrame {
public:
	UIBaseFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height);
	virtual void draw();
	virtual uint32_t click(uint32_t x, uint32_t y){}
	list<UIBaseFrame*>& getChilds(){return _childs;}
	virtual ~UIBaseFrame();
private:
	UIBaseFrame* _parrent;
	list<UIBaseFrame*> _childs;
	uint32_t _x;
	uint32_t _y;
	uint32_t _wight;
	uint32_t _height;
};

#endif	/* UIBASEFRAME_H */

