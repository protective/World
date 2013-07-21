/* 
 * File:   GObj.h
 * Author: karsten
 *
 * Created on 15. maj 2011, 21:23
 */

#ifndef SOBJ_H
#define	SOBJ_H
#include "../SFunctions.h"
#include "../Command/SCommand.h"
#include "SPos.h"
#include "../Client.h"
class SCreature;
class SObj {
public:
	SObj(uint32_t id, SPos pos, uint32_t team, uint32_t playerId);
	uint32_t getId();
	SPos& getPos();
	SPos& getOldPos();
        void MovePos(int32_t x, int32_t y);
	uint32_t getSize(){return _size;}
	virtual void announceRemovalOf(SObj* obj){};
	virtual bool canBeRemoved(){return false;}
	virtual uint32_t getTeam(){return _team;}
	virtual uint32_t getPlayerId(){return _playerId;}
	virtual void setUpdateCounter(uint32_t value){this->_updateCounter = value;}
	virtual uint32_t getUpdateCounter(){return this->_updateCounter;}
	virtual SCreature* getCreature(){return NULL;}
	virtual bool readyCast(){return true;}
	list<Client*>* getSubscribers(){return _subscribers;}
	
	uint32_t addCommand(SCommand* cmd);
	uint32_t removeCommand(SCommand* cmd);
	SCommand* procesFirstReadyCommand();
        uint32_t setPos(SPos pos);
        uint32_t reqMove(SPos);
        void lockProcesCommand();
	void releaseProcesCommand();
	virtual ~SObj();
protected:
	SPos _pos;
        uint32_t _posUpdateTime;
	SPos _oldPos;
	uint32_t _id;
	uint32_t _size;
	uint32_t _team;
	uint32_t _playerId;
	uint32_t _updateCounter;
	pthread_mutex_t _lockCommands;
	pthread_mutex_t _lockCommandAccess;
	bool _commandAccessLocked;
	list<SCommand*> _commands;
	list<Client*> _subscribers[3];
};
typedef map<uint32_t,SObj*>::iterator SObjI;
#endif	/* SOBJ_H */

