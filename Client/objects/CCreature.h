/* 
 * File:   CCreature.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:35
 */

#ifndef CCREATURE_H
#define	CCREATURE_H
#include "CObj.h"
#include "../Powers/CPower.h"
class CCreature : public CObj {
public:
	CCreature(uint32_t id, uint32_t playerId, CPos pos);
	
	uint32_t getCastTime(){return _castTime;}
	void setCastTime(uint32_t time){_castTime = time;}
	uint32_t getCastCompletionTime(){return _castCompletionTime;}
	void setCastCompletionTime(uint32_t time){_castCompletionTime = time;}
	virtual CCreature* getCreature(){return this;}
	map<uint32_t,CPower*>& getPowers(){return this->_powerList;}
	virtual void Draw();
        virtual ~CCreature();
private:
	map<uint32_t,CPower*> _powerList;
	uint32_t _castTime;
	uint32_t _castCompletionTime;
};

#endif	/* CCREATURE_H */

