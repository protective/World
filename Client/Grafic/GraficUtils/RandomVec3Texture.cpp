/* 
 * File:   RandomVec3Texture.cpp
 * Author: karsten
 * 
 * Created on 6. oktober 2013, 22:40
 */

#include "RandomVec3Texture.h"
#include "../../CFunctions.h"
RandomVec3Texture::RandomVec3Texture() {
	cerr<<"Create RandomVec3Texture"<<endl;
}

bool RandomVec3Texture::initRandomTexture(uint32_t Size)
{
	glm::vec3* pRandomData = new glm::vec3[Size];
    for (unsigned int i = 0 ; i < Size ; i++) {
        pRandomData[i].x = (float)myrandom(0,10000)/10000.0f;
        pRandomData[i].y = (float)myrandom(0,10000)/10000.0f;
        pRandomData[i].z = (float)myrandom(0,10000)/10000.0f;
    }
        
    glGenTextures(1, &_textureObj);
    glBindTexture(GL_TEXTURE_1D, _textureObj);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, Size, 0, GL_RGB, GL_FLOAT, pRandomData);
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);    
    
    delete [] pRandomData;
    
    return 0;
}

void RandomVec3Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(GL_TEXTURE_1D, _textureObj);
}

RandomVec3Texture::~RandomVec3Texture()
{
    if (_textureObj != 0) {
        glDeleteTextures(1, &_textureObj);
    }
}
