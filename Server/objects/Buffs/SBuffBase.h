/* 
 * File:   SBuffBase.h
 * Author: karsten
 *
 * Created on 22. november 2012, 20:02
 */

#ifndef SBUFFBASE_H
#define	SBUFFBASE_H
#include "../../SFunctions.h"
#include "../../Command/SC_BuffProces.h"
class SBuff;
class SBuffBase {
public:
	SBuffBase(SBuff* buff);
	virtual uint32_t proces(SC_BuffProces* cmd, uint32_t tickCount){}
	virtual ~SBuffBase();
protected:
	SBuff* _buff;
};

#endif	/* SBUFFBASE_H */

