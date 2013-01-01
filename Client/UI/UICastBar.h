/* 
 * File:   UICastBar.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:33
 */

#ifndef UICASTBAR_H
#define	UICASTBAR_H

#include "UIBaseFrame.h"

class CCreature;
class UICastBar : public UIBaseFrame {
public:
	UICastBar(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height,CCreature* creature);
	virtual void draw();
	virtual ~UICastBar();
private:
	CCreature* _creature;
};

#endif	/* UICASTBAR_H */

