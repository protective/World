/* 
 * File:   SPowerTypeSpellDD.h
 * Author: karsten
 *
 * Created on 7. november 2012, 20:57
 */

#ifndef SPOWERTYPESPELLDD_H
#define	SPOWERTYPESPELLDD_H

#include "SPowerType.h"

class SPowerTypeSpellDD : public SPowerType{
public:
	SPowerTypeSpellDD(uint32_t damage);
	virtual uint32_t activate(uint32_t time, SObj* caster, SObj* target);

	void callBackResult(uint32_t time,SObj* caster, SObj* target,EResults::Enum result, uint32_t value);
	void addResultPowerType(EResults::Enum event, SPowerType* power);
	virtual ~SPowerTypeSpellDD();
private:
	uint32_t _damage;
	map<EResults::Enum, list<SPowerType*> > _resultsList;
};

#endif	/* SPOWERTYPESPELLDD_H */

