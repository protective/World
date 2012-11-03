/* 
 * File:   SPowerSpellDebuff.h
 * Author: karsten
 *
 * Created on 1. november 2012, 22:17
 */

#ifndef SPOWERTYPESPELLDEBUFF_H
#define	SPOWERTYPESPELLDEBUFF_H

#include "SPowerType.h"
class SObj;
struct ticksEffects{
	uint32_t _delay;
	ModTypes::Enum _effect;
	uint32_t _value;
};

class SPowerTypeSpellDebuff : public SPowerType {
public:
	SPowerTypeSpellDebuff();
	virtual uint32_t activate(uint32_t time, SObj* unit, SObj* target);
	virtual ~SPowerTypeSpellDebuff();
private:
	map<ModTypes::Enum,int32_t> _fullMods;
	list<ticksEffects> _ticks;
};

#endif	/* SPOWERTYPESPELLDEBUFF_H */

