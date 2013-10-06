/* 
 * File:   ParticalSystem.cpp
 * Author: karsten
 * 
 * Created on 2. oktober 2013, 11:53
 */

#include "ParticalSystem.h"

ParticalSystem::ParticalSystem() {
}


bool ParticalSystem::InitParticleSystem(const glm::vec3& Pos){
    Particle Particles[MAX_PARTICLES];
	memset(&Particles,0,sizeof(Particle)*MAX_PARTICLES);

    Particles[0].Type = PARTICLE_TYPE_LAUNCHER;
    Particles[0].Pos = Pos;
    Particles[0].Vel = glm::vec3(0.0f, 0.0001f, 0.0f);
    Particles[0].LifetimeMillis = 0.0f;

    glGenTransformFeedbacks(2, m_transformFeedback);    
    glGenBuffers(2, m_particleBuffer);
    
    for (unsigned int i = 0; i < 2 ; i++) {
        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, m_transformFeedback[i]);
        glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Particles), Particles, GL_DYNAMIC_DRAW);
        glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, m_particleBuffer[i]);        
    }
                      
    if (!m_updateTechnique.init()) {
        return false;
    }
    
    m_updateTechnique.enable();
    
    //m_updateTechnique.SetRandomTextureUnit(RANDOM_TEXTURE_UNIT_INDEX);
    m_updateTechnique.SetLauncherLifetime(100.0f);
    m_updateTechnique.SetShellLifetime(10000.0f);
    
	/*
    if (!m_randomTexture.InitRandomTexture(1000)) {
        return false;
    }
    
    m_randomTexture.Bind(RANDOM_TEXTURE_UNIT);

	*/
    if (!m_billboardTechnique.init()) {
        return false;
    }
    
    m_billboardTechnique.enable();

	/*
    m_billboardTechnique.SetColorTextureUnit(COLOR_TEXTURE_UNIT_INDEX);

    m_billboardTechnique.SetBillboardSize(0.01f);
    
    m_pTexture = new Texture(GL_TEXTURE_2D, "fireworks_red.jpg");
    
    if (!m_pTexture->Load()) {
        return false;
    }        
    */
    return 0;
}




void ParticalSystem::Update(int DeltaTimeMillis)
{
	m_time += DeltaTimeMillis;
	
    m_updateTechnique.enable();
    m_updateTechnique.SetTime(m_time);
    m_updateTechnique.SetDeltaTimeMillis(DeltaTimeMillis);
   
   // m_randomTexture.Bind(RANDOM_TEXTURE_UNIT);
    
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

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
}


void ParticalSystem::draw(Camera* camera){
    m_billboardTechnique.enable();
    m_billboardTechnique.SetCameraPosition(camera->getPosition());
	glm::mat4 VP = glm::mat4(*camera->getViewMatrix())* (*camera->getProjectionMatrix());
    m_billboardTechnique.SetVP(&VP) ;
    //m_pTexture->Bind(COLOR_TEXTURE_UNIT);
    
    glDisable(GL_RASTERIZER_DISCARD);

    glBindBuffer(GL_ARRAY_BUFFER, m_particleBuffer[m_currTFB]);    

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), (const GLvoid*)4);  // position

    glDrawTransformFeedback(GL_POINTS, m_transformFeedback[m_currTFB]);

    glDisableVertexAttribArray(0);

	//flip buffer
	m_currVB = m_currTFB;
    m_currTFB = (m_currTFB + 1) & 0x1;
}


ParticalSystem::~ParticalSystem() {
}

