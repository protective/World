/* 
 * File:   SBuff.h
 * Author: karsten
 *
 * Created on 17. november 2012, 21:31
 */

#ifndef SBUFF_H
#define	SBUFF_H

#include "SBuffBase.h"


class SBuff {
public:
	SBuff();
	list<SBuffBase*>& getEffects(){return _effects;} 
	virtual ~SBuff();
private:
	list<SBuffBase*> _effects;
};

#endif	/* SBUFF_H */

