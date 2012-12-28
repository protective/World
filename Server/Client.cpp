/* 
 * File:   Client.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 10:00
 */

#include <vector>

#include "Client.h"
#include "World/SWorld.h"
//#include "Sspacebjects/subsystems/SShipTypeSlotData.h"

Client::Client(int socket) {

	this->socket = socket;
	playerID = 0;
	_teamId = 2;
	this->parsingoutput = false;
	this->active_buffer = 1;
	this->networkBuf1.recived = 0;
	this->networkBuf2.recived = 0;
	pthread_mutex_init(&this->networkBufLock, NULL);
	pthread_mutex_init(&this->networkSendLock, NULL);
	pthread_mutex_init(&this->locksubscriber, NULL);
	
	pthread_mutex_lock(&this->networkSendLock);
	networkSendLockBool = true;
	pthread_mutex_unlock(&this->networkSendLock);
	//this->switchBuffer();
	inputnetworkBuf = &networkBuf1;
	outputnetworkBuf = &networkBuf2;




	cerr << "create client" << endl;
}


void Client::initTransfere(){
	for (map<uint32_t,SObj*>::iterator it = world->getGrids()[1]->getObjInGrid().begin(); it != world->getGrids()[1]->getObjInGrid().end(); it++){
		it->second->getSubscribers().push_back(this);
	}
			
	cerr<<"data sendt"<<endl;
}

/*
void Client::sendGrids() {
	for (map<uint32_t, SGrid*>::iterator it = world->getGrids().begin(); it != world->getGrids().end(); it++) {

		char message[sizeof (SerialGrid)];
		memset(message, 0, sizeof (SerialGrid));

		SerialGrid* data = (SerialGrid*) (message);
		data->_type = SerialType::SerialGrid;
		data->_size = sizeof (SerialGrid);
		data->_Id = it->second->_id;
		data->_wight = it->second->getWight();
		data->_hight = it->second->getHight();

		send(this->getSocket(), message, sizeof (SerialGrid), 0);

	}

}
 * */
Client::~Client() {
}

