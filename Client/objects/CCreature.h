/* 
 * File:   CCreature.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:35
 */

#ifndef CCREATURE_H
#define	CCREATURE_H
#include "CObj.h"
#include "../Grafic/CGraficObject.h"
#include "../Powers/CPower.h"
#include "Buffs/CBuff.h"

class CCreature : public CObj , public CGraficObject {
public:
	friend class CGraficObject;
	CCreature(uint32_t id, uint32_t playerId, CPos pos, Model* model);
	virtual void Proces(uint32_t DTime);
	uint32_t getCastTime(){return _castTime;}
	void setCastTime(uint32_t time){_castTime = time;}
	uint32_t getCastCompletionTime(){return _castCompletionTime;}
	void setCastCompletionTime(uint32_t time){_castCompletionTime = time;}
	virtual CCreature* getCreature(){return this;}
	uint32_t addBuff(CBuff* buff);
	uint32_t removeBuff(CBuff* buff);
	map<uint32_t,CBuff*>& getBuffs(){return _bufflist;}
	map<uint32_t,CPower*>& getPowers(){return this->_powerList;}
	map<Attributes::Enum , int32_t>& getAttibute(){return _attribute;}
	virtual ~CCreature();
protected:
	map<uint32_t,CPower*> _powerList;
	map<Attributes::Enum , int32_t> _attribute;
	map<uint32_t,CBuff*> _bufflist;
	uint32_t _castTime;
	uint32_t _castCompletionTime;
};

#endif	/* CCREATURE_H */

