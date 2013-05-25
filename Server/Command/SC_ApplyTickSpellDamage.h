/* 
 * File:   SC_ApplyTickSpellDamage.h
 * Author: karsten
 *
 * Created on 1. november 2012, 08:49
 */

#ifndef SC_APPLYTICKSPELLDAMAGE_H
#define	SC_APPLYTICKSPELLDAMAGE_H

#include "SCommand.h"


class SC_ApplyTickSpellDamage : public SCommand {
public:
	SC_ApplyTickSpellDamage(uint32_t time, SObj* procesUnit, SObj* caster, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power);
	virtual uint32_t execute();
	virtual ~SC_ApplyTickSpellDamage();
private:
	uint32_t _damage;
	SPowerType* _power;
	DamageTypes::Enum _dmgType;
	SObj* _caster;
};

#endif	/* SC_APPLYTICKSPELLDAMAGE_H */

