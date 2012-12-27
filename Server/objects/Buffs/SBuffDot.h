/* 
 * File:   SBuffDot.h
 * Author: karsten
 *
 * Created on 18. november 2012, 21:38
 */

#ifndef SBUFFDOT_H
#define	SBUFFDOT_H


#include "SBuffBase.h"
#include "../../Powers/SEffectTypeAddBuff.h"
class SBuffDot : public SBuffBase {
public:
	SBuffDot(SBuff* buff, SCreature* owner, SEffectTypeAddBuff* power);
	virtual uint32_t proces(SC_BuffProces* cmd, uint32_t tickCount);
	virtual ~SBuffDot();
private:
	SCreature* _owner;
	SEffectTypeAddBuff* _power;
	float_t _tick;
	uint32_t _damageRemaining;
	DamageTypes::Enum _damageType;
	
};

#endif	/* SBUFFDOT_H */

