/* 
 * File:   CPlayerObjHandle.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 15:32
 */


#include "CPlayerObjHandle.h"
#include "objects/CObj.h"

CPlayerObjHandle::CPlayerObjHandle() {
}

map<uint32_t,CObj*>& CPlayerObjHandle::getObjs(){
	return this->objs;
}
