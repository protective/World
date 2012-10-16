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
	
	void SetVertexArray(uint32_t noVertix, u_int32_t* VArray,uint32_t noFace, u_int32_t* FArray){
		_noVertix = noVertix;
		_vertixArray = VArray;
		_noFace = noFace;
		_faceArray = FArray;
	}
	virtual ~CMesh();
private:
	uint32_t _noVertix;
	uint32_t* _vertixArray;
	uint32_t _noFace;
	uint32_t* _faceArray;
};

#endif	/* CMESH_H */

