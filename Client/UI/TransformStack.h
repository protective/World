/* 
 * File:   TransformStack.h
 * Author: karsten
 *
 * Created on 18. august 2013, 16:32
 */

#ifndef TRANSFORMSTACK_H
#define	TRANSFORMSTACK_H

#include "../CFunctions.h"
#include "../GLutil.h"

class TransformStack {
public:
	TransformStack();
	void push(){
		glm::mat4* p = top();
		_stack.push_back(p?*p:glm::mat4());
	}
	glm::mat4 pop(){
		glm::mat4* p = top();
		_stack.pop_back();
		return *p;
	}
	void loadIdentity(){
		_stack.back() = glm::mat4();
	}
	glm::mat4* top(){return _stack.size() ?  &_stack.back() :  NULL;}

	void translate(glm::vec3 vec){
		*top() = glm::translate(*top(),vec);
	}
private:

	list<glm::mat4> _stack;
};

#endif	/* TRANSFORMSTACK_H */

