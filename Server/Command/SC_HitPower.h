/* 
 * File:   SC_HitPower.h
 * Author: karsten
 *
 * Created on 26. december 2012, 21:09
 */

#ifndef SC_HITPOWER_H
#define	SC_HITPOWER_H

#include "SCommand.h"
class SPower;
class SObj;
class SC_HitPower : public SCommand {
public:
	SC_HitPower(uint32_t time, SObj* procesUnit, SObj* caster, SPower* power);
	virtual uint32_t execute();
	map<PowerProjectileMods::Enum, int32_t>& getValues(){return _values;}

	virtual ~SC_HitPower();
private:
	map<PowerProjectileMods::Enum, int32_t> _values;
	SPower* _power;
	SObj* _caster;
};

#endif	/* SC_HITPOWER_H */

