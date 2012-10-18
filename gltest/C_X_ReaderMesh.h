/* 
 * File:   C_X_ReaderMesh.h
 * Author: karsten
 *
 * Created on 16. oktober 2012, 23:05
 */

#ifndef C_X_READERMESH_H
#define	C_X_READERMESH_H

#include "C_X_ReaderBase.h"
#include "C_X_ReaderNormals.h"


class C_X_ReaderMesh : public C_X_ReaderBase {
public:
	C_X_ReaderMesh();
	virtual void ReadLine(string line);
	virtual void SetReaderNormal(C_X_ReaderNormals* normalReader){_normalReader = normalReader;}
	virtual string Name(){return "Mesh";}
	virtual CMesh* getMesh();
	virtual ~C_X_ReaderMesh();
private:
	C_X_ReaderNormals* _normalReader;
	uint32_t _lineFeed;
	uint32_t _noVertex;
	uint32_t _noFace;
	uint32_t _vertexCounter;
	uint32_t _faceCounter;
	string nowParsing;
	map<uint32_t, map<uint32_t, GLfloat> > _vertixList;

	map<uint32_t, map<uint32_t, map<uint32_t, GLfloat> > > _meshVertixList;

};

#endif	/* C_X_READERMESH_H */

