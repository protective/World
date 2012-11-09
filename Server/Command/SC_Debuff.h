/* 
 * File:   SC_Debuff.h
 * Author: karsten
 *
 * Created on 1. november 2012, 08:36
 */

#ifndef SC_DEBUFF_H
#define	SC_DEBUFF_H

#include "SCommand.h"
#include "../Powers/SPowerTypeSpellDebuff.h"


class SC_Debuff : public SCommand {
public:
	SC_Debuff(uint32_t time, SObj* caster, SObj* target, SPowerTypeSpellDebuff* power);
	virtual uint32_t execute();
	virtual ~SC_Debuff();
private:
	SPowerTypeSpellDebuff* _power;
	float_t _tick;
	uint32_t _tickCount;
	uint32_t _damageRemaing;
};

#endif	/* SC_DEBUFF_H */

