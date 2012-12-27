/* 
 * File:   SBuffStat.h
 * Author: karsten
 *
 * Created on 22. november 2012, 20:02
 */

#ifndef SBUFFSTAT_H
#define	SBUFFSTAT_H

#include "SBuffBase.h"


class SBuffStat : public SBuffBase {
public:
	SBuffStat(SBuff* buff, StatsMods::Enum stat, int32_t value);
	virtual SBuffStat* getBuffStat(){return this;}
	StatsMods::Enum getStat(){return _stat;}
	int32_t getValue(){return _value;}
	virtual ~SBuffStat();
private:
	StatsMods::Enum _stat;
	int32_t _value;
};

#endif	/* SBUFFSTAT_H */

