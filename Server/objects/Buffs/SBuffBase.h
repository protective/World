/* 
 * File:   SBuffBase.h
 * Author: karsten
 *
 * Created on 22. november 2012, 20:02
 */

#ifndef SBUFFBASE_H
#define	SBUFFBASE_H
#include "../../SFunctions.h"

class SBuffBase {
public:
	SBuffBase();
	virtual uint32_t proces(uint32_t tickCount){}
	virtual ~SBuffBase();
private:

};

#endif	/* SBUFFBASE_H */

