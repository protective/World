/* 
 * File:   UIPrimitiveBox.h
 * Author: karsten
 *
 * Created on 21. september 2013, 01:47
 */

#ifndef UIPRIMITIVEBOX_H
#define	UIPRIMITIVEBOX_H

#include "UIBaseFrame.h"
#include "../Grafic/Shaders/UIPrimShader.h"

class UIPrimitiveBox : public UIBaseFrame {
public:
	UIPrimitiveBox(UIBaseFrame* parrent, uint32_t x, uint32_t y, uint32_t wight, uint32_t height, glm::vec4 colour);
	virtual void draw();
	virtual ~UIPrimitiveBox();
protected:

	virtual void bind();
	virtual void unbind();
	UIPrimShader* _shader;
	glm::vec4 _colour;
};

#endif	/* UIPRIMITIVEBOX_H */

