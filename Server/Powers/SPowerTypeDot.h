/* 
 * File:   SPowerTypeSpellDot.h
 * Author: karsten
 *
 * Created on 22. november 2012, 19:29
 */

#ifndef SPOWERTYPEDOT_H
#define	SPOWERTYPEDOT_H

#include "SPowerType.h"


class SPowerTypeDot : public SPowerType{
public:
	SPowerTypeDot(uint32_t id, uint32_t min, uint32_t max,  DamageTypes::Enum dmgType);
	virtual ~SPowerTypeDot();
private:

};

#endif	/* SPOWERTYPESPELLDOT_H */

