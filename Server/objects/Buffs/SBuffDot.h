/* 
 * File:   SBuffDot.h
 * Author: karsten
 *
 * Created on 18. november 2012, 21:38
 */

#ifndef SBUFFDOT_H
#define	SBUFFDOT_H


#include "SBuffBase.h"
#include "../../Command/SC_Debuff.h"
class SBuffDot : public SBuffBase {
public:
	SBuffDot(SEffectTypeAddBuff* power);
	virtual uint32_t proces(uint32_t tickCount);
	virtual ~SBuffDot();
private:
	SEffectTypeAddBuff* _power;
	float_t _tick;
	uint32_t _damageRemaining;
	DamageTypes::Enum _damageType;
};

#endif	/* SBUFFDOT_H */

