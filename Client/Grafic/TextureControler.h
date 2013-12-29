/* 
 * File:   TextureControler.h
 * Author: karsten
 *
 * Created on 26. december 2013, 18:37
 */

#ifndef TEXTURECONTROLER_H
#define	TEXTURECONTROLER_H

#include "../CFunctions.h"
class TextureControler {
public:
	TextureControler(Textures::Enum type);
	
	GLuint getTexture(uint32_t id);
	virtual ~TextureControler();
private:
	void LoadTextureGroup(string path);
	
	GLuint loadTexture(string file);
	GLuint load3DTexture(list<string> files);
	
	map<uint32_t,string> _texturePath;
	map<uint32_t,GLuint> _loadedTextures;
};

#endif	/* TEXTURECONTROLER_H */

