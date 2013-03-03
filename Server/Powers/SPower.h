/* 
 * File:   SPower.h
 * Author: karsten
 *
 * Created on 1. november 2012, 17:40
 */

#ifndef SPOWER_H
#define	SPOWER_H
#include "../SFunctions.h"
#include "SPowerType.h"
class SObj;
class SPower {
public:
	SPower(uint32_t id, SObj* owner, SPowerType* powertype);
	virtual uint32_t activate(uint32_t time, SObj* unit,SObj* target);
	virtual ~SPower();
	SPowerType* getPowerType(){return _powertype;}
	void sendToClient(Client* cli);
	uint32_t getId() {return _id;}
protected:
	SPowerType* _powertype;
	uint32_t _id;
	uint32_t _cd;
	SObj* _owner;
};

#endif	/* SPOWER_H */

