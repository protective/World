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
class Model {
public:
	Model();
	virtual ~Model();
private:
	Vertex* _vertices;
	uint32_t _vertixCount;
	uint32_t* _indices;
	uint32_t _indicesCount;
	GLuint _vao; //vertex array hold array meta information
	GLuint _vbo; //vertices handler
	GLuint _ibo; //indices handler
};

#endif	/* MODEL_H */

