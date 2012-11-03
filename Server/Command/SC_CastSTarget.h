/* 
 * File:   SC_CastSTarget.h
 * Author: karsten
 *
 * Created on 1. november 2012, 17:39
 */

#ifndef SC_CASTSTARGET_H
#define	SC_CASTSTARGET_H

#include "SCommand.h"

class SPower;
class SCreature;
class SC_CastSTarget : public SCommand {
public:
	SC_CastSTarget(uint32_t time, SObj* unit, SPower* power, SCreature* target);
	virtual uint32_t execute();

	virtual ~SC_CastSTarget();
private:
	SPower* _power;
	SCreature* _target;
};

#endif	/* SC_CASTSTARGET_H */

