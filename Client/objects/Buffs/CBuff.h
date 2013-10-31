/* 
 * File:   CBuff.h
 * Author: karsten
 *
 * Created on 20. oktober 2013, 16:18
 */

#ifndef CBUFF_H
#define	CBUFF_H
#include "../../CFunctions.h"
class GraficEffectType;
class CBuff {
public:
	CBuff(uint32_t id);
	uint32_t getId(){return _id;}
	list<GraficEffectType*>& getEffects(){return _effects;}
	virtual ~CBuff();
private:
	uint32_t _id;
	list<GraficEffectType*> _effects;
};

#endif	/* CBUFF_H */

