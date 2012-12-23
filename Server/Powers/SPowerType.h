/* 
 * File:   SPowerType.h
 * Author: karsten
 *
 * Created on 3. november 2012, 18:40
 */

#ifndef SPOWERTYPE_H
#define	SPOWERTYPE_H
#include "../SFunctions.h"
#include "SEffectType.h"
class SObj;
class SPowerType {
public:
	SPowerType(uint32_t id);
	virtual uint32_t activate(uint32_t time, SObj* caster, SObj* target);
	uint32_t getId(){return _id;}
	map<EResults::Enum, list<SEffectType*> > getSubComponents(){return _subComponents;}
	virtual ~SPowerType();
private:
	uint32_t _id;
	map<EResults::Enum, list<SEffectType*> >_subComponents;
};

#endif	/* SPOWERTYPE_H */

