/* 
 * File:   SPowerSpellDebuff.h
 * Author: karsten
 *
 * Created on 1. november 2012, 22:17
 */

#ifndef SPOWERTYPESPELLDEBUFF_H
#define	SPOWERTYPESPELLDEBUFF_H

#include "SPowerSpellType.h"
class SObj;


class SPowerTypeSpellDebuff : public SPowerSpellType {
public:
	SPowerTypeSpellDebuff(uint32_t id);
	virtual uint32_t activate(uint32_t time, SObj* caster, SObj* target);
	virtual ~SPowerTypeSpellDebuff();
	uint32_t getTickDelay(){return _tickDelay;}
	uint32_t getTickCounts(){return _tickCounts;}
private:
	
	uint32_t _tickCounts;
	uint32_t _tickDelay;
};

#endif	/* SPOWERTYPESPELLDEBUFF_H */

