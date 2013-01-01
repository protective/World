/* 
 * File:   CObjHandler.h
 * Author: karsten
 *
 * Created on 1. januar 2013, 19:53
 */

#ifndef COBJHANDLER_H
#define	COBJHANDLER_H
#include "CFunctions.h"
class CObjHandler {
public:
	CObjHandler();
	virtual ~CObjHandler();
private:
	map<uint32_t,CObj*> _objects;
};

#endif	/* COBJHANDLER_H */

