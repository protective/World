/* 
 * File:   ParticalUpShader.h
 * Author: karsten
 *
 * Created on 2. oktober 2013, 11:53
 */

#ifndef PARTICALUPSHADER_H
#define	PARTICALUPSHADER_H
#include "../ShaderProgram.h"


class ParticalUpShader : public ShaderProgram {
public:
	ParticalUpShader();
	uint32_t init();
	void SetParticleLifetime(float Lifetime);
    void SetDeltaTimeMillis(unsigned int DeltaTimeMillis); 
    void SetTime(int Time);
    void SetLauncherLifetime(float Lifetime);
    void SetShellLifetime(float Lifetime);
	
	virtual ~ParticalUpShader();
private:
	GLuint m_deltaTimeMillisLocation;
	GLuint m_randomTextureLocation;
	GLuint m_timeLocation;
	GLuint m_launcherLifetimeLocation;
	GLuint m_shellLifetimeLocation;
};

#endif	/* PARTICALUPSHADER_H */

