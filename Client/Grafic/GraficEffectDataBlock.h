/* 
 * File:   GraficEffectDataBlock.h
 * Author: karsten
 *
 * Created on 20. oktober 2013, 16:19
 */

#ifndef GRAFICEFFECTDATABLOCK_H
#define	GRAFICEFFECTDATABLOCK_H
#include "../GLutil.h"
class GraficEffectDataBlock {
public:
	GraficEffectDataBlock();
	virtual ~GraficEffectDataBlock();
private:
	glm::vec3 _deltaV;
	
};

#endif	/* GRAFICEFFECTDATABLOCK_H */

