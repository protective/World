/* 
 * File:   UIMainFrame.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:15
 */

#ifndef UIMAINFRAME_H
#define	UIMAINFRAME_H

#include "UIBaseFrame.h"
#include "UICastBar.h"
#include "UISocket.h"
#include "UIUnitBox.h"


class UIMainFrame : public UIBaseFrame {
public:
	UIMainFrame();
        void updateUI();
        virtual uint32_t click(uint32_t x, uint32_t y);
        map<uint32_t, UISocket* >& getSockets(){return _sockets;}
	virtual ~UIMainFrame();
private:

    UICastBar* _castbar;
	UIUnitBox* _playerBox;
    map<uint32_t, UISocket* > _sockets;
};

#endif	/* UIMAINFRAME_H */

