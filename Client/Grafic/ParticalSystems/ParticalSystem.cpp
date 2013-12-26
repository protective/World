/* 
 * File:   ParticalSystem.cpp
 * Author: karsten
 * 
 * Created on 2. oktober 2013, 11:53
 */

#include "ParticalSystem.h"
#include "../../objects/CCreature.h"
ParticalSystem::ParticalSystem(GraficEffectDataBlock* data) {
	_engine = data->_engine;
	_data = data;
	m_isFirst = true;
	m_currVB = 0;
    m_currTFB = 1;
	m_time = 0;
	_expireTime = 0;
	changeStateUpdate(PSStates::Init);
}

ParticalSystem::~ParticalSystem(){
    if (m_transformFeedback[0] != 0) {
        glDeleteTransformFeedbacks(2, m_transformFeedback);
    }
    
    if (m_particleBuffer[0] != 0) {
        glDeleteBuffers(2, m_particleBuffer);
    }
}

bool ParticalSystem::InitParticleSystem(CCreature* object, HardPoints::Enum hp){
	
	_creature = object;
	_hp = hp;
    Particle Particles[MAX_PARTICLES];
	memset(&Particles,0,sizeof(Particle)*MAX_PARTICLES);
    Particles[0].Type = PARTICLE_TYPE_LAUNCHER;
    Particles[0].Pos = object->getGraficPos() + object->getModel()->getHardPoint(hp);
    Particles[0].Vel = glm::vec3(0.0f, 0.0001f, 0.0f);
    Particles[0].LifetimeMillis = 0.0f;
	
	glGenTransformFeedbacks(2, m_transformFeedback);
	ExitOnGLError("ERROR: glGenTransformFeedbacks ");
    glGenBuffers(2, m_particleBuffer);
	ExitOnGLError("ERROR: glGenBuffers ");

    for (unsigned int i = 0; i < 2 ; i++) {
        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, m_transformFeedback[i]);
        glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Particles), Particles, GL_DYNAMIC_DRAW);
        glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, m_particleBuffer[i]);        
    }
    _engine->getUpShader()->enable();
    _engine->getUpShader()->SetRandomTextureUnit(3);
    _engine->getUpShader()->SetLauncherLifetime((float)_data->getEmitterSpwanRate(_state));
    _engine->getUpShader()->SetShellLifetime(3000.0f);
	
    ExitOnGLError("ERROR: Setuniforms ");

    _engine->getRandomVec3Tex()->Bind(GL_TEXTURE3);
	ExitOnGLError("ERROR: getRandomVec3Tex()->Bind ");

    _engine->getBillboardShader()->enable();
	
    _engine->getBillboardShader()->SetColorTextureUnit(0);

    _engine->getBillboardShader()->SetBillboardSize(0.01f);
    
	//TODO load correct texture
    m_pTexture = textures[2];
	changeStateUpdate(PSStates::Init);
    return 0;
}

bool ParticalSystem::TermParticleSystem(){
	_expireTime = m_time+_data->getTermTime();
	changeStateUpdate(PSStates::Term);
}

void ParticalSystem::changeStateUpdate(PSStates::Enum state){
	_state = state;
	
}

void ParticalSystem::Update(int DeltaTimeMillis)
{
	m_time += DeltaTimeMillis;
    _engine->getUpShader()->enable();
    _engine->getUpShader()->SetTime(m_time);
    _engine->getUpShader()->SetDeltaTimeMillis(DeltaTimeMillis);
	_engine->getUpShader()->SetLauncherLifetime((float)_data->getEmitterSpwanRate(_state));
	_engine->getUpShader()->SetEmitterPos(_creature->getGraficPos() + _creature->getModel()->getHardPoint(_hp));
	
	_engine->getUpShader()->SetCrikInitVel(0);
	_engine->getUpShader()->SetGlobeInitVel(1);
	_engine->getUpShader()->SetGravity(0);
	
	_engine->getUpShader()->setInitVel(glm::vec3(0,0,0));
	
	
	_engine->getRandomVec3Tex()->Bind(GL_TEXTURE3);
    glEnable(GL_RASTERIZER_DISCARD);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[m_currVB]);    
    glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, m_transformFeedback[m_currTFB]);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);

    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), 0);                          // type
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)4);         // position
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)16);        // velocity
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)28);          // lifetime
	
    glBeginTransformFeedback(GL_POINTS);
    if (m_isFirst) {
        glDrawArrays(GL_POINTS, 0, 1);

        m_isFirst = false;
    }
    else {
        glDrawTransformFeedback(GL_POINTS, m_transformFeedback[m_currVB]);
    }             
    glEndTransformFeedback();
	ExitOnGLError("ERROR: glEndTransformFeedback");
  
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);

	glDisable(GL_RASTERIZER_DISCARD);
	
	
}


void ParticalSystem::draw(Camera* camera){
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable (GL_BLEND);
	glDepthMask (GL_FALSE);
    _engine->getBillboardShader()->enable();
	//cerr<<"cam x "<<camera->getPosition()->x<<" y "<<camera->getPosition()->y<<" z "<<camera->getPosition()->z<<endl;
    _engine->getBillboardShader()->SetCameraPosition(camera->getPosition());
	
	glm::mat4 VP = glm::mat4(*camera->getViewMatrix()) * (*camera->getProjectionMatrix());
	glm::mat4 V = *camera->getViewMatrix();
	glm::mat4 P	= *camera->getProjectionMatrix();
	glm::mat4 PV = P * V;
	//VP = glm::mat4();
    _engine->getBillboardShader()->SetVP(&(PV)) ;
	_engine->getBillboardShader()->SetRight(camera->getRight());
	ExitOnGLError("ERROR: ParticalSystem::draw set uniforms");
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_3D, m_pTexture);
	ExitOnGLError("ERROR: ParticalSystem::draw glBindtexture");
	//ExitOnGLError("ERROR: Could not set the model shader texture uniforms");

    glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[m_currTFB]);    
	ExitOnGLError("ERROR: ParticalSystem::draw glBindBuffer");
    glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)4);  // position
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)28);  // LifetimeMillis
	ExitOnGLError("ERROR: ParticalSystem::draw set attri");
	
	//glDrawArrays(GL_POINTS, 0,1);
    glDrawTransformFeedback(GL_POINTS, m_transformFeedback[m_currTFB]);
	ExitOnGLError("ERROR: ParticalSystem::draw glDrawTransformFeedback");
    glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	//flip buffer
	m_currVB = m_currTFB;
    m_currTFB = (m_currTFB + 1) & 0x1;
	if(_state == PSStates::Init){
		
		changeStateUpdate(_state);
	}
	glDepthMask (GL_TRUE);
	glDisable (GL_BLEND);
}


