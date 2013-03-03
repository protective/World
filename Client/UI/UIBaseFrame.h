/* 
 * File:   UIBaseFrame.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:15
 */

#ifndef UIBASEFRAME_H
#define	UIBASEFRAME_H
#include "../CFunctions.h"
#include "../Grafic/Grafic.h"
class UIBaseFrame {
public:
	UIBaseFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height);
	virtual void draw();
	virtual void drawChilds();
        void addChild(UIBaseFrame* frame){
            _childs.push_back(frame);
        }
        void removeChild(UIBaseFrame* frame){
            _childs.remove(frame);
        }
	virtual uint32_t click(uint32_t x, uint32_t y);
        virtual uint32_t clickChilds(uint32_t x, uint32_t y);
	list<UIBaseFrame*>& getChilds(){return _childs;}
        virtual uint32_t getX(){return _x;}
        virtual uint32_t getY(){return _y;}
        virtual uint32_t getWight(){return _wight;}
        virtual uint32_t getHeight(){return _height;}
	virtual ~UIBaseFrame();
protected:
	UIBaseFrame* _parrent;
	list<UIBaseFrame*> _childs;
	uint32_t _x;
	uint32_t _y;
	uint32_t _wight;
	uint32_t _height;
};

#endif	/* UIBASEFRAME_H */

