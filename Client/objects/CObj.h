/* 
 * File:   GObj.h
 * Author: karsten
 *
 * Created on 15. maj 2011, 21:23
 */

#ifndef COBJ_H
#define	COBJ_H
#include "../CFunctions.h"
#include "CPos.h"
#include "../GLutil.h"
class CCreature;
class CObj {
public:
	CObj(uint32_t id, uint32_t playerId, CPos pos);
	virtual CPos& getPos();
	virtual glm::vec3 getGraficPos();
	virtual CPos& getActualPos(){return _actualPos;}
	virtual void setPos(CPos pos){_pos = pos;}
	void MovePos(int32_t x, int32_t y);
	virtual void ResivePosUpdate(CPos& pos, uint32_t btime, uint32_t etime);
	uint32_t getId(){return this->_id;}
	virtual void Proces(uint32_t DTime);
	virtual uint32_t getSize(){return 0;}
	virtual void announceRemovalOf(CObj* obj){};
	virtual bool canBeRemoved(){return false;}
	virtual bool isDead(){return false;}
	virtual uint8_t getTeam(){return _team;}
	virtual uint32_t getPlayerId(){return _playerId;}
	virtual CCreature* getCreature(){return NULL;}
	virtual ~CObj();
protected:
	uint32_t _id;
	uint32_t _playerId;
	int32_t _team;
	uint32_t _lastUpdate;
	uint32_t _procedTime;
	uint32_t _etime;
	CPos _pos;
	CPos _actualPos;
	int16_t _fadetimer;
	int16_t _maxfadetimer;
	float _moveX , _moveY;
};

typedef map<uint32_t,CObj*>::iterator CobjI;

#endif	/* COBJ_H */

