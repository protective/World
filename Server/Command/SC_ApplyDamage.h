/* 
 * File:   SC_ApplyDamage.h
 * Author: karsten
 *
 * Created on 15. november 2012, 21:07
 */

#ifndef SC_APPLYDAMAGE_H
#define	SC_APPLYDAMAGE_H

#include "SCommand.h"


class SC_ApplyDamage : public SCommand {
public:
	SC_ApplyDamage(uint32_t time, SObj* caster, SObj* target, uint32_t damage, DamageTypes::Enum dmgType, SPowerType* power);
	virtual uint32_t execute();
	virtual ~SC_ApplyDamage();
private:
	SPowerType* _power;
	uint32_t _damage;
	DamageTypes::Enum _dmgType;
};

#endif	/* SC_APPLYDAMAGE_H */

