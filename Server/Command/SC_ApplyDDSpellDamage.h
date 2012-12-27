/* 
 * File:   SC_ApplyDDSpellDamage.h
 * Author: karsten
 *
 * Created on 1. november 2012, 08:49
 */

#ifndef SC_APPLYDDSPELLDAMAGE_H
#define	SC_APPLYDDSPELLDAMAGE_H
#include "../Powers/SPowerType.h"
#include "SCommand.h"
class SC_ApplyDDSpellDamage :public SCommand {
public:
	SC_ApplyDDSpellDamage(uint32_t time, SObj* caster, SObj* target, uint32_t min, uint32_t max, uint32_t hit, uint32_t crit, DamageTypes::Enum dmgType, SPowerType* power);
	virtual uint32_t execute();
	virtual ~SC_ApplyDDSpellDamage();
private:
	SPowerType* _power;
	uint32_t _min;
	uint32_t _max;
	uint32_t _hit;
	uint32_t _crit;
	DamageTypes::Enum _dmgType;
};

#endif	/* SC_APPLYDDSPELLDAMAGE_H */

