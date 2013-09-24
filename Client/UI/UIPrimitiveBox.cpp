/* 
 * File:   UIPrimitiveBox.cpp
 * Author: karsten
 * 
 * Created on 21. september 2013, 01:47
 */

#include "UIPrimitiveBox.h"
#include "../Grafic/screenControler.h"
UIPrimitiveBox::UIPrimitiveBox(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height, glm::vec4 colour):
UIBaseFrame(parrent,x,y,wight,height){
	_shader = masterScreen->getUIPrimShaderProgram();
	_colour = colour;
	
	_shader->enable();
	
	
	glGenVertexArrays(1, &_vao);
	ExitOnGLError("ERROR: Could not generate the VAO");
	glBindVertexArray(_vao);
	ExitOnGLError("ERROR: Could not bind the VAO");

	glEnableVertexAttribArray(0);
	ExitOnGLError("ERROR: Could not enable vertex attributes");

	glGenBuffers(1, &_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) 0);
	ExitOnGLError("ERROR: Could not set VAO attributes");

	glBindVertexArray(0);

	glUseProgram(0);
}

void UIPrimitiveBox::bind(){
	glBindVertexArray(this->_vao);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");
}
void UIPrimitiveBox::unbind(){
	glBindVertexArray(0);
	glUseProgram(0);
}

void UIPrimitiveBox::draw(){
	/*
	glm::mat4 temp = *masterScreen->getUIStack()->top();
	for(int i= 0; i < 4;i++){
		cerr<<temp[i].x<<" ";
		cerr<<temp[i].y<<" ";
		cerr<<temp[i].z<<" ";
		cerr<<temp[i].w<<" ";
	}
	cerr<<endl;
	 * 
	*/
	//enable shader and set uniforms
	_shader->enable();
	_shader->setModelMatrix(masterScreen->getUIStack()->top());
	_shader->setColor(&_colour);
	
	//bind and draw
	this->bind();
	glDrawArrays(GL_TRIANGLE_FAN,0,4);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
	this->unbind();

	
	//matrix stack
	masterScreen->getUIStack()->translate(glm::vec3(getX(),getY(),0));
	
	//do childs
	this->drawChilds();

}

UIPrimitiveBox::~UIPrimitiveBox() {
}

