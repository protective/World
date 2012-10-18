/* 
 * File:   C_X_ReaderNormals.cpp
 * Author: karsten
 * 
 * Created on 18. oktober 2012, 13:42
 */

#include "C_X_ReaderNormals.h"

C_X_ReaderNormals::C_X_ReaderNormals() {
	nowParsing = "normalCount";
	_noNormal = 0;
	_noFace= 0;
	_faceCounter = 0;
	_normalCounter = 0;
}

void C_X_ReaderNormals::ReadLine(string line){
	line = trim(line);
	cerr<<nowParsing<<endl;
	cerr<<"READ line >>"<<line<<endl;
	if(nowParsing == "normalCount"){
		
		_noNormal = strToInt(line.substr(0,line.find(";")));
		cerr<<"parse normalcount "<<_noNormal<<endl;
		nowParsing = "Normal";
		return;
	}
	
	if(nowParsing == "Normal"){
		for(uint32_t i = 0 ; i < 3; i++){
			GLfloat temp = strTofloat(line.substr(0,line.find(";")));
			cerr<<"temp "<<temp<<endl;
			_normalList[_normalCounter][i] = temp;
			line = line.substr(line.find(";")+1);
		}
		_normalCounter++;		
		if(	_normalCounter >= _noNormal){
			nowParsing = "faceCount";
		}
		return;
	}
	
	
	if(nowParsing == "faceCount"){
		_noFace = strToInt(line.substr(0,line.find(";")));
		nowParsing = "Face";
		//cerr<<"NOFace >"<<_noFace<<endl;
		return;
	}
	if(nowParsing == "Face"){
		uint32_t noveprface = strTofloat(line.substr(0,line.find(";")));
		line = line.substr(line.find(";")+1);
		for(GLfloat i = 0 ; i < noveprface; i++){
			uint32_t faceit = strToInt(line.substr(0,line.find(";")));
			_meshNormalList[_faceCounter][faceit] = _normalList[faceit];
			line = line.substr(line.find(";")+1);
		}
		_faceCounter++;
		if(	_faceCounter >= _noFace){
			nowParsing = "done";
		}
		
		
		return;
	}
	
	

}

GLfloat* C_X_ReaderNormals::GetNormalArray(){
	cerr<<"no normals"<<_noNormal<<endl;
	GLfloat* normalArray = (GLfloat*)malloc(sizeof(GLfloat) * _noNormal * 3);
	uint32_t j = 0;
	for(map<uint32_t, map<uint32_t, map<uint32_t, GLfloat> > >::iterator it = _meshNormalList.begin() ; it != _meshNormalList.end();it++){
		for(map<uint32_t, map<uint32_t, GLfloat> >::iterator it2 = it->second.begin() ; it2 != it->second.end(); it2++){
			for ( map<uint32_t, GLfloat>::iterator it3 = it2->second.begin(); it3 != it2->second.end();it3++){
				normalArray[j++] = (GLfloat)it3->second;
			}
		}
	}
	cerr<<"NORMAL ARRAY"<<endl;
	//for(uint32_t i = 0 ; i < _noNormal * 3; i++){
		//cerr<<(GLfloat)normalArray[i]<<endl;
	//}
	return normalArray;
}


C_X_ReaderNormals::~C_X_ReaderNormals() {
}

