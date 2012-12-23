/* 
 * File:   SBuff.h
 * Author: karsten
 *
 * Created on 17. november 2012, 21:31
 */

#ifndef SBUFF_H
#define	SBUFF_H

#include "SBuffBase.h"


class SBuff {
public:
	SBuff(uint32_t maxTick, uint32_t tickTime);
	list<SBuffBase*>& getEffects(){return _effects;}
	uint32_t procesTick();
	uint32_t getTickCount(){return _tickCount;}
	uint32_t getTickTime(){return _tickTime;}
	virtual ~SBuff();
private:
	list<SBuffBase*> _effects;
	uint32_t _tickCount;
	uint32_t _maxtickCount;
	uint32_t _tickTime;
};

#endif	/* SBUFF_H */
