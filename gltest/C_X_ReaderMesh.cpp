/* 
 * File:   C_X_ReaderMesh.cpp
 * Author: karsten
 * 
 * Created on 16. oktober 2012, 23:05
 */


#include "C_X_ReaderMesh.h"
#include "CMesh.h"

C_X_ReaderMesh::C_X_ReaderMesh() {
	_vertexCounter= 0;
	_faceCounter = 0;
	_noVertex = 0;
	_noFace = 0;
	_lineFeed = 0;
	nowParsing = "vertexCount";
}

void C_X_ReaderMesh::ReadLine(string line){
	line = trim(line);
	
	if(nowParsing == "vertexCount"){
		_noVertex = strToInt(line.substr(0,line.find(";")));
		nowParsing = "Vertex";
		return;
	}
	if(nowParsing == "Vertex"){
		for(GLfloat i = 0 ; i < 3; i++){
			_vertixList[_vertexCounter][i] = strTofloat(line.substr(0,line.find(";")));
			line = line.substr(line.find(";")+1);
		}
		_vertexCounter++;		
		if(	_vertexCounter >= _noVertex){
			nowParsing = "faceCount";
		}
		return;
	}
	if(nowParsing == "faceCount"){
		_noFace = strToInt(line.substr(0,line.find(";")));
		nowParsing = "Face";
		return;
	}
	if(nowParsing == "Face"){
		uint32_t noveprface = strTofloat(line.substr(0,line.find(";")));
		line = line.substr(line.find(";")+1);
		for(GLfloat i = 0 ; i < noveprface; i++){
			uint32_t vertexit = strToInt(line.substr(0,line.find(";")));
			_meshVertixList[_faceCounter][vertexit] = _vertixList[vertexit];
			line = line.substr(line.find(";")+1);
		}
		_faceCounter++;
		if(	_faceCounter >= _noFace){
			nowParsing = "normalCount";
		}
		
		
		return;
	}
	

	_lineFeed++;
}

CMesh* C_X_ReaderMesh::getMesh(){
	CMesh* mesh = new CMesh();
	
	GLfloat* vertixArray = (GLfloat*)malloc(sizeof(GLfloat) * _noVertex * 3);
	
	uint8_t* faceArray = (uint8_t*)malloc(sizeof(uint8_t)*_noFace);
	if(!_normalReader){
		cerr<<"ERROR no normals"<<endl;
		return NULL;
	}
		
	mesh->SetVertexArray(_noVertex,vertixArray,_noFace,faceArray,_normalReader->GetNormalArray());
	uint32_t i = 0;
	uint32_t j = 0;
	for(map<uint32_t, map<uint32_t, map<uint32_t, GLfloat> > >::iterator it = _meshVertixList.begin() ; it != _meshVertixList.end();it++){
		faceArray[i++] = (uint8_t)it->second.size();
		for(map<uint32_t, map<uint32_t, GLfloat> >::iterator it2 = it->second.begin() ; it2 != it->second.end(); it2++){
			for ( map<uint32_t, GLfloat>::iterator it3 = it2->second.begin(); it3 != it2->second.end();it3++){
				vertixArray[j++] = (GLfloat)it3->second;
			}
		}
	}


	return mesh;
}


C_X_ReaderMesh::~C_X_ReaderMesh() {
}

