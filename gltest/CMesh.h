/* 
 * File:   CMesh.h
 * Author: karsten
 *
 * Created on 16. oktober 2012, 13:49
 */

#ifndef CMESH_H
#define	CMESH_H
#include "C_X_Loader.h"

class CMesh {
public:
	CMesh();
	void Render();
	
	void SetVertexArray(uint32_t noVertix, GLfloat* VArray,uint32_t noFace, u_int8_t* FArray, GLfloat* NArray){
		_noVertix = noVertix;
		_vertixArray = VArray;
		_normalArray = NArray;
		_noFace = noFace;
		_faceArray = FArray;
	}
	virtual ~CMesh();
private:
	uint32_t _noVertix;
	GLfloat* _vertixArray;
	GLfloat* _normalArray;
	uint32_t _noFace;
	uint8_t* _faceArray;
};

#endif	/* CMESH_H */

