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
	
	//create vartice array
	_vertices = new Vertex[4];
	_vertixCount = 4;
	memset(_vertices,0,sizeof(Vertex)*4);
	/*
	_vertices[0].Position[0] = x; _vertices[0].Position[1] = y;
	_vertices[1].Position[0] = x + wight; _vertices[1].Position[1] = y;
	_vertices[2].Position[0] = x + wight; _vertices[2].Position[1] = y + height;
	_vertices[3].Position[0] = x; _vertices[3].Position[1] = y + height;
	*/
	
	_vertices[0].Position[0] = x; _vertices[0].Position[1] = y;
	_vertices[1].Position[0] = x + wight; _vertices[1].Position[1] = y;
	_vertices[2].Position[0] = x + wight; _vertices[2].Position[1] = y + height;
	_vertices[3].Position[0] = x; _vertices[3].Position[1] = y + height;
	
	for(int i =0 ;i < 4 ; i++){
		_vertices[i].Position[3] = 1;
	}

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
	
	_vertices[0].Tex[0] = 0; _vertices[0].Tex[1] = 0;
	_vertices[1].Tex[0] = 1; _vertices[1].Tex[1] = 0;
	_vertices[2].Tex[0] = 1; _vertices[2].Tex[1] = 1;
	_vertices[3].Tex[0] = 0; _vertices[3].Tex[1] = 1;
	_texture = masterScreen->getIconTextures()->getTexture(iconId);

	
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

void UIBaseFrame::setWight(uint32_t wight){

	_vertices[1].Position[0] = _vertices[0].Position[0] + wight; 
	_vertices[2].Position[0] = _vertices[3].Position[0] + wight; 

}


UIBaseFrame::~UIBaseFrame() {
}

