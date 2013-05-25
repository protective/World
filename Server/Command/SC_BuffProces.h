/* 
 * File:   SC_BuffProces.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:16
 */

#ifndef SC_BUFFPROCES_H
#define	SC_BUFFPROCES_H

#include "SCommand.h"

class SObj;
class SBuff;
class SC_BuffProces : public SCommand {
public:
	SC_BuffProces(uint32_t time, SObj* procesUnit, SObj* caster, SBuff* buff);
	virtual uint32_t execute();
	SObj* getCaster(){return _caster;}
	virtual ~SC_BuffProces();
private:
	SBuff* _buff;
	SObj* _caster;
};

#endif	/* SC_BUFFPROCES_H */

