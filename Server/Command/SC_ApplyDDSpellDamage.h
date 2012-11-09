/* 
 * File:   SC_ApplyDDSpellDamage.h
 * Author: karsten
 *
 * Created on 1. november 2012, 08:49
 */

#ifndef SC_APPLYDDSPELLDAMAGE_H
#define	SC_APPLYDDSPELLDAMAGE_H
#include "../Powers/SPowerTypeSpellDD.h"
#include "SCommand.h"
class SC_ApplyDDSpellDamage :public SCommand {
public:
	SC_ApplyDDSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, SPowerTypeSpellDD* power);
	virtual uint32_t execute();
	virtual ~SC_ApplyDDSpellDamage();
private:
	SPowerTypeSpellDD* _power;
	uint32_t _damage;
};

#endif	/* SC_APPLYDDSPELLDAMAGE_H */

