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
	
	
	GLint loc = glGetUniformLocation(ProgramObject, "Bone");
		if (loc != -1)
		{
		glUniform1f(loc, 0.432);
		}
	
	for(uint32_t f = 0 ; f < _noFace ; f ++){//loop each face
		glBegin(GL_TRIANGLE_FAN);
		uint8_t no_ve_pr_face = (_faceArray[f]); //read the face array
		
		
		GLfloat* n3 = &_normalArray[(i)*3]; // read the normal array
		glNormal3d(n3[0], n3[1],n3[2]);


		
		for(uint8_t v = 0 ; v < no_ve_pr_face ; v++){ //loop each vertex on face 
			GLfloat* v3 = &_vertixArray[(i+v)*3]; // read the vertex array
			glColor4f(1.0f, 0.0f, 0.0f ,1.0f);
			glVertex3f(v3[0], v3[1],v3[2]);
			
		}
		i+= no_ve_pr_face;
		glEnd();
	}
}


CMesh::~CMesh() {
}

