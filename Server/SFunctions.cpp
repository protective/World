/* 
 * File:   SFunctions.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 09:57
 */

#include "SFunctions.h"
#include "Client.h"
#include "../Network/Serialize.h"
#include "World/SWorld.h"
#include "Command/SC_CastSTarget.h"
#include "objects/SCreature.h"
void sendtoC(Client* cli, char* buffer, uint32_t len){
	pthread_mutex_lock(&cli->networkSendLock);
		if (cli->networkSendLockBool)
			send(cli->getSocket(),buffer, len,MSG_NOSIGNAL);
	pthread_mutex_unlock(&cli->networkSendLock);
}

uint32_t getFreeID(){
	uint32_t ret;
	pthread_mutex_lock(&lockFreeID);
		freeIdCount++;
		ret = freeIdCount;
	pthread_mutex_unlock(&lockFreeID);
	return ret;
}

void* thread_Listen(){
	struct sockaddr_in stSockAddr;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(-1 == SocketFD)
    {
      perror("can not create socket");
      exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(11142);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;

    if(-1 == bind(SocketFD,(const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in)))
    {
      perror("error bind failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }

    if(-1 == listen(SocketFD, 10))
    {
      perror("error listen failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }

	for(;;){
		int ConnectFD = accept(SocketFD, NULL, NULL);
		cerr<<"connected time "<<SDL_GetTicks()<<endl;

		if(0 > ConnectFD){
			perror("error accept failed");
			close(SocketFD);
			exit(EXIT_FAILURE);
		}


		//create new client
		
		Client* cli = new Client(ConnectFD);
		cerr<<"connected "<<endl;
		pthread_mutex_lock(&lockClientList);
		clients.push_back(cli);
		pthread_mutex_unlock(&lockClientList);

		cerr<<"added to clients"<<endl;
		pthread_create(&(cli->listenThread), NULL, (void*(*)(void*))thread_Recive, cli);
		cerr<<"begin listen"<<endl;
		

	}

    close(SocketFD);
	return 0;
}


void* thread_Recive(Client* client){


	printf ("recv test....\n");
	int recsize;
	uint32_t timeout = 0;

	while(true){

		recsize = recv(client->getSocket(), (client->inputnetworkBuf->networkBuf) + client->inputnetworkBuf->recived, 512,0);

		if (recsize < 0){
			fprintf(stderr, "RECV  ERROR***********************\n");
			break;
		}
		if (recsize)
			timeout = 0;

		client->inputnetworkBuf->recived +=recsize;
		bool switchdone = false;
		while (!switchdone){
			usleep(1000);
			pthread_mutex_lock(&client->networkBufLock);
			//************************************
			//CRITICAL
			if (!client->parsingoutput){
				switchdone = client->switchBuffer();
			}
			//CRITICAL
			//************************************
			pthread_mutex_unlock(&client->networkBufLock);
		}
		timeout+=1;
		if (timeout < 20)
			usleep(400);
		else{
			cerr<<"timeout"<<endl;
			break;
		}
	}

	
	pthread_mutex_lock(&client->networkSendLock);
		client->networkSendLockBool = false;
	pthread_mutex_unlock(&client->networkSendLock);
	pthread_mutex_lock(&lockClientList);
	shutdown(client->getSocket(), SHUT_RDWR);

	close(client->getSocket());

	clients.remove(client);
	for(map<uint32_t, SGrid*>::iterator it = world->getGrids().begin(); it != world->getGrids().end();it++){
		//it->second->UnSubscribe(client);
	}
	cerr<<"Delete"<<endl;
	delete client;
	pthread_mutex_unlock(&lockClientList);
	pthread_exit(0);
}


void* ReadBuffer(Client* client){

		if (client->outputnetworkBuf->recived > 0){
			//************************************
			//CRITICAL
			pthread_mutex_lock(&client->networkBufLock);
			client->parsingoutput = true;
			pthread_mutex_unlock(&client->networkBufLock);
			//CRITICAL
			//************************************
			//if(printbufferbool)
			uint32_t delta = parseBuffer(client,client->outputnetworkBuf->recived);

			memmove(client->outputnetworkBuf->networkBuf, client->outputnetworkBuf->networkBuf+ delta, client->outputnetworkBuf->recived- delta);

			client->outputnetworkBuf->recived -= delta;

			//************************************
			//CRITICAL
			pthread_mutex_lock(&client->networkBufLock);
			client->parsingoutput = false;
			pthread_mutex_unlock(&client->networkBufLock);
			//CRITICAL
			//************************************
		}


}

uint32_t parseBuffer(Client* client, uint32_t len){
	char* buffer = client->outputnetworkBuf->networkBuf;
	uint32_t offset = 0;
	if (SPrintBuff)
		printBuffer(buffer,len);
	while (offset < len){
		SerialData* temp = (SerialData*)(buffer + offset);
		if (len - offset >= sizeof(uint32_t)*2 && temp->_size <= len - offset){


			switch(temp->_type)
			{
				case SerialType::SerialTime:{
					SerialTime* st = (SerialTime*)(buffer+offset);

					char message[sizeof(SerialTime)];
					memset(message,0,sizeof(SerialTime));

					SerialTime* data = (SerialTime*)(message);
					data->_type = SerialType::SerialTime;
					data->_size = sizeof(SerialTime);
					data->_sendtime = SDL_GetTicks();
					data->_local = st->_local;
					cerr<<"send Time "<<data->_sendtime<<endl;
					send(client->getSocket(),message,sizeof(SerialTime),0);

					break;
				}
				case SerialType::SerialReqJoin:{
					SerialReqJoin* st = (SerialReqJoin*)(buffer+offset);
					client->setPlayerId(st->_unitId);
					client->initTransfere();

					break;
				}
				case SerialType::SerialReqMove:{
					SerialReqMove* st = (SerialReqMove*)(buffer+offset);
					map<uint32_t,SObj*>::iterator unit =world->getObjs().find(st->_unitId);
					
					if (unit == world->getObjs().end())
						break;
					
					SPos pos;
					pos.x = st->_pos.x;
					pos.y = st->_pos.y;
					pos.z = st->_pos.z;
					pos.d = st->_pos.d;
					unit->second->reqMove(pos);
					
					break;
				}
				case SerialType::SerialReqActivatePowerT:{
					SerialReqActivatePowerT* st = (SerialReqActivatePowerT*)(buffer+offset);
					map<uint32_t,SObj*>::iterator unit =world->getObjs().find(st->_unitId);
					map<uint32_t,SObj*>::iterator target =world->getObjs().find(st->_targetId);
					
					if (unit == world->getObjs().end() || target == world->getObjs().end())
						break;
					if(!unit->second->getCreature())
						break;
					SPower* power = unit->second->getCreature()->getPower(st->_powerId);
					if(!power)
						break;
					
					SC_CastSTarget* cmd = new SC_CastSTarget(SDL_GetTicks(),unit->second,target->second,power);
					unit->second->addCommand(cmd);
					
					break;
				}				
				default:{
					cerr<<"error no packet parse function defined"<<endl;
					//offset = len;
					break;
				}
			}
			offset += temp->_size;
		}else{
			cerr<<"servermissing data"<<endl;
			break;
		}
			
	}
	//cerr<<"end parse  "<<endl;
	return offset;

}
uint32_t Rangeobj(SPos& pos1, SPos& pos2)
{
	int32_t p1x = pos1.x/100;
	int32_t p2x = pos2.x/100;
	int32_t p1y = pos1.y/100;
	int32_t p2y = pos2.y/100;

	return sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}




int32_t Direction(SPos& pos1, SPos& pos2){
	return Deg(pos2.x - pos1.x, pos2.y - pos1.y);
}