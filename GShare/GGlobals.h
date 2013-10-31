/* 
 * File:   GGlobals.h
 * Author: karsten
 *
 * Created on 23. april 2011, 11:04
 */

#ifndef GGLOBALS_H
#define	GGLOBALS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include "Enums.h"
#include "../Network/Serialize.h"
#define PI 3.14159265358979323846
using namespace std;
extern bool printbufferbool;
extern bool printposbufferbool;
extern map<SerialType::Enum, bool> printbufferSerial;
extern uint32_t Gtime;
extern double MySin[360];
extern double MyCos[360];
#endif	/* GGLOBALS_H */

