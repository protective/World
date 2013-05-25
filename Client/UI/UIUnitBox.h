/* 
 * File:   UIUnitBox.h
 * Author: karsten
 *
 * Created on 20. april 2013, 20:26
 */

#ifndef UIUNITBOX_H
#define	UIUNITBOX_H
#include "UIBaseFrame.h"
class CCreature;
class UIUnitBox : public UIBaseFrame  {
public:
    UIUnitBox(UIBaseFrame* parrent,CCreature* creature, uint32_t x, uint32_t y);
    virtual void draw();
	virtual ~UIUnitBox();
private:
	CCreature* _creature;
};

#endif	/* UIUNITBOX_H */

