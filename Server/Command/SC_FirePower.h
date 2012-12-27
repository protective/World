/* 
 * File:   SC_FirePower.h
 * Author: karsten
 *
 * Created on 26. december 2012, 21:08
 */

#ifndef SC_FIREPOWER_H
#define	SC_FIREPOWER_H
#include "SCommand.h"
class SPower;
class SCreature;
class SC_FirePower : public SCommand{
public:
	SC_FirePower(uint32_t time, SObj* caster, SObj* target, SPower* power);
	virtual uint32_t execute();
	virtual ~SC_FirePower();
private:

	SPower* _power;
};

#endif	/* SC_FIREPOWER_H */

