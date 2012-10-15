/* 
 * File:   CPlayerObjHandle.h
 * Author: karsten
 *
 * Created on 22. maj 2011, 15:32
 */

#ifndef CPLAYEROBJHANDLE_H
#define	CPLAYEROBJHANDLE_H
#include "CFunctions.h"


class CPos;
class CObj;
class CPlayerObjHandle {
public:
	CPlayerObjHandle();

	map<uint32_t,CObj*>& getObjs();
private:
	map<uint32_t,CObj*> objs;
};

#endif	/* CPLAYEROBJHANDLE_H */

