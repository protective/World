/* 
 * File:   UIMainFrame.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:15
 */

#ifndef UIMAINFRAME_H
#define	UIMAINFRAME_H

#include "UIBaseFrame.h"


class UIMainFrame : public UIBaseFrame {
public:
	UIMainFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height);
	virtual ~UIMainFrame();
private:

};

#endif	/* UIMAINFRAME_H */

