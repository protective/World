/* 
 * File:   SPowerSpellType.h
 * Author: karsten
 *
 * Created on 10. november 2012, 21:04
 */

#ifndef SPOWERSPELLTYPE_H
#define	SPOWERSPELLTYPE_H
#include "SPowerType.h"

class SPowerSpellType : public SPowerType {
public:
	SPowerSpellType(uint32_t id);
	uint32_t getSpellLevel(){return _spellLevel;}
	uint32_t getCd(){return _cd;}
	virtual ~SPowerSpellType();
protected:
	uint32_t _spellLevel;
	uint32_t _cd;
};

#endif	/* SPOWERSPELLTYPE_H */

