/* 
 * File:   ParticalSystem.h
 * Author: karsten
 *
 * Created on 2. oktober 2013, 11:53
 */

#ifndef PARTICALSYSTEM_H
#define	PARTICALSYSTEM_H

#include "../Shaders/BillboardShader.h"
#include "ParticalUpShader.h"
#include "../Camera.h"
#include "../GraficUtils/RandomVec3Texture.h"
#include "ParticalEngine.h"
#include "../Model.h"
#include "../GraficEffectDataBlock.h"
struct Particle
{
    float Type;    
    glm::vec3 Pos;
    glm::vec3 Vel;    
    float LifetimeMillis;    
};

#define MAX_PARTICLES 500
#define PARTICLE_LIFETIME 10.0f

#define PARTICLE_TYPE_LAUNCHER 0.0f
#define PARTICLE_TYPE_SHELL 1.0f
#define PARTICLE_TYPE_SECONDARY_SHELL 2.0f




class ParticalSystem {
public:
	ParticalSystem(GraficEffectDataBlock* data);
	~ParticalSystem();
	bool InitParticleSystem(CCreature* object, HardPoints::Enum hp);
	bool TermParticleSystem();
	bool SystemDone(){return m_time >= _expireTime && _expireTime > 0;}
	bool IsTerminating(){return _expireTime ;}
	virtual void draw(Camera* camera);
	virtual void Update(int DeltaTimeMillis);
private:
	void changeStateUpdate(PSStates::Enum state);
    bool m_isFirst;
    unsigned int m_currVB;
    unsigned int m_currTFB;
    GLuint m_particleBuffer[2];
    GLuint m_transformFeedback[2];
	GraficEffectDataBlock*  _data;
	ParticalEngine*  _engine; //performans saving
    GLuint m_pTexture;
    int m_time;
	CCreature* _creature;
	HardPoints::Enum _hp;
	PSStates::Enum _state;
	int32_t _expireTime;

};

#endif	/* PARTICALSYSTEM_H */

