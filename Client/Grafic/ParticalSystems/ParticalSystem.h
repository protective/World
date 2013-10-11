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
	ParticalSystem(ParticalEngine* engine);
	bool InitParticleSystem(CCreature* object, HardPoints::Enum hp);
    
	virtual void draw(Camera* camera);
	virtual void Update(int DeltaTimeMillis);
	virtual ~ParticalSystem();
private:
	
    bool m_isFirst;
    unsigned int m_currVB;
    unsigned int m_currTFB;
    GLuint m_particleBuffer[2];
    GLuint m_transformFeedback[2];
	ParticalEngine* _engine;
    GLuint m_pTexture;
    int m_time;
	CCreature* _creature;
	HardPoints::Enum _hp;
};

#endif	/* PARTICALSYSTEM_H */

