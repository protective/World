/* 
 * File:   SPowerTypeSpellDD.h
 * Author: karsten
 *
 * Created on 7. november 2012, 20:57
 */

#ifndef SPOWERTYPESPELLDD_H
#define	SPOWERTYPESPELLDD_H

#include "SPowerSpellType.h"

class SPowerTypeSpellDD : public SPowerSpellType {
public:
	SPowerTypeSpellDD(uint32_t id,uint32_t min, uint32_t max,  DamageTypes::Enum dmgType);
	virtual uint32_t activate(uint32_t time, SObj* caster, SObj* target);

	void callBackResult(uint32_t time,SObj* caster, SObj* target,EResults::Enum result, uint32_t value);
	void addResultPowerType(EResults::Enum event, SPowerType* power);
	virtual ~SPowerTypeSpellDD();
private:
	uint32_t _min;
	uint32_t _max;
	DamageTypes::Enum _dmgType;
	map<EResults::Enum, list<SPowerType*> > _resultsList;
};

#endif	/* SPOWERTYPESPELLDD_H */

