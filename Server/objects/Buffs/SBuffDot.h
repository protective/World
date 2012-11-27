/* 
 * File:   SBuffDot.h
 * Author: karsten
 *
 * Created on 18. november 2012, 21:38
 */

#ifndef SBUFFDOT_H
#define	SBUFFDOT_H


#include "SBuffBase.h"

class SBuffDot : public SBuffBase {
public:
	SBuffDot(SC_Debuff* command, SPowerTypeSpellDebuff* power);
	virtual uint32_t proces(uint32_t tickCount);
	virtual ~SBuffDot();
private:
	SC_Debuff* _command;
	SPowerTypeSpellDebuff* _power;
	float_t _tick;
	uint32_t _damageRemaining;
};

#endif	/* SBUFFDOT_H */

