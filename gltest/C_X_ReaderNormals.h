/* 
 * File:   C_X_ReaderNormals.h
 * Author: karsten
 *
 * Created on 18. oktober 2012, 13:42
 */

#ifndef C_X_READERNORMALS_H
#define	C_X_READERNORMALS_H

#include "C_X_ReaderBase.h"


class C_X_ReaderNormals : public C_X_ReaderBase{
public:
	C_X_ReaderNormals();
	virtual void ReadLine(string line);
	
	virtual string Name(){return "MeshNormal";}
	GLfloat* GetNormalArray();
	virtual ~C_X_ReaderNormals();
private:
	uint32_t _noNormal;
	uint32_t _noFace;
	string nowParsing;
	uint32_t _normalCounter;
	uint32_t _faceCounter;
	map<uint32_t, map<uint32_t, map<uint32_t, GLfloat> > > _meshNormalList;
	map<uint32_t, map<uint32_t, GLfloat> > _normalList;
};

#endif	/* C_X_READERNORMALS_H */

