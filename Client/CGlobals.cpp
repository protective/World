/* 
 * File:   CGlobals.cpp
 * Author: karsten
 * 
 * Created on 24. april 2011, 13:54
 */

#include "CGlobals.h"
#include "CPlayerObjHandle.h"

#include "world/CWorld.h"
ConnectionStruct connection;
uint32_t tTime = 0;
pthread_mutex_t lockInput= PTHREAD_MUTEX_INITIALIZER;
CPlayerObjHandle* playerObj = new CPlayerObjHandle();
map<uint32_t,GLuint> textures;

CWorld* world = new CWorld();
uint32_t playerId;
map<uint32_t,uint8_t> teamlist;

FTGLPixmapFont font("/usr/share/fonts/truetype/msttcorefonts/Arial.ttf");


