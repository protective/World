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
	virtual SPowerTypeSpellDebuff* getPower(){return _power;}
	virtual ~SC_Debuff();
private:
	SPowerTypeSpellDebuff* _power;
	uint32_t _tickCount;
	list<SBuffBase*> _buffeffectlist;
};

#endif	/* SC_DEBUFF_H */

