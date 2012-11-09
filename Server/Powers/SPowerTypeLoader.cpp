/* 
 * File:   SPowerTypeLoader.cpp
 * Author: karsten
 * 
 * Created on 5. november 2012, 17:34
 */

#include "SPowerTypeLoader.h"

SPowerTypeLoader::SPowerTypeLoader() {
	con = new connection("dbname=world");
}

SPowerType* SPowerTypeLoader::loadPower(uint32_t id){
	work worker(*con);

	pqxx::result r = worker.exec(
	"SELECT id "
	"FROM Powers "
	"WHERE name =");
}

SPowerTypeLoader::~SPowerTypeLoader() {
}

