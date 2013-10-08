/* 
 * File:   ParticalUpShader.cpp
 * Author: karsten
 * 
 * Created on 2. oktober 2013, 11:53
 */

#include "ParticalUpShader.h"

ParticalUpShader::ParticalUpShader() {
	cerr<<"Create ParticalUpShader"<<endl;
}



uint32_t ParticalUpShader::init(){
	cerr<<"INIT ParticalUpShader SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/ParticalSystems/ParticalUpVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/ParticalSystems/ParticalUpGeometryShader.glsl", GL_GEOMETRY_SHADER)))
		return 3;
	
	const GLchar* Varyings[4];    
    Varyings[0] = "Type1";
    Varyings[1] = "Position1";
    Varyings[2] = "Velocity1";    
    Varyings[3] = "Age1";
    
    glTransformFeedbackVaryings(_id, 4, Varyings, GL_INTERLEAVED_ATTRIBS);

	
	
	if(finalize())
		return 5;
	
	
	//TODO 
	//Add locations to uniforms in the geometryshader
	
	m_deltaTimeMillisLocation = getUniformLocation("gDeltaTimeMillis");
	m_randomTextureLocation = getUniformLocation("gRandomTexture");
	m_timeLocation = getUniformLocation("gTime");
	m_launcherLifetimeLocation = getUniformLocation("gLauncherLifetime");
	m_shellLifetimeLocation =  getUniformLocation("gShellLifetime");
	
	return 0;
}


ParticalUpShader::~ParticalUpShader() {
}

void ParticalUpShader::SetDeltaTimeMillis(unsigned int DeltaTimeMillis)
{
    glUniform1f(m_deltaTimeMillisLocation, (float)DeltaTimeMillis);
}


void ParticalUpShader::SetTime(int Time)
{
    glUniform1f(m_timeLocation, (float)Time);
}


void ParticalUpShader::SetRandomTextureUnit(unsigned int TextureUnit)
{    
    glUniform1i(m_randomTextureLocation, TextureUnit);
}


void ParticalUpShader::SetLauncherLifetime(float Lifetime)
{
    glUniform1f(m_launcherLifetimeLocation, Lifetime);
}


void ParticalUpShader::SetShellLifetime(float Lifetime)
{
    glUniform1f(m_shellLifetimeLocation, Lifetime);
}
