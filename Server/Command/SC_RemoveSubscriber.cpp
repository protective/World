/* 
 * File:   SC_RemoveSubscriber.cpp
 * Author: karsten
 * 
 * Created on 23. september 2013, 22:59
 */

#include "SC_RemoveSubscriber.h"
#include "../objects/SObj.h"
SC_RemoveSubscriber::SC_RemoveSubscriber(uint32_t time, SObj* procesUnit, Client* client):
SCommand(time,procesUnit){
	_client = client;
	
}

uint32_t SC_RemoveSubscriber::execute(){
	for(int i = 0; i< 3;i++)
		_procesUnit->getSubscribers()[i].remove(_client);
	return 0;
}

SC_RemoveSubscriber::~SC_RemoveSubscriber() {
}

