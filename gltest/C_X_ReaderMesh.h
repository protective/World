/* 
 * File:   C_X_ReaderMesh.h
 * Author: karsten
 *
 * Created on 16. oktober 2012, 23:05
 */

#ifndef C_X_READERMESH_H
#define	C_X_READERMESH_H

#include "C_X_ReaderBase.h"


class C_X_ReaderMesh : public C_X_ReaderBase {
public:
	C_X_ReaderMesh();
	virtual void ReadLine(string line);
	virtual string Name(){return "Mesh";}
	virtual ~C_X_ReaderMesh();
private:
	uint32_t _lineFeed;
	uint32_t _noVertex;
};

#endif	/* C_X_READERMESH_H */

