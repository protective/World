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
		void recStatsAbs(SerialStatsAbs* st);
		void recStatsRel(SerialStatsRel* st);
		void recTakeDmgHeal(SerialTakeDmgHeal* st);
		void recAttribute(SerialAttribute* st);
        void recCast(SerialCast* st);
        void ServerReqActivatePower(CPower* power, CObj* target);
        void ServerReqMove(CObj* obj);
        CObj* selectObject(int32_t x, int32_t y);
        void procesPlayerUnit(uint32_t deltaTime);
        CCreature* player(){return _player;}
	map<uint32_t,CObj*>& getObjs();
private:
	map<uint32_t,CObj*> _objs;
        CCreature* _player;
        uint32_t _moveCounter;
};

#endif	/* CPLAYEROBJHANDLE_H */

