/* 
 * File:   SDatabase.h
 * Author: karsten
 *
 * Created on 7. september 2011, 10:46
 */

#ifndef SDATABASE_H
#define	SDATABASE_H
#include "SFunctions.h"
#include <pqxx/pqxx>
#include <dirent.h>
class SDatabase {
public:
	SDatabase();
	void LoadAllItems();
	void ReadSubDir(DIR *dp, string datapath);
	void LoadGame();
	void LoadFromPostgres();
	virtual ~SDatabase();
private:
	void CheckRefs();
	void loadCreatures(pqxx::work& w);
	void loadCreatureStats(pqxx::work& w);
	void loadPowers(pqxx::work& w);
	void loadPowersStats(pqxx::work& w);
	void loadEffects(pqxx::work& w);
	void loadBuffs(pqxx::work& w);
	void loadBuffsStats(pqxx::work& w);
	void creaturePowers(pqxx::work& w);
};

#endif	/* SDATABASE_H */

