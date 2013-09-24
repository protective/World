/* 
 * File:   UIAbilityBox.h
 * Author: karsten
 *
 * Created on 26. februar 2013, 21:56
 */

#ifndef UIABILITYBOX_H
#define	UIABILITYBOX_H
#include "UIBaseFrame.h"
#include "../Grafic/Shaders/UIShader.h"
class CPower;
class UIAbilityBox : public UIBaseFrame {
public:
    UIAbilityBox(UIBaseFrame* parrent, uint32_t x, uint32_t y, CCreature* creature, CPower* power);
    virtual void draw();
    void setPower(CPower* power){_power = power;}
    virtual uint32_t click(uint32_t x, uint32_t y);
    virtual ~UIAbilityBox();
private:
	virtual void bind();
	virtual void unbind();
	CCreature* _creature;
	CPower* _power;
	UIShader* _shader;
};

#endif	/* UIABILITYBOX_H */

