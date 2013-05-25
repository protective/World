/* 
 * File:   SC_KillUnit.h
 * Author: karsten
 *
 * Created on 16. november 2012, 23:58
 */

#ifndef SC_KILLUNIT_H
#define	SC_KILLUNIT_H
#include "SCommand.h"

class SC_KillUnit : public SCommand {
public:
	SC_KillUnit(uint32_t time, SObj* procesUnit, SObj* caster);
	virtual uint32_t execute();
	virtual ~SC_KillUnit();
private:
	SObj* _caster;	
};

#endif	/* SC_KILLUNIT_H */

