/* 
 * File:   SPowerType.h
 * Author: karsten
 *
 * Created on 3. november 2012, 18:40
 */

#ifndef SPOWERTYPE_H
#define	SPOWERTYPE_H
#include "../SFunctions.h"
class SObj;
class SPowerType {
public:
	SPowerType();
	virtual uint32_t activate(uint32_t time, SObj* unit, SObj* target){}
	virtual ~SPowerType();
private:

};

#endif	/* SPOWERTYPE_H */

