/* 
 * File:   SEffectTypeAddBuff.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:15
 */

#ifndef SEFFECTTYPEADDBUFF_H
#define	SEFFECTTYPEADDBUFF_H

#include "SEffectType.h"
#include "../objects/SCreature.h"

struct ticksEffects{
	int32_t _value;
	
};

class SEffectTypeAddBuff : public SEffectType {
public:
	SEffectTypeAddBuff();
	virtual void apply(uint32_t time, SCreature* caster, SCreature* target);
	list<ticksEffects>& gettickEffects(){return _tickEffects;}
	uint32_t getTotalDamage(){return _totalDamage;}
	virtual ~SEffectTypeAddBuff();
private:

	map< StatsMods::Enum, int32_t> _statsMods;
	list<ticksEffects> _tickEffects;
	uint32_t _totalDamage;
};

#endif	/* SEFFECTTYPEADDBUFF_H */

