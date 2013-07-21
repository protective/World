/* 
 * File:   SEffectTypeAddBuff.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:15
 */

#ifndef SEFFECTTYPEADDBUFF_H
#define	SEFFECTTYPEADDBUFF_H

#include "SEffectType.h"
#include "../objects/SCreature.h"

struct ticksEffects{
	ticksEffects(int32_t value){
	_value = value;
	}
	int32_t _value;
	
};

class SEffectTypeAddBuff : public SEffectType {
public:
	SEffectTypeAddBuff();
	virtual void apply(uint32_t time, SPowerType* type, SCreature* caster, SCreature* target,map<PowerProjectileMods::Enum, int32_t> values);
	list<ticksEffects>& gettickEffects(){return _tickEffects;}
	map< StatsMods::Enum, int32_t>& getStatsMods(){return _statsMods;}
	
	uint32_t getTotalDamage(){return _totalDamage;}	
	void setTotalDamage(int32_t damage){_totalDamage = damage;}
	
	DamageTypes::Enum getDamageType(){return _damageType;}	
	void setDamageType(DamageTypes::Enum type){_damageType = type;}

	map<BuffVisualEffects::Enum,uint32_t>& getVisualEffects(){return _visualEffects;}
	
	void setTickTime(uint32_t time){_tickTime = time;}
	
	virtual ~SEffectTypeAddBuff();
private:

	map< StatsMods::Enum, int32_t> _statsMods;
	map<BuffVisualEffects::Enum,uint32_t> _visualEffects;
	list<ticksEffects> _tickEffects;
	uint32_t _tickTime;
	uint32_t _totalDamage;
	DamageTypes::Enum _damageType;
	
};

#endif	/* SEFFECTTYPEADDBUFF_H */

