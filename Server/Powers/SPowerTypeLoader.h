/* 
 * File:   SPowerTypeLoader.h
 * Author: karsten
 *
 * Created on 5. november 2012, 17:34
 */

#ifndef SPOWERTYPELOADER_H
#define	SPOWERTYPELOADER_H

#include "SPowerType.h"
#include <pqxx/pqxx>

using namespace pqxx;

class SPowerTypeLoader {
public:
	SPowerTypeLoader();
	SPowerType* loadPower(uint32_t id);
	virtual ~SPowerTypeLoader();
private:
	connection* con;
};

#endif	/* SPOWERTYPELOADER_H */

