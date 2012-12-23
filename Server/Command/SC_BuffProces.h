/* 
 * File:   SC_BuffProces.h
 * Author: karsten
 *
 * Created on 20. december 2012, 22:16
 */

#ifndef SC_BUFFPROCES_H
#define	SC_BUFFPROCES_H

#include "SCommand.h"


class SC_BuffProces : public SCommand {
public:
	SC_BuffProces(uint32_t time, SObj* caster, SObj* target, SBuff* buff);
	virtual uint32_t execute();
	virtual ~SC_BuffProces();
private:
	SBuff* _buff;
};

#endif	/* SC_BUFFPROCES_H */

