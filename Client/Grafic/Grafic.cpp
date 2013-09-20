


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
	GLuint rettexture;

      switch (texture)
      {

         //case Textures::Icons1:
            //path = "Textures/Icons/iconsheet.png";
        //    break;

         default:
            //path = "Textures/Icons/Icons/Armor/itempic0001.png";
			 path = "Textures/test2.png";
      }

	std::stringstream ss;
	ss <<  prepatch<< path;
	std::string s = ss.str();

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
		cerr<<"tc_ "<<rettexture<<endl;
		// Bind the texture object
		glBindTexture( GL_TEXTURE_2D, rettexture );

		// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		// Edit the texture object's image data using the information SDL_Surface gives us
		glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
						  texture_format, GL_UNSIGNED_BYTE, surface->pixels );

		cerr<<"td_ "<<rettexture<<endl;
		return rettexture;
	}else {
	printf("SDL could not load image.bmp: %s\n", SDL_GetError());
	return 0;
	}

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

