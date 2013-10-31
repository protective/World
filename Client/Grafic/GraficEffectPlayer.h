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
namespace GEP {
	enum Options {
	  Init    = 0x01,
	  Term    = 0x02
	  
	};
}
class GraficEffectPlayer {
public:
	GraficEffectPlayer(CCreature* obj, GraficEffectType* typeData);
	~GraficEffectPlayer();
	void incRef(){_refs++;}
	void decRef(){_refs--;}
	void checkDeleteAllParticalSystems(bool force);
	bool refZero(){return _refs == 0;}
	virtual void draw(Camera* camera);
	virtual void Proces(uint32_t DTime);
	virtual uint32_t signal(uint32_t signal);
	bool canBeRemoved();
private:
	uint32_t _EffectId;
	CCreature* _obj;
	GraficEffectType* _typeData;
	map<uint32_t, ParticalSystem*> _particalS;
	uint32_t _signal;
	uint32_t _refs;
	
};

#endif	/* GRAFICEFFECTPLAYER_H */

