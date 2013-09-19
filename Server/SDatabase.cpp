/* 
 * File:   SDatabase.cpp
 * Author: karsten
 * 
 * Created on 7. september 2011, 10:46
 */

#include <iterator>
#include <algorithm>
#include <map>

#include "SDatabase.h"
#include "World/SGrid.h"
#include "World/SWorld.h"
#include "sys/stat.h"

#include "objects/SCreature.h"
#include "Powers/SEffectTypeAddBuff.h"

void SDatabase::LoadFromPostgres(){
	pqxx::connection c("dbname= world user=karsten password=f1FF");
	pqxx::work w(c);
	
	loadCreatures(w);
	loadCreatureStats(w);
	loadPowers(w);
	loadPowersStats(w);
	loadEffects(w);
	loadBuffs(w);
	loadBuffsStats(w);
	creaturePowers(w);
	
}

void  SDatabase::loadCreatures(pqxx::work& w){
	try
	{
		pqxx::result r = w.exec("select id, team from creature;");
		SGrid* g = world->getGrids()[1];
		for(int i = 0; i< r.size(); i++){
			SPos p1(30000,10000*i,30000*i,0);
			int temp = r[i][0].as<uint32_t>();
			SCreature* o = new SCreature(r[i][0].as<uint32_t>(),p1 ,r[i][1].as<uint32_t>() ,0);
			g->addObj(o);

		}
	}
	catch (const std::exception &e)
	{
		cerr<<"ERROR SDatabase::loadCreatures"<<endl;
		std::cerr << e.what() << std::endl;
		return;
	}
}
	
