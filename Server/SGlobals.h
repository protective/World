/* 
 * File:   SGlobals.h
 * Author: karsten
 *
 * Created on 23. april 2011, 09:41
 */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <SDL/SDL.h>
#include <list>
#include <map>

//#include "Powers/SEffectType.h"
//#include "Powers/SEffectTypeAddBuff.h"
//#include "Sspacebjects/subsystems/SSubType.h"

#define NRTHREADS 2
#define PBaseSpellMiss 5
#define PBaseSpellCritBonus 1.5
#define PBaseSpellResist 5

#ifndef SGLOBALS_H
#define	SGLOBALS_H
using namespace std;
class Client;
class SWorld;
class SPowerType;
class SEffectType;
class SEffectTypeAddBuff;
extern SWorld* world;
extern list<Client*> clients;
extern pthread_mutex_t lockNetInput;
extern pthread_mutex_t lockClientList;
extern uint32_t freeIdCount;
extern pthread_mutex_t lockFreeID;
extern pthread_barrier_t  procesBar;
extern map<string,uint32_t> itemlistFileNames;
extern map<uint32_t,uint8_t> teamlist;
extern list<uint8_t> allteams;
extern bool SPrintBuff;
extern map<uint32_t, SPowerType*> GlobalPowerTypes;
extern map<uint32_t, SEffectType*> GlobalEffetTypes;
extern map<uint32_t, SEffectTypeAddBuff*> GlobalAddBuffTypes;
extern pthread_mutex_t lockServerTick;
extern uint32_t serverTick;
#endif	/* SGLOBALS_H */

