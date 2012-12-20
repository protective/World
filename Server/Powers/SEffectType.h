/* 
 * File:   SEffectType.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:15
 */

#ifndef SEFFECTTYPE_H
#define	SEFFECTTYPE_H

class SEffectType {
public:
	SEffectType();
	virtual void apply(SCreature* caster, SCreature* target){}
	virtual ~SEffectType();
private:

};

#endif	/* SEFFECTTYPE_H */

