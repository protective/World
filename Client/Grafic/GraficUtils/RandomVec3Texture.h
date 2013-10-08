/* 
 * File:   RandomVec3Texture.h
 * Author: karsten
 *
 * Created on 6. oktober 2013, 22:40
 */

#ifndef RANDOMVEC3TEXTURE_H
#define	RANDOMVEC3TEXTURE_H
#include "../../GLutil.h"

class RandomVec3Texture {
public:
	RandomVec3Texture();
	~RandomVec3Texture();
	bool initRandomTexture(uint32_t Size);

    void Bind(GLenum TextureUnit);
private:
	GLuint _textureObj;
};

#endif	/* RANDOMVEC3TEXTURE_H */

