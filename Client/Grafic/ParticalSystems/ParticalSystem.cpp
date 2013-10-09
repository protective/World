/* 
 * File:   ParticalSystem.cpp
 * Author: karsten
 * 
 * Created on 2. oktober 2013, 11:53
 */

#include "ParticalSystem.h"

ParticalSystem::ParticalSystem(ParticalEngine* engine) {
	cerr<<"Create particle system"<<endl;
	_engine = engine;
	m_isFirst = true;
	m_currVB = 0;
    m_currTFB = 1;
	m_time = 0;
}


bool ParticalSystem::InitParticleSystem(const glm::vec3& Pos){
	cerr<<"INIT particle system"<<endl;
    Particle Particles[MAX_PARTICLES];
	memset(&Particles,0,sizeof(Particle)*MAX_PARTICLES);
	
    Particles[0].Type = PARTICLE_TYPE_LAUNCHER;
    Particles[0].Pos = Pos;
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
    _engine->getUpShader()->SetLauncherLifetime(100.0f);
    _engine->getUpShader()->SetShellLifetime(10000.0f);
    ExitOnGLError("ERROR: Setuniforms ");

    
    _engine->getRandomVec3Tex()->Bind(GL_TEXTURE3);
	ExitOnGLError("ERROR: getRandomVec3Tex()->Bind ");


    _engine->getBillboardShader()->enable();

	
    _engine->getBillboardShader()->SetColorTextureUnit(0);

    _engine->getBillboardShader()->SetBillboardSize(0.01f);
    
	//TODO load correct texture
    m_pTexture = textures[1];

    return 0;
}




void ParticalSystem::Update(int DeltaTimeMillis)
{
	
	m_time += DeltaTimeMillis;
    _engine->getUpShader()->enable();
    _engine->getUpShader()->SetTime(m_time);
    _engine->getUpShader()->SetDeltaTimeMillis(DeltaTimeMillis);
   
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

	
    _engine->getBillboardShader()->enable();
	//cerr<<"cam x "<<camera->getPosition()->x<<" y "<<camera->getPosition()->y<<" z "<<camera->getPosition()->z<<endl;
    _engine->getBillboardShader()->SetCameraPosition(camera->getPosition());
	
	glm::mat4 VP = glm::mat4(*camera->getViewMatrix()) * (*camera->getProjectionMatrix());
	glm::mat4 V = *camera->getViewMatrix();
	glm::mat4 P	= *camera->getProjectionMatrix();
	glm::mat4 PV = P * V;
	//VP = glm::mat4();
    _engine->getBillboardShader()->SetVP(&(PV)) ;
	ExitOnGLError("ERROR: ParticalSystem::draw set uniforms");
	
    //m_pTexture->Bind(GL_TEXTURE0);
    
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_pTexture);
	ExitOnGLError("ERROR: ParticalSystem::draw glBindtexture");
	//ExitOnGLError("ERROR: Could not set the model shader texture uniforms");

    glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[m_currTFB]);    
	ExitOnGLError("ERROR: ParticalSystem::draw glBindBuffer");
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)4);  // position
	ExitOnGLError("ERROR: ParticalSystem::draw set attri");
	
	//glDrawArrays(GL_POINTS, 0,1);
    glDrawTransformFeedback(GL_POINTS, m_transformFeedback[m_currTFB]);
	ExitOnGLError("ERROR: ParticalSystem::draw glDrawTransformFeedback");
    glDisableVertexAttribArray(0);

	//flip buffer
	m_currVB = m_currTFB;
    m_currTFB = (m_currTFB + 1) & 0x1;
}


ParticalSystem::~ParticalSystem() {
}

