/* 
 * File:   ParticalUpShader.cpp
 * Author: karsten
 * 
 * Created on 2. oktober 2013, 11:53
 */

#include "ParticalUpShader.h"

ParticalUpShader::ParticalUpShader() {
}



uint32_t ParticalUpShader::init(){
	cerr<<"INIT ParticalUpShader SHADER"<<endl;
	if(ShaderProgram::init())
		return 1;
	
	if(addShader(new Shader("../../../Grafic/Shaders/ParticalUpVertexShader.glsl", GL_VERTEX_SHADER)))
		return 2;
	
	if(addShader(new Shader("../../../Grafic/Shaders/ParticalUpGeometryShader.glsl", GL_GEOMETRY_SHADER)))
		return 3;
	
	if(finalize())
		return 5;
	
	
	//TODO 
	//Add locations to uniforms in the geometryshader
	
	//_VPMatrix = getUniformLocation("VPMatrix");
	//_ProjectionMatrix = getUniformLocation("ProjectionMatrix");	
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

/*
void ParticalUpShader::SetRandomTextureUnit(unsigned int TextureUnit)
{    
    glUniform1i(m_randomTextureLocation, TextureUnit);
}
*/

void ParticalUpShader::SetLauncherLifetime(float Lifetime)
{
    glUniform1f(m_launcherLifetimeLocation, Lifetime);
}


void ParticalUpShader::SetShellLifetime(float Lifetime)
{
    glUniform1f(m_shellLifetimeLocation, Lifetime);
}
