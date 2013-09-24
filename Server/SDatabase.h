/* 
 * File:   SDatabase.h
 * Author: karsten
 *
 * Created on 7. september 2011, 10:46
 */

#ifndef SDATABASE_H
#define	SDATABASE_H
#include "SFunctions.h"
#include "Powers/SEffectType.h"
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
	void loadPowersEffects(pqxx::work& w);
	void loadEffects(pqxx::work& w);
	
	void loadEffectsDD(pqxx::work& w, uint32_t id);
	void loadEffectsBuffDot(pqxx::work& w, uint32_t id);
	void loadEffectsBuffStatMod(pqxx::work& w, uint32_t id);
	void loadEffectsBuffTick(pqxx::work& w, uint32_t id);
	
	void creaturePowers(pqxx::work& w);
	
	//linking variables;
	
	map<uint32_t, SEffectType*> _effectypes;
};

#endif	/* SDATABASE_H */

