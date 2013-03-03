/* 
 * File:   UISocket.h
 * Author: karsten
 *
 * Created on 3. marts 2013, 16:40
 */

#ifndef UISOCKET_H
#define	UISOCKET_H
#include "UIBaseFrame.h"
#include "UIAbilityBox.h"

class UISocket : public UIBaseFrame {
public:
    UISocket(UIBaseFrame* parrent, uint32_t x, uint32_t y);
    uint32_t drop(UIAbilityBox* abilityBox);
    virtual void draw();
    
    virtual uint32_t click(uint32_t x, uint32_t y);
    virtual ~UISocket();
private:
        UIAbilityBox* _abilityBox;
};

#endif	/* UISOCKET_H */

