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
class SCreature : public SObj {
public:
	SCreature(uint32_t id, SPos pos, uint8_t team, uint32_t playerId);
	virtual ~SCreature();
	virtual SCreature* getCreature(){return this;}
	SPower* getPower(uint32_t id){if(_powerList.find(id) != _powerList.end())return _powerList[id];else return NULL;}
	virtual void addPower(SPower* power);
	map<Attributes::Enum , uint32_t>& getAttibute(){return _attribute;}
	map<uint32_t,SBuff*>& getBuffList(){return _bufflist;}
	uint32_t addBuff(SBuff* buff);
	uint32_t removeBuff(SBuff* buff);
	virtual bool readyCast(){if (_casting) return false;return true;}
	void setCasting(SPower* casting){_casting = casting;}
	void sendToClient(Client* cli);
	void updateAttribute();
private:
	map<uint32_t,SPower*> _powerList;
	map<Attributes::Enum , uint32_t> _attribute;
	map<Attributes::Enum , uint32_t> _BaseAttribute;
	map<uint32_t,SBuff*> _bufflist;
	SPower* _casting;
};

#endif	/* SCREATURE_H */

