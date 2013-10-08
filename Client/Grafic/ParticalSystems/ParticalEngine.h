/* 
 * File:   ParticalEngine.h
 * Author: karsten
 *
 * Created on 7. oktober 2013, 17:38
 */

#ifndef PARTICALENGINE_H
#define	PARTICALENGINE_H
#include "ParticalUpShader.h"
#include "../Shaders/BillboardShader.h"
#include "../GraficUtils/RandomVec3Texture.h"
class ParticalEngine {
public:
	ParticalEngine();
	bool InitParticleEngine();
    ParticalUpShader* getUpShader(){return &m_updateTechnique;}
	BillboardShader* getBillboardShader(){return &m_billboardTechnique;}
	RandomVec3Texture* getRandomVec3Tex(){return &m_randomTexture;}
	virtual ~ParticalEngine();
private:
    ParticalUpShader m_updateTechnique;
    BillboardShader m_billboardTechnique;
    RandomVec3Texture m_randomTexture;
};

#endif	/* PARTICALENGINE_H */

