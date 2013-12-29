


#include "Grafic.h"
#include "sys/stat.h"
#include "Model.h"

GLuint loadTexture(Textures::Enum texture){
	cerr<<"tb_ "<<texture<<endl;
	struct stat st;
	//DIR *dp;
	string prepatch= "../../../";
	if(stat("Textures",&st) == 0){
		prepatch= "";
		//dp = opendir(datapath.c_str());
	}else{
		prepatch= "../../../";
		//dp = opendir(datapath.c_str());
	}

	
	//string prepatch = "";
	string path;
	list<string> files;
	GLuint rettexture;

      switch (texture)
      {

		  case Textures::Partical:{
		    path = "Textures/Effects/Fire/";
			files.push_back("0010.png");
			files.push_back("0020.png");
			files.push_back("0060.png");
			files.push_back("0080.png");
			files.push_back("0110.png");
			files.push_back("0130.png");
			files.push_back("0140.png");
			files.push_back("0150.png");
            break;
		  }
         default:
            //path = "Textures/Icons/Icons/Armor/itempic0001.png";
			 path = "Textures/test2.png";
      }

	std::stringstream ss;
	ss <<  prepatch<< path;
	std::string s = ss.str();

	if(files.size()> 1)
		return load3DTexture(files, prepatch + path);
	
	SDL_Surface *surface;
	if ( (surface = IMG_Load(s.c_str())) ) {


		GLenum texture_format;
		GLint  nOfColors;

		// Check that the image's width is a power of 2
		if ( (surface->w & (surface->w - 1)) != 0 ) {
			printf("warning: image.bmp's width is not a power of 2\n");
		}

		// Also check if the height is a power of 2
		if ( (surface->h & (surface->h - 1)) != 0 ) {
			printf("warning: image.bmp's height is not a power of 2\n");
		}

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
	}else {
	printf("SDL could not load image.bmp: %s\n", SDL_GetError());
	return 0;
	}

}

GLuint load3DTexture(list<string> files, string filepath){
	SDL_Surface *surface;
	GLuint rettexture;
	string file = "";
	uint8_t* datablock = NULL;
	uint8_t* datapointer = NULL; 
	int bytePrPng = 0;
	int z = files.size();
	GLenum texture_format;
	GLint  nOfColors;
			
	while (files.size()){
		file = files.front();
		string s = ""; s.append(filepath); s.append(file);
		if (!(surface = IMG_Load(s.c_str()))) {
			cerr<<"ERROR loading 3d texture file"<<endl;
			return 0;
		}
		if(!datablock){
			// get the number of channels in the SDL surface
			nOfColors = surface->format->BytesPerPixel;
			if (nOfColors == 4){
				texture_format = surface->format->Rmask == 0x000000ff ? GL_RGBA: GL_BGRA;
			} else if (nOfColors == 3){
				texture_format = surface->format->Rmask == 0x000000ff ? GL_RGB : GL_BGR;
			} else {
				printf("warning: the image is not truecolor..  this will probably break\n");
			}
			
			bytePrPng = surface->w * surface->h * surface->format->BytesPerPixel;
			int datasize = (bytePrPng * files.size());
			datablock = new uint8_t[datasize];
			datapointer = datablock;
		}
		memcpy(datapointer, surface->pixels, bytePrPng);
		datapointer += bytePrPng; 
		files.pop_front();
	}
	
	//Begin generating texture;
	
	
	// Have OpenGL generate a texture object handle for us
	glGenTextures( 1, &rettexture);
	// Bind the texture object
	glBindTexture( GL_TEXTURE_3D, rettexture );

	// Set the texture's stretching properties
	glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage3D( GL_TEXTURE_3D, 0, nOfColors, surface->w, surface->h, z, 0,
					  texture_format, GL_UNSIGNED_BYTE, (void*)datablock );

	cerr<<rettexture<<endl;
	return rettexture;
	
}


void draw(Model* Model){

}

void Drawbox( float x, float y, float width, float hight, float r, float g, float b, float a )
{
	//cerr<<"ha"<<endl;
    glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
    glColor4f( r, g, b, a);
    glVertex4f( x, y + hight,0,1);
    glVertex4f( x+width, y + hight,0,1);
	glVertex4f( x+width, y,0,1);
	glVertex4f( x, y,0,1);
    glEnd();
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
}

