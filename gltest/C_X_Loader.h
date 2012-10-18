/* 
 * File:   C_X_Loader.h
 * Author: karsten
 *
 * Created on 16. oktober 2012, 13:45
 */

#ifndef C_X_LOADER_H
#define	C_X_LOADER_H




#include <iostream>
#include <fstream>
#include <sstream>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



#include <math.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include <list>
#include <map>


#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <algorithm> 
#include <cmath>

#include <functional> 
#include <cctype>
#include <locale>

#include "C_X_Loader.h"
using namespace std;

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

static inline GLfloat strTofloat(string str) {
	GLfloat intReturn;

	intReturn = atof(str.c_str());

	return (intReturn);
}

static inline int strToInt(string str) {
	int intReturn;

	intReturn = atoi(str.c_str());

	return (intReturn);
}




class CMesh;
CMesh* Lload(string file);
#endif	/* C_X_LOADER_H */

