/* 
 * File:   Model.cpp
 * Author: karsten
 * 
 * Created on 9. juni 2013, 16:16
 */

#include <vector>

#include "Model.h"
#include "Grafic.h"

Model::Model(ShaderProgram* shader) {
	
	glUseProgram(shader->getProgramId());
	_shader = shader;
	_vertixCount = 3;
	_indicesCount = 6;
	
	
	_vertices = new Vertex[_vertixCount];
	
	_vertices[0].Position[0] = 11.1f;
	_vertices[0].Position[1] = 0.0f;
	_vertices[0].Position[2] = 10.0f;
	_vertices[0].Position[3] = 1.0f;	
	_vertices[0].Color[0] = 1.0f;
	_vertices[0].Color[1] = 0.0f;
	_vertices[0].Color[2] = 0.0f;
	_vertices[0].Color[3] = 1.0f;
	
	_vertices[1].Position[0] = 0.0f;
	_vertices[1].Position[1] = 0.0f;
	_vertices[1].Position[2] = 0.0f;
	_vertices[1].Position[3] = 1.0f;	
	_vertices[1].Color[0] = 1.0f;
	_vertices[1].Color[1] = 0.0f;
	_vertices[1].Color[2] = 0.0f;
	_vertices[1].Color[3] = 1.0f;
	
	_vertices[2].Position[0] = 0.0f;
	_vertices[2].Position[1] = -10.1f;
	_vertices[2].Position[2] = 10.0f;
	_vertices[2].Position[3] = 1.0f;	
	_vertices[2].Color[0] = 1.0f;
	_vertices[2].Color[1] = 1.0f;
	_vertices[2].Color[2] = 0.0f;
	_vertices[2].Color[3] = 1.0f;
	_indices = new GLuint[_indicesCount];
	
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	_indices[3] = 2;
	_indices[4] = 1;
	_indices[5] = 0;
	glGenVertexArrays(1,&_vao);
	ExitOnGLError("ERROR: Could not generate the VAO");
	glBindVertexArray(_vao);
	ExitOnGLError("ERROR: Could not bind the VAO");
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	ExitOnGLError("ERROR: Could not enable vertex attributes");

	
	glGenBuffers(1, &_vbo);
	
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount*sizeof(Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(GL_FLOAT)*4));
	ExitOnGLError("ERROR: Could not set VAO attributes");

	glGenBuffers(1, &_ibo);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indicesCount*sizeof(GLfloat), _indices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the IBO to the VAO");

	glBindVertexArray(0);
	
	glUseProgram(0);
}

Model::~Model() {
}

