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
struct ticksEffects{
	uint32_t _delay;
	EffectTypes::Enum _effect;
	uint32_t _value;
};

class SPowerTypeSpellDebuff : public SPowerSpellType {
public:
	SPowerTypeSpellDebuff();
	virtual uint32_t activate(uint32_t time, SObj* caster, SObj* target);
	virtual ~SPowerTypeSpellDebuff();
	map<EffectTypes::Enum,int32_t>& getfullMods(){return _fullMods;} 
	list<ticksEffects>& gettickEffects(){return _ticks;} 
	uint32_t getTotalDamage(){return _totalDamage;}
private:
	map<EffectTypes::Enum,int32_t> _fullMods;
	list<ticksEffects> _ticks;
	uint32_t _totalDamage;
};

#endif	/* SPOWERTYPESPELLDEBUFF_H */

