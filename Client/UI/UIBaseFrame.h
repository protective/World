/* 
 * File:   UIBaseFrame.h
 * Author: karsten
 *
 * Created on 31. december 2012, 15:15
 */

#ifndef UIBASEFRAME_H
#define	UIBASEFRAME_H
#include "../CFunctions.h"
#include "../Grafic/Grafic.h"
#include "../Grafic/ShaderProgram.h"
class UIBaseFrame {
public:
	UIBaseFrame(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height);
	virtual void draw();
	virtual void drawChilds();
	void addChild(UIBaseFrame* frame){
		_childs.push_back(frame);
	}
	void removeChild(UIBaseFrame* frame){
		_childs.remove(frame);
	}
	virtual void setIcon(uint32_t iconId);
	virtual uint32_t click(uint32_t x, uint32_t y);
	virtual uint32_t clickChilds(uint32_t x, uint32_t y);
	list<UIBaseFrame*>& getChilds(){return _childs;}
	virtual uint32_t getX(){return _vertices[0].Position[0];}
	virtual uint32_t getY(){return _vertices[0].Position[1];}
	virtual uint32_t getWight(){return _vertices[2].Position[0] - _vertices[0].Position[0] ;}
	virtual uint32_t getHeight(){return _vertices[2].Position[1] - _vertices[0].Position[1];}
	
	virtual void bind();
	virtual void unbind();
	virtual ~UIBaseFrame();
protected:
	UIBaseFrame* _parrent;
	list<UIBaseFrame*> _childs;
	

	Vertex* _vertices;
	uint32_t _vertixCount;
	GLuint _vao; //vertex array hold array meta information
	GLuint _vbo; //vertices handler
	GLuint _texture;
	
};

#endif	/* UIBASEFRAME_H */

