/* 
 * File:   GraficEffectPlayer.h
 * Author: karsten
 *
 * Created on 20. oktober 2013, 16:17
 */

#ifndef GRAFICEFFECTPLAYER_H
#define	GRAFICEFFECTPLAYER_H

#include "GraficEffectType.h"
#include "ParticalSystems/ParticalSystem.h"


class GraficEffectPlayer {
public:
	GraficEffectPlayer(CCreature* obj, GraficEffectType* typeData);
	virtual void draw(Camera* camera);
	virtual void Proces(uint32_t DTime);
	virtual uint32_t signal(uint32_t signal);
	
	virtual ~GraficEffectPlayer();
private:
	uint32_t _EffectId;
	CCreature* _obj;
	GraficEffectType* _typeData;
	map<uint32_t, ParticalSystem*> _particalS;
	
};

#endif	/* GRAFICEFFECTPLAYER_H */

