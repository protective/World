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
	//cerr<<"RENDER"<<endl;
	uint32_t i = 0;
	//cerr<<"noface>"<<_noFace<<endl;
	for(uint32_t f = 0 ; f < _noFace ; f ++){//loop each face
		glBegin(GL_TRIANGLE_FAN);
		uint8_t no_ve_pr_face = (_faceArray[f]); //read the face array
		
		
		GLfloat* n3 = &_normalArray[(i)*3]; // read the normal array
		glNormal3d(n3[0], n3[1],n3[2]);
		//cerr<<"render normal x>"<<n3[0]<<" y>"<<n3[1]<<" z>"<<n3[2]<<endl;
		//cerr<<"no_ve_pr_face>"<<(uint32_t)no_ve_pr_face<<endl;
		for(uint8_t v = 0 ; v < no_ve_pr_face ; v++){ //loop each vertex on face 
			GLfloat* v3 = &_vertixArray[(i+v)*3]; // read the vertex array
			glColor3f(1.0f, 0.0f, 0.0f);
			//cerr<<"render vertex x>"<<v3[0]<<" y>"<<v3[1]<<" z>"<<v3[2]<<endl;
			glVertex3f(v3[0], v3[1],v3[2]);
			
		}
		i+= no_ve_pr_face;
		glEnd();
	}
}


CMesh::~CMesh() {
}

