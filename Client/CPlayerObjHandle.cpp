/* 
 * File:   CPlayerObjHandle.cpp
 * Author: karsten
 * 
 * Created on 22. maj 2011, 15:32
 */


#include "CPlayerObjHandle.h"
#include "objects/CObj.h"
#include "objects/CCreature.h"
#include "Powers/CPower.h"
CPlayerObjHandle::CPlayerObjHandle() {
	_moveCounter = 0;
}

map<uint32_t,CObj*>& CPlayerObjHandle::getObjs(){
	return this->_objs;
}


void CPlayerObjHandle::recPower(SerialPower* st){
	map<uint32_t,CObj*>::iterator handle = _objs.find(st->_unitId);

	if(handle == _objs.end()){
		cerr<<"WARNING CPlayerObjHandle::recPower unit not found"<<endl;
		return;}

	CPower* power = new CPower(st->_powerId,handle->second,st->_iconId,st->_castTime);
	handle->second->getCreature()->getPowers()[st->_powerId] = power;
	
	power->setCD(st->_cd); 
}


void CPlayerObjHandle::recBeginCast(SerialBeginCast* st){
	map<uint32_t,CObj*>::iterator handle = _objs.find(st->_unitId);
	CCreature* creature;

	if(handle == _objs.end()){
		cerr<<"WARNING CPlayerObjHandle::recBeginCast not found"<<endl;
		return;
	}else
		creature = handle->second->getCreature();

	if(!creature){
		cerr<<"WARNING CPlayerObjHandle::recBeginCast not creature"<<endl;
		return;}
	
	creature->setCastCompletionTime(st->_castTime+st->_time);
	creature->setCastTime(st->_time);
}

void CPlayerObjHandle::recCast(SerialCast* st){
	map<uint32_t,CObj*>::iterator handle = _objs.find(st->_unitId);
	CCreature* creature;

	if(handle == _objs.end()){
		cerr<<"WARNING CPlayerObjHandle::recCast not creature"<<endl;
		return;
	}else
		creature = handle->second->getCreature();

	if(!creature){
		cerr<<"WARNING CPlayerObjHandle::recCast not creature"<<endl;
		return;}
	
	creature->setCastCompletionTime(0);
	creature->setCastTime(0);	
}


void CPlayerObjHandle::recCreature(SerialCreature* st){

	map<uint32_t,CObj*>::iterator handle = _objs.find(st->_unitId);
	CCreature* creature;

	if(handle == _objs.end()){
		CPos temp(st->_x,st->_y,st->_z,st->_d);
		creature = new CCreature(st->_unitId,0,temp);
		_objs[st->_unitId] = creature;
	}else
		creature = handle->second->getCreature();

	
	if(!creature){
		cerr<<"WARNING CPlayerObjHandle::recCreature not creature"<<endl;
		return;}

	if (st->_unitId== 2)
		_player = creature; 
	//handle->second->getCreature()->getPowers()[st->_powerId] = power;
}

CObj* CPlayerObjHandle::selectObject(int32_t x, int32_t y){
	cerr<<x<<" "<<y<<endl;
	for(map<uint32_t,CObj*>::iterator it = _objs.begin(); it != _objs.end();it++){
		cerr<<( Rangeobj((it->second->getPos().x-viewPos->x)*viewZoom, (it->second->getPos().y-viewPos->y)*viewZoom,x*100,y*100) <= 20*viewZoom/2)<<endl;
		if( Rangeobj((it->second->getPos().x-viewPos->x)*viewZoom, (it->second->getPos().y-viewPos->y)*viewZoom,x*100,y*100) <= 20*viewZoom/2){
			playerTarget = it->second;
			cerr<<"sel "<<it->second->getId()<<endl;
			break;
		}
	}

}


void CPlayerObjHandle::ServerReqActivatePower(CPower* power, CObj* target){
	if(power == NULL || target == NULL){
		cerr<<"WARNING CPlayerObjHandle::ServerReqActivatePower null values"<<endl;
		return;
	}
	char message[sizeof(SerialReqActivatePowerT)];
	memset(message,0,sizeof(SerialReqActivatePowerT));

	SerialReqActivatePowerT* data = (SerialReqActivatePowerT*)(message);
	data->_type = SerialType::SerialReqActivatePowerT;
	data->_size = sizeof(SerialReqActivatePowerT);
	data->_unitId = power->getOwner()->getId();
	data->_powerId = power->getId();
	data->_targetId = target->getId();
	cerr<<"req fire power"<<endl;
	
	send(connection.SocketFD,message,sizeof(SerialReqActivatePowerT),0);


}


void CPlayerObjHandle::ServerReqMove(CObj* obj){
	if(obj == NULL){
		cerr<<"WARNING CPlayerObjHandle::ServerReqMove null values"<<endl;
		return;
	}
	char message[sizeof(SerialReqMove)];
	memset(message,0,sizeof(SerialReqMove));

	SerialReqMove* data = (SerialReqMove*)(message);
	data->_type = SerialType::SerialReqMove;
	data->_size = sizeof(SerialReqMove);
	data->_time = getTime();
	data->_unitId = obj->getId();
	data->_pos.x = obj->getPos().x;
	data->_pos.y = obj->getPos().y;
	data->_pos.z = obj->getPos().z;
	data->_pos.d = obj->getPos().d;
	cerr<<"req move"<<endl;
	
	send(connection.SocketFD,message,sizeof(SerialReqMove),0);
}

void CPlayerObjHandle::procesPlayerUnit(uint32_t deltaTime){
	
	_moveCounter += deltaTime;
	if (_moveCounter > 25)
		_moveCounter = 0;
	if(!_player)
		return;
	
	if (keydown[SDLK_w]){
		_player->getPos().moveFw(deltaTime);
	}
	if (keydown[SDLK_s]){
		_player->getPos().moveBw(deltaTime);
	}
	if (keydown[SDLK_a]){
		_player->getPos().TurnL(deltaTime);
	}
	if (keydown[SDLK_d]){
		_player->getPos().TurnR(deltaTime);
	}
}