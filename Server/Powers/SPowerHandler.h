/* 
 * File:   SPowerHandler.h
 * Author: karsten
 *
 * Created on 1. november 2012, 20:41
 */

#ifndef SPOWERHANDLER_H
#define	SPOWERHANDLER_H
#include "../SFunctions.h"
#include "SPower.h"

class SPowerHandler {
public:
	SPowerHandler();
	virtual ~SPowerHandler();
private:
	map<uint32_t , SPower*> _powers;
};

#endif	/* SPOWERHANDLER_H */

