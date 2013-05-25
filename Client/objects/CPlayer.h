/* 
 * File:   CPlayer.h
 * Author: karsten
 *
 * Created on 27. april 2013, 13:33
 */

#ifndef CPLAYER_H
#define	CPLAYER_H
#include "CCreature.h"
class CPlayer : CCreature {
public:
	CPlayer(uint32_t id, uint32_t playerId, CPos pos);
	virtual ~CPlayer();
private:

};

#endif	/* CPLAYER_H */

