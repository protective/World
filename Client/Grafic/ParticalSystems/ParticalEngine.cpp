/* 
 * File:   ParticalEngine.cpp
 * Author: karsten
 * 
 * Created on 7. oktober 2013, 17:38
 */

#include "ParticalEngine.h"

ParticalEngine::ParticalEngine() {
}


bool ParticalEngine::InitParticleEngine(){
    if (m_updateTechnique.init()) {
        return false;
    }
	
	if (m_randomTexture.initRandomTexture(1000)) {
        return false;
    }
	
	if (m_billboardTechnique.init()) {
        return false;
    }
	cerr<<"DONE INIT PARTICLE ENGINE "<<endl;
}

ParticalEngine::~ParticalEngine() {
}