void  SDatabase::loadCreatureStats(pqxx::work& w){
	try
	{
		pqxx::result r = w.exec("select id,stattype, value from creaturestats order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			SCreature* o = world->getObjs()[id]->getCreature();
			if(!o)
				continue;
			Attributes::Enum stat = (Attributes::Enum)r[i][1].as<uint32_t>();
			o->getAttibute()[stat] = r[i][2].as<int32_t>();
		}
	}
	catch (const std::exception &e)
	{
		cerr<<"ERROR SDatabase::loadCreatureStats"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
	
}
void  SDatabase::loadPowers(pqxx::work& w){
	try
	{
		pqxx::result r = w.exec("select id,image from powerType order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			uint32_t iconId = r[i][1].as<uint32_t>();
			string tt = toString(id);
			SPowerType* powert = new SPowerType(id,iconId);
			GlobalPowerTypes[id] = powert;

			pqxx::result r2 = w.exec("select stattype, value from powertypestats where id = " + tt + ";");
			for(int j = 0; j< r2.size(); j++){
				uint32_t statType = r2[j][0].as<uint32_t>();
				uint32_t statValue = r2[j][1].as<uint32_t>();
				powert->getStats()[(PowerTypeStats::Enum)statType] = statValue;
			}
		}
	}
	catch (const std::exception &e)
	{
		cerr<<"ERROR SDatabase::loadPowers"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
}
void  SDatabase::loadPowersStats(pqxx::work& w){
	try
	{
		pqxx::result r = w.exec("select id,stattype, value from powertypestats order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			SPowerType* o = GlobalPowerTypes[id];
			if(!o)
				continue;
			PowerTypeStats::Enum stat = (PowerTypeStats::Enum)r[i][1].as<uint32_t>();
			o->getStats()[stat] = r[i][2].as<int32_t>();
		}	
	}
	catch (const std::exception &e)
	{
		cerr<<"ERROR SDatabase::loadPowersStats"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}	
}
void  SDatabase::loadEffects(pqxx::work& w){

}
void  SDatabase::loadBuffs(pqxx::work& w){
	
	try{
		pqxx::result r = w.exec("select id, name from buff order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			string name = r[i][1].as<string>();
			SEffectTypeAddBuff* effect = new SEffectTypeAddBuff();
			GlobalAddBuffTypes[id] = effect;
		}	
	}
	catch (const std::exception &e){
		cerr<<"ERROR SDatabase::loadBuffs"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
	 	
}

void  SDatabase::loadBuffsStats(pqxx::work& w){

	try{
		pqxx::result r = w.exec("select id, stattype, value from buffstats order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			int32_t stattype = r[i][1].as<int32_t>();
			int32_t value = r[i][2].as<int32_t>();
			
			if(GlobalAddBuffTypes.find(id) != GlobalAddBuffTypes.end()){
				if (stattype >= 0){
					GlobalAddBuffTypes[id]->getStatsMods()[(StatsMods::Enum)stattype] = value;
				}
				
			}
		}	
	}
	catch (const std::exception &e){
		cerr<<"ERROR SDatabase::loadBuffs"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
	try{
		pqxx::result r = w.exec("select id, effect, value from buffvisualEffects order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			int32_t effect = r[i][1].as<uint32_t>();
			int32_t value = r[i][2].as<uint32_t>();
			
			if(GlobalAddBuffTypes.find(id) != GlobalAddBuffTypes.end()){
				GlobalAddBuffTypes[id]->getVisualEffects()[(BuffVisualEffects::Enum)effect] = value;
				
			}
			
		}	
	}
	catch (const std::exception &e){
		cerr<<"ERROR SDatabase::loadBuffs"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}	
	
	
}


void SDatabase::creaturePowers(pqxx::work& w){
	try
	{
		pqxx::result r = w.exec("select id, powertypeid from creaturePowers order by id;");
		for(int i = 0; i< r.size(); i++){
			uint32_t id = r[i][0].as<uint32_t>();
			SCreature* o = world->getObjs()[id]->getCreature();
			if(!o)
				continue;
			uint32_t powerid = r[i][1].as<uint32_t>();
			SPowerType* p = GlobalPowerTypes[powerid];
			if(!p)
				continue;

			SPower* po = new SPower(getFreeID(),o,p);
			o->addPower(po);
		}
	}
	catch (const std::exception &e)
	{
		cerr<<"ERROR SDatabase::creaturePowers"<<endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
}

int getAllparameter(string line, string key, uint32_t* returnbegin, uint32_t* returnlen) {
	uint32_t index = line.find(key) + key.size();
	if (index < line.size()) {
		while (line.at(index) == 32) {
			index++;
		}
		*returnbegin = index;

		while (index < line.size()) {
			index++;
		}
		*returnlen = index - (*returnbegin);
	}else{
		return 0;
	}
	
	return 1;
}


int getparameter(string line, string key, uint32_t nparam, uint32_t* returnbegin, uint32_t* returnlen) {
	uint32_t index = line.find(key) + key.size();
	for (int i = 0; i < nparam + 1; i++) {
		if (index < line.size()) {
			while (line.at(index) == 32) {
				index++;
			}
			*returnbegin = index;

			while (index < line.size() && line.at(index) != 32) {
				index++;
			}
			*returnlen = index - (*returnbegin);
		}else{
			return 0;
		}
	}
	return 1;
}



int getparameter(string line, string key, uint32_t nparam, uint32_t n2param, uint32_t* returnbegin, uint32_t* returnlen) {
	uint32_t index = line.find(key) + key.size();
	
	for (int i = 0; i < nparam + 1; i++) {
		if (index < line.size()) {
			while (line.at(index) == 32 && index < line.size()) {
				index++;
			}
			for(int j = 0; j < n2param +1; j++){
				if (index < line.size()) {
					while (line.at(index) == 58 && index < line.size()) {
						index++;
					}
					
					*returnbegin = index;
					while (index < line.size() && line.at(index) != 58) {
						if (line.at(index) == 32)
							break;
						index++;
					}
					
					*returnlen = index - (*returnbegin);
					if (index < line.size() && line.at(index) == 32)
						break;	
				}else{
					return 0;
				}
			}
			while (index < line.size()&&line.at(index) != 32 ) {
				index++;
			}
		}else{
			return 0;
		}
	}
	
	return 1;
}






void parseDataItemrefs(){

}
void ParseGame(ifstream* file,string filename){
	
	uint32_t beginint = 0;
	uint32_t lenint = 0;
	string parseState = "";
	string parseSubState = "";
	string line;

	cerr<<"fname "<<filename<<endl;
	while (std::getline((*file), line)) {

		if (line.find("//") != string::npos)
			continue;
		

	}
}

void ParseData(ifstream* file,string filename) {
	uint32_t id = 0;


	if (filename.find("itemtexname.txt", 0) != string::npos)
		return;
	if (filename.find("objtexname.txt", 0) != string::npos)
		return;
	if (filename.find("shottexname.txt", 0) != string::npos)
		return;
	if (!id){
		cerr<<"WARNING Sdatabase::parsedata itemfilename not found"<<endl;
	}
	uint32_t beginint = 0;
	uint32_t lenint = 0;
	string parseState = "";
	string parseSubState = "";
	string line;

	cerr<<filename<<endl;
	while (std::getline((*file), line)) {
		
		if (line.find("//") != string::npos)
			continue;
		}
	
}

SDatabase::SDatabase() {

}

void SDatabase::LoadGame() {
	DIR *dp;
	struct dirent *ep;
	struct stat st;
	string datapath = "";
	if(stat("Games",&st) == 0){
		datapath= "Games";
		dp = opendir(datapath.c_str());
	}else{
		datapath= "../../../Games";
		dp = opendir(datapath.c_str());
	}
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			if (string(ep->d_name) != "." && string(ep->d_name) != "..") {
				string temp = datapath + (string) "/" + string(ep->d_name);
				ifstream file(temp.c_str());
				ParseGame(&file,string(ep->d_name));
				break;
			}
		}
		(void) closedir(dp);
	} else {
		cerr << "ERROR dir not found" << endl;
	}
}
















void SDatabase::ReadSubDir(DIR *dp, string datapath){
	struct dirent *ep;
	if (dp != NULL) {
		while (ep = readdir(dp)) {
			if (string(ep->d_name) != "." && string( ep->d_name) != "..") {
				string temp = datapath + (string) "/" + string(ep->d_name);			
				DIR *dp;
				dp = opendir(temp.c_str());
				if(dp){
					ReadSubDir(opendir(temp.c_str()),temp);
				}else{
					ifstream file(temp.c_str());
					ParseData(&file,string(ep->d_name));
				}
			}
		}
		(void) closedir(dp);
	}
}

void SDatabase::LoadAllItems() {

	parseDataItemrefs();
	DIR *dp;
	struct dirent *ep;

	uint32_t susi = 1;
	struct stat st;
	string datapath = "";
	if(stat("database",&st) == 0){
		datapath= "database";
		dp = opendir(datapath.c_str());
	}else{
		datapath= "../../../database";
		dp = opendir(datapath.c_str());
	}
	if (dp != NULL) {
		ReadSubDir(dp,datapath);
	}

}



void SDatabase::CheckRefs(){
	
}

SDatabase::~SDatabase() {
}

