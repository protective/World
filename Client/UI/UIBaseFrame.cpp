/* 
 * File:   UIBaseFrame.cpp
 * Author: karsten
 * 
 * Created on 31. december 2012, 15:15
 */

#include "UIBaseFrame.h"
#include "UIMainFrame.h"
#include "../Grafic/screenControler.h"
UIBaseFrame::UIBaseFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height) {
	_parrent = parrent;

	
	//Init Shaders
	_vertices = new Vertex[4];
	_vertixCount = 4;
	memset(_vertices,0,sizeof(Vertex)*4);
	_vertices[0].Position[0] = x; _vertices[0].Position[1] = y;
	_vertices[1].Position[0] = x + wight; _vertices[1].Position[1] = y;
	_vertices[2].Position[0] = x + wight; _vertices[2].Position[1] = y + height;
	_vertices[3].Position[0] = x; _vertices[3].Position[1] = y + height;
	

	//_vertices[0].Position[0] = 0; _vertices[0].Position[1] = 0;
	//_vertices[1].Position[0] = 50; _vertices[1].Position[1] = 0;
	//_vertices[2].Position[0] = 50; _vertices[2].Position[1] = 50;
	//_vertices[3].Position[0] = 0; _vertices[3].Position[1] = 100;
	
	
	
	for(int i =0 ;i < 4 ; i++){
		_vertices[i].Position[3] = 1;
	}
	/*
	for(int i =0 ;i < 4 ; i++){
		cerr<<_vertices[i].Position[0]<<endl;
		cerr<<_vertices[i].Position[1]<<endl;
		cerr<<_vertices[i].Position[2]<<endl;
		cerr<<_vertices[i].Position[3]<<endl<<endl;
	}*/
	
	glUseProgram(masterScreen->getUIShaderProgram()->getProgramId());
	_texture = textures[0];
	
	glGenVertexArrays(1, &_vao);
	ExitOnGLError("ERROR: Could not generate the VAO");
	glBindVertexArray(_vao);
	ExitOnGLError("ERROR: Could not bind the VAO");

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	ExitOnGLError("ERROR: Could not enable vertex attributes");

	glGenBuffers(1, &_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex), (GLvoid*) (sizeof (GL_FLOAT)*4));
	ExitOnGLError("ERROR: Could not set VAO attributes");

	glBindVertexArray(0);

	glUseProgram(0);	
}

void UIBaseFrame::bind(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glUniform1i(masterScreen->getUIShaderProgram()->getTextureUniform(), /*GL_TEXTURE*/0);
	ExitOnGLError("ERROR: Could not set the shader texture uniforms");
	glBindVertexArray(this->_vao);
	ExitOnGLError("ERROR: Could not bind the VAO for drawing purposes");
}
void UIBaseFrame::unbind(){
	glBindVertexArray(0);
	glUseProgram(0);
}

void UIBaseFrame::draw(){
	this->drawChilds();
}
void UIBaseFrame::drawChilds(){

	for(list<UIBaseFrame*>::iterator it = _childs.begin(); it != _childs.end();it++){
		masterScreen->getUIStack()->push();
		(*it)->draw();
		masterScreen->getUIStack()->pop();
	}

}

void UIBaseFrame::setIcon(uint32_t iconId){
	
	cerr<<"set icon"<<iconId<<endl;
	switch(iconId){
		case 1:{		
			_vertices[0].Tex[0] = 0; _vertices[0].Tex[1] = 0;
			_vertices[1].Tex[0] = 1; _vertices[1].Tex[1] = 0;
			_vertices[2].Tex[0] = 1; _vertices[2].Tex[1] = 1;
			_vertices[3].Tex[0] = 0; _vertices[3].Tex[1] = 1;
			_texture = textures[0];
			break;
		}
		default:{
		_vertices[0].Tex[0] = 0; _vertices[0].Tex[1] = 0;
		_vertices[1].Tex[0] = 100; _vertices[1].Tex[1] = 0;
		_vertices[2].Tex[0] = 100; _vertices[2].Tex[1] = 100;
		_vertices[3].Tex[0] = 0; _vertices[3].Tex[1] = 100;
		_texture = textures[0];
			break;
		}
	}
	masterScreen->getUIShaderProgram()->enable();
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	ExitOnGLError("ERROR: Could not bind BUFFer");
	glBufferData(GL_ARRAY_BUFFER, _vertixCount * sizeof (Vertex), _vertices, GL_STATIC_DRAW);
	ExitOnGLError("ERROR: Could not bind the VBO to the VAO");
	glBindVertexArray(0);
	glUseProgram(0);
	
}

uint32_t UIBaseFrame::click(uint32_t x, uint32_t y){
	return clickChilds(x,y);
}

uint32_t UIBaseFrame::clickChilds(uint32_t x, uint32_t y){
	for(list<UIBaseFrame*>::reverse_iterator it = _childs.rbegin(); it != _childs.rend();it++){
		if(x-getX() >= (*it)->getX() && x-getX() <= (*it)->getX()+(*it)->getWight() && y-getY() >= (*it)->getY() && y-getY() <= (*it)->getY()+(*it)->getHeight()){
			uint32_t result = (*it)->click(x-getX(),y-getY());
			if (result)
				return result;
		}
	}
	return 0;
}


UIBaseFrame::~UIBaseFrame() {
}

