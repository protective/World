/* 
 * File:   GraficEffectType.h
 * Author: karsten
 *
 * Created on 20. oktober 2013, 16:18
 */

#ifndef GRAFICEFFECTTYPE_H
#define	GRAFICEFFECTTYPE_H
#include "../CFunctions.h"
#include "GraficEffectDataBlock.h"

class GraficEffectType {
public:
	GraficEffectType(uint32_t id);
	uint32_t getId(){return _id;}
	map<uint32_t, GraficEffectDataBlock*>& getData(){return _particalSystemsData;}
	
	virtual ~GraficEffectType();
private:
	uint32_t _id;
	map<uint32_t, GraficEffectDataBlock*> _particalSystemsData;
};

#endif	/* GRAFICEFFECTTYPE_H */

