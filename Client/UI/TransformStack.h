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
		Matrix* p = top();
		_stack.push_back(p?*p:IDENTITY_MATRIX);
	}
	Matrix pop(){
		Matrix* p = top();
		_stack.pop_back();
		return *p;
	}
	void loadIdentity(){
		_stack.back() = IDENTITY_MATRIX;
	}
	Matrix* top(){return _stack.size() ?  &_stack.back() :  NULL;}
private:

	list<Matrix> _stack;
};

#endif	/* TRANSFORMSTACK_H */

