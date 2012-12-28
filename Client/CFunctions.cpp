/* 
 * File:   CFunctions.cpp
 * Author: karsten
 * 
 * Created on 24. april 2011, 13:54
 */

#include "CFunctions.h"
#include "objects/CObj.h"



#include "CDatabase.h"

#include "world/CWorld.h"

uint32_t getTime(){
	return SDL_GetTicks()+Gtime;
}

void* Connect(string ip, uint32_t playerid, uint32_t pass){

	struct sockaddr_in stSockAddr;

    int Res;
    connection.SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (-1 == connection.SocketFD)
    {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(11142);
    Res = inet_pton(AF_INET, ip.c_str(), &stSockAddr.sin_addr);

    if (0 > Res)
    {
      perror("error: first parameter is not a valid address family");
      close(connection.SocketFD);
      exit(EXIT_FAILURE);
    }
    else if (0 == Res)
    {
      perror("char string (second parameter does not contain valid ipaddress");
      close(connection.SocketFD);
      exit(EXIT_FAILURE);
    }

	if (-1 == connect(connection.SocketFD, (const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in))){
		perror("connect failed");
		close(connection.SocketFD);
		exit(EXIT_FAILURE);
	}
	//while (true){
	cerr<<"connected time "<<SDL_GetTicks()<<endl;
	connection.connected = true;


	pthread_create(&connection.listenThread, NULL, (void*(*)(void*))thread_Recive, NULL);
		char message[sizeof(SerialReqJoin)];
		memset(message,0,sizeof(SerialReqJoin));

		SerialReqJoin* data = (SerialReqJoin*)(message);
		data->_type = SerialType::SerialReqJoin;
		data->_size = sizeof(SerialReqJoin);
		data->_unitId = playerid; //TODO BIG TODO FIX THIS SOOON
		playerId = playerid;
		data->_pass = pass;
		send(connection.SocketFD,message,sizeof(SerialReqJoin),0);


		for (int i = 0; i < 5; i++){
			char message2[sizeof(SerialTime)];
			memset(message2,0,sizeof(SerialTime));

			SerialTime* data2 = (SerialTime*)(message2);
			data2->_type = SerialType::SerialTime;
			data2->_size = sizeof(SerialTime);
			data2->_sendtime = 0;
			data2->_local = SDL_GetTicks();
			cerr<<"send Time req"<<data2->_local<<endl;

			send(connection.SocketFD,message2,sizeof(SerialTime),0);

			usleep(200000);
		}
  }



void* thread_Recive(){

		connection.messagebuffer = (char*)malloc(1024);
		memset(connection.messagebuffer,0,1024);
		printf ("recv test....\n");
		int recsize;

		int recived = 0;
		uint32_t delta = 0;

	
		while(connection.connected){

			recsize = recv(connection.SocketFD, connection.messagebuffer + recived, 512,0);

			if (recsize < 0)
					fprintf(stderr, "error\n");
			recived +=recsize;

			if (recived >= 1){
				delta = 1;
				while (delta){
					pthread_mutex_lock(&lockInput);
					delta = parseBuffer(connection.messagebuffer,recived);
					pthread_mutex_unlock(&lockInput);
					memmove(connection.messagebuffer, connection.messagebuffer+ delta, 1024- delta);
					recived -= delta;
				}
			}
			usleep(40);
		}


		shutdown(connection.SocketFD, SHUT_RDWR);

		close(connection.SocketFD);
		pthread_exit(0);
}




uint32_t parseBuffer(char* buffer, uint32_t len){
	uint32_t offset = 0;
	printBuffer(buffer,len);
	while (offset < len){
		SerialData* meta = (SerialData*)(buffer + offset);

		if (len - offset >= sizeof(uint32_t)*2 && meta->_size <= len - offset){


			switch(meta->_type)
			{
				case SerialType::SerialTime:{
					SerialTime* st = (SerialTime*)(buffer+offset);
					cerr<<"recived time req"<<st->_sendtime<< " local "<<SDL_GetTicks()<<endl;
					uint32_t tem = st->_sendtime + ((SDL_GetTicks()-st->_local)/2);

					Gtime += tem -SDL_GetTicks();

					tTime ++;
					cerr<<"t"<<tTime<<endl;
					if (tTime == 5){
						Gtime = Gtime/5;
						cerr<<"final Gtime "<<Gtime<<endl;
					}
					break;

				}
				case SerialType::SerialBeginCast:{
					SerialBeginCast* st = (SerialBeginCast*)(buffer+offset);
					break;
				}				
				case SerialType::SerialCast:{
					SerialCast* st = (SerialCast*)(buffer+offset);
					break;
				}
				case SerialType::SerialTakeDmgHeal:{
					SerialTakeDmgHeal* st = (SerialTakeDmgHeal*)(buffer+offset);
					break;
				}
				default:{
					cerr<<"ERROR PARSING debug recived = "<<(uint32_t) *(buffer+offset)<<endl;

					break;
				}
			}
				offset += meta->_size;
		}else{
			//cerr<<"missing data "<<endl;
			break;
		}
	}
	//updateFrames();
	return offset;
}

  void* Disconnect(){

	cerr<<"Disconnect"<<endl;
	shutdown(connection.SocketFD, SHUT_RDWR);

	close(connection.SocketFD);
	connection.connected = false;
	pthread_join(connection.listenThread, NULL);
  }

uint32_t Rangeobj(CPos& pos1, CPos& pos2)
{
	int32_t p1x = pos1.x/100;
	int32_t p2x = pos2.x/100;
	int32_t p1y = pos1.y/100;
	int32_t p2y = pos2.y/100;

	//cerr<<"p1x "<<pos1.x<<" p2x "<<pos2.x<<" p1y "<<pos1.y<<" p2y "<<pos2.y<<endl;
	return sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}

uint32_t Rangeobj(CPos& pos1, int32_t x2, int32_t y2)
{
	int32_t p1x = pos1.x/100;
	int32_t p2x = x2/100;
	int32_t p1y = pos1.y/100;
	int32_t p2y = y2/100;

	//cerr<<"p1x "<<pos1.x<<" p2x "<<pos2.x<<" p1y "<<pos1.y<<" p2y "<<pos2.y<<endl;
	return sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}

uint32_t Rangeobj(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
	int32_t p1x = x1/100;
	int32_t p2x = x2/100;
	int32_t p1y = y1/100;
	int32_t p2y = y2/100;

	//cerr<<"p1x "<<pos1.x<<" p2x "<<pos2.x<<" p1y "<<pos1.y<<" p2y "<<pos2.y<<endl;
	return sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}






