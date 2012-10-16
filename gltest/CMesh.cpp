/* 
 * File:   CMesh.cpp
 * Author: karsten
 * 
 * Created on 16. oktober 2012, 13:49
 */

#include "CMesh.h"

CMesh::CMesh() {
}

void CMesh::Render(){
	uint32_t i;
	for(uint32_t f = 0 ; f < _noFace ; f ++){//loop each face
		glBegin(GL_TRIANGLES);
		uint8_t no_ve_pr_face = (uint8_t)*(_faceArray+(i *sizeof(uint8_t))); //read the face array
		for(uint8_t v = 0 ; v < no_ve_pr_face ; v++){ //loop each vertex on face 
			uint32_t* v3 = _vertixArray+ ((i+v)*3*sizeof(GLfloat)); // read the vertex array
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3i((GLfloat)*v3, (GLfloat)*v3+sizeof(GLfloat),(GLfloat)*v3+(sizeof(GLfloat)*2));
			
		}
		i+= no_ve_pr_face;
		glEnd();
	}
}


CMesh::~CMesh() {
}

