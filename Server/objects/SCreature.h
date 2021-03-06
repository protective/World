/* 
 * File:   SCreature.h
 * Author: karsten
 *
 * Created on 1. november 2012, 22:52
 */

#ifndef SCREATURE_H
#define	SCREATURE_H
#include "SObj.h"
#include "../Powers/SPower.h"
#include "Buffs/SBuff.h"
#include "../Command/SC_ObjProces.h"
class SCreature : public SObj {
public:
	SCreature(uint32_t id, SPos pos, uint32_t team, uint32_t playerId);
	virtual ~SCreature();
	virtual SCreature* getCreature(){return this;}
	SPower* getPower(uint32_t id){if(_powerList.find(id) != _powerList.end())return _powerList[id];else return NULL;}
	virtual void addPower(SPower* power);
	map<Attributes::Enum , int32_t>& getAttibute(){return _attribute;}
	void SetAttributes(Attributes::Enum attri,int32_t value);
	void transmitAttribute(Attributes::Enum attri);
	map<uint32_t,SBuff*>& getBuffList(){return _bufflist;}
	uint32_t addBuff(SBuff* buff);
	uint32_t addBuff(SBuff* buff, uint32_t time);
	uint32_t removeBuff(SBuff* buff);
	virtual bool readyCast(){if (_casting) return false;return true;}
	void setCasting(SPower* casting);
	void sendToClient(Client* cli);
	int32_t modMana(int32_t mana);
	int32_t modFocus(int32_t focus);
	void updateAttribute();
private:
	map<uint32_t,SPower*> _powerList;
	map<Attributes::Enum , int32_t> _attribute;
	map<Attributes::Enum , int32_t> _BaseAttribute;
	map<uint32_t,SBuff*> _bufflist;
	SPower* _casting;
	map<SC_ObjProcesTask::Enum,SC_ObjProces*> _procesTask;
};

#endif	/* SCREATURE_H */

