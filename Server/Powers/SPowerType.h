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
	SPowerType(uint32_t id, uint32_t iconId);
	uint32_t activate(uint32_t time, SObj* caster, SObj* target, map<PowerProjectileMods::Enum,int32_t> values);
	uint32_t getId(){return _id;}
        uint32_t getIconId(){return _iconId;}
	map<EResults::Enum, list<SEffectType*> >& getSubComponents(){return _subComponents;}
	map<PowerTypeStats::Enum, int32_t>& getStats(){return _stats;}
	virtual ~SPowerType();
private:
	uint32_t _id;
        uint32_t _iconId;
	map<EResults::Enum, list<SEffectType*> >_subComponents;
	map<PowerTypeStats::Enum, int32_t> _stats;
};

#endif	/* SPOWERTYPE_H */

