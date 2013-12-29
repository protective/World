/* 
 * File:   TextureControler.cpp
 * Author: karsten
 * 
 * Created on 26. december 2013, 18:37
 */

#include "TextureControler.h"
#include "sys/stat.h"
#include "Grafic.h"

TextureControler::TextureControler(Textures::Enum type) {
	if (type == Textures::Icons){
		LoadTextureGroup("Textures/Icons/icontexdef.conf");
	
	}
}
void TextureControler::LoadTextureGroup(string path){
	
	struct stat st;
	//DIR *dp;
	string prepatch= "../../../";
	if(stat("Textures",&st) == 0){
		prepatch= "" + path;
		//dp = opendir(datapath.c_str());
	}else{
		prepatch= "../../../"+path;
		//dp = opendir(datapath.c_str());
	}
	
	ifstream file(prepatch.c_str());
	string line;
	while (std::getline((file), line)) {
		uint32_t i = 0;
		uint32_t lastcharindex = 0;
		uint32_t parsing = 0;
		uint32_t texindex = 0;
		
		while(true){
			if (i == line.size() || line.at(i) == 9) {
				if (parsing == 0) {
					cerr<<"last"<<lastcharindex<<" "<<i-lastcharindex<<endl;
					texindex = strToInt(line.substr(lastcharindex, i-lastcharindex));
					cerr<<">>>"<<texindex<<"<<<"<<endl;
				}else if (parsing == 1){

				}else if (parsing >= 2) {
					_texturePath[texindex] = line.substr(lastcharindex,i-lastcharindex);	
					cerr<<">>>"<<_texturePath[texindex]<<"<<<"<<endl;
				}
				lastcharindex = i + 1;
				parsing++;
				if(i == line.size())
					break;
			}
			i++;
		}
	}
}
	
GLuint TextureControler::loadTexture(string file){
	SDL_Surface *surface;
	struct stat st;
	//DIR *dp;
	string prepatch= "../../../";
	if(stat("Textures",&st) == 0){
		prepatch= "" + file;
		//dp = opendir(datapath.c_str());
	}else{
		prepatch= "../../../" + file;
		//dp = opendir(datapath.c_str());
	}
	
	
	cerr<<"file>"<<prepatch<<endl;
	surface = IMG_Load(prepatch.c_str());
	if (!surface) {
		cerr<<"ERROR TextureControler::loadTexture load file"<<endl;
		return 0;
	}
	GLuint rettexture;
	GLenum texture_format;
	GLint  nOfColors;

	// get the number of channels in the SDL surface
	nOfColors = surface->format->BytesPerPixel;
	if (nOfColors == 4)     // contains an alpha channel
	{
			if (surface->format->Rmask == 0x000000ff)
					texture_format = GL_RGBA;
			else
					texture_format = GL_BGRA;
	} else if (nOfColors == 3)     // no alpha channel
	{
			if (surface->format->Rmask == 0x000000ff)
					texture_format = GL_RGB;
			else
					texture_format = GL_BGR;
	} else {
			printf("warning: the image is not truecolor..  this will probably break\n");
			// this error should not go unhandled
	}

	// Have OpenGL generate a texture object handle for us
	glGenTextures( 1, &rettexture );
	// Bind the texture object
	glBindTexture( GL_TEXTURE_2D, rettexture );

	// Set the texture's stretching properties
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
					  texture_format, GL_UNSIGNED_BYTE, surface->pixels );

	return rettexture;
}

GLuint TextureControler::load3DTexture(list<string> files){
	cerr<<"TextureControler::load3DTexture TODO IMPLEMENT "<<endl;
}

GLuint TextureControler::getTexture(uint32_t id){

	if(_loadedTextures.find(id) == _loadedTextures.end())
		_loadedTextures[id] = loadTexture(string("Textures/") + _texturePath[id]);
	return _loadedTextures[id];
}

TextureControler::~TextureControler() {
}

