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
class CCreature;
class CPower;
class CPlayerObjHandle {
public:
	CPlayerObjHandle();
	void recPower(SerialPower* st);
	void recCreature(SerialCreature* st);
        void recBeginCast(SerialBeginCast* st);
        void recCast(SerialCast* st);
        void ServerReqActivatePower(CPower* power, CObj* target);
        CObj* selectObject(int32_t x, int32_t y);
        CCreature* player(){return _player;}
	map<uint32_t,CObj*>& getObjs();
private:
	map<uint32_t,CObj*> _objs;
        CCreature* _player;
};

#endif	/* CPLAYEROBJHANDLE_H */

