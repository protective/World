/* 
 * File:   GraficEffectDataBlock.h
 * Author: karsten
 *
 * Created on 20. oktober 2013, 16:19
 */

#ifndef GRAFICEFFECTDATABLOCK_H
#define	GRAFICEFFECTDATABLOCK_H
#include "../GLutil.h"
#include "Model.h"
#include "GraficEffectDataBlockState.h"
class ParticalEngine;
class GraficEffectDataBlock {
public:
	GraficEffectDataBlock();
	virtual ~GraficEffectDataBlock();
	ParticalEngine* _engine;

	bool getTermOnInit(){return _termOnInit;}
	glm::vec3 getDeltaV(){return _deltaV;}
	HardPoints::Enum getHardPoint(){return _hp;}
	uint32_t getEmitterSpwanRate(PSStates::Enum state){return _blocks[state]->_emitterSpwanRate;}
	uint32_t getTermTime(){return _termTime;};
	void SetDataBlockState(PSStates::Enum state, GraficEffectDataBlockState* data);

private:
	map<PSStates::Enum, GraficEffectDataBlockState*> _blocks;
	
	bool _termOnInit;
	glm::vec3 _deltaV;
	HardPoints::Enum _hp;
	uint32_t _termTime;
};

#endif	/* GRAFICEFFECTDATABLOCK_H */

