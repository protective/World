/* 
 * File:   SEffectTypeDD.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:15
 */

#ifndef SEFFECTTYPEDD_H
#define	SEFFECTTYPEDD_H

#include "SEffectType.h"


class SEffectTypeDD :public SEffectType {
public:
	SEffectTypeDD();
	virtual void apply(uint32_t time, SPowerType* type, SCreature* caster, SCreature* target, map<PowerProjectileMods::Enum, int32_t> values);
	
	uint32_t getMinDamage(){return _minDamage;}
	void setMinDamage(int32_t damage){_minDamage = damage;}

	uint32_t getMaxDamage(){return _maxDamage;}
	void setMaxDamage(int32_t damage){_maxDamage = damage;}
	
	uint32_t getCritMod(){return _critMod;}
	void setCritMod(int32_t mod){_critMod = mod;}
	
	DamageTypes::Enum getDamageType(){return _damageType;}
	void setDamageType(DamageTypes::Enum type){_damageType = type;}
	
	virtual ~SEffectTypeDD();
private:
	DamageTypes::Enum _damageType;
	uint32_t _minDamage;
	uint32_t _maxDamage;
	uint32_t _critMod;
};

#endif	/* SEFFECTTYPEDD_H */

