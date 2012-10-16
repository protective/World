/* 
 * File:   SGrid.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 16:42
 */

#include "SGrid.h"
#include "SWorld.h"
#include "../Client.h"

SGrid::SGrid(uint32_t id) {
	this->_id = id;
	_spaceHight = 10;
	_spaceWight = 10;
	pthread_mutex_init(&this->locksubscriber, NULL);
	pthread_mutex_init(&this->lockgrid, NULL);
	cerr<<"init grid"<<endl;
}

SGrid::SGrid(uint32_t id, uint32_t spaceWight, uint32_t spaceHight) {
	this->_id = id;
	_spaceHight = spaceHight;
	_spaceWight = spaceWight;
	pthread_mutex_init(&this->locksubscriber, NULL);
	pthread_mutex_init(&this->lockgrid, NULL);
	cerr<<"init grid"<<endl;
}

void SGrid::addObj(SObj* obj){
	pthread_mutex_lock(&this->lockgrid);
	this->objToAdd[obj->getId()] = obj;
	pthread_mutex_unlock(&this->lockgrid);
}

void SGrid::removeObj(SObj* obj){

}


SGrid::~SGrid() {
}

