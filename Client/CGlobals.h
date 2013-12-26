/* 
 * File:   CGlobals.h
 * Author: karsten
 *
 * Created on 24. april 2011, 13:54
 */

#ifndef CGLOBALS_H
#define	CGLOBALS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
//include "SDL/SDL_opengl.h"
#include <GL/glew.h>
//#include "GL/gl.h"
#include <pthread.h>
#include <cstdlib>
#include "../GShare/GFunctions.h"


#include <FTGL/ftgl.h>
class CPlayerObjHandle;
class CObj;
class UIMainFrame;
class CPos;
class CWorld;
class screenControler;
using namespace std;

struct ConnectionStruct{
	int SocketFD;
	char* messagebuffer;
	char* messagepointer;
	bool connected;
	pthread_t listenThread;
};

struct CPlayercolour{
	CPlayercolour(double r,double g,double b){_r = r; _g = g; _b = b;}
	CPlayercolour(){}
	double _r;
	double _g;
	double _b;
};



extern pthread_mutex_t lockInput;
extern ConnectionStruct connection;
extern uint32_t tTime;
extern CPlayerObjHandle* playerObj;
extern map<uint32_t,GLuint> textures;
extern map<uint32_t, GLuint> iconTextures;
extern CWorld* world;
extern CObj* playerSels;
extern CObj* playerTarget;
extern list<CObj*> playerMultiSels;

extern uint32_t GlobalPlayerId;
extern map<uint32_t,uint8_t> teamlist;
extern CPos* viewPos;
extern double viewZoom;
extern double viewRZoom;
extern FTGLPixmapFont font;
extern map<uint32_t, CPlayercolour> playercolour;
extern UIMainFrame* mainFrame;
extern map<SDLKey,bool> keydown;
extern bool CPrintBuff;
extern screenControler* masterScreen;
#endif	/* CGLOBALS_H */

