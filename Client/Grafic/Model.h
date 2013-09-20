/* 
 * File:   Model.h
 * Author: karsten
 *
 * Created on 9. juni 2013, 16:16
 */

#ifndef MODEL_H
#define	MODEL_H
#include "../GLutil.h"
#include "../CFunctions.h"
#include "Shaders/ObjectShader.h"
class Model {
public:
	Model(ObjectShader* shader);
	void bind();
	void unbind();
	ObjectShader* getShader(){return _shader;}
	GLuint get_vao(){return _vao;}
	GLuint get_vbo(){return _vbo;}
	GLuint* get_ibo(){return &_ibo;}
	GLuint get_texture(){return _texture;}
	uint32_t getIndicesCount(){return _indicesCount;}
	virtual ~Model();
private:
	void createFromFile(string filePath);
	ObjectShader* _shader;
	Vertex* _vertices;
	uint32_t _vertixCount;
	GLuint* _indices;
	uint32_t _indicesCount;
	GLuint _vao; //vertex array hold array meta information
	GLuint _vbo; //vertices handler
	GLuint _ibo; //indices handler
	GLuint _texture;
};

#endif	/* MODEL_H */

