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





int strToInt(string str) {
	int intReturn;

	intReturn = atoi(str.c_str());

	return (intReturn);
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

