/* 
 * File:   SEffectType.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:15
 */

#ifndef SEFFECTTYPE_H
#define	SEFFECTTYPE_H
#include "../SFunctions.h"
class SPowerType;
class SCreature;
class SEffectType {
public:
	SEffectType();
	virtual void apply(uint32_t time, SPowerType* type, SCreature* caster, SCreature* target, map<PowerProjectileMods::Enum, int32_t> values, EResults::Enum result){cerr<<"ERROR empty effectType"<<endl;}
	virtual ~SEffectType();
private:

};

#endif	/* SEFFECTTYPE_H */

