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

class SEffectTypeAddBuff : public SEffectType {
public:
	SEffectTypeAddBuff();
	virtual void apply(SCreature* caster, SCreature* target);
	virtual ~SEffectTypeAddBuff();
private:

};

#endif	/* SEFFECTTYPEADDBUFF_H */

