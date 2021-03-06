/* 
 * File:   CPos.h
 * Author: karsten
 *
 * Created on 23. maj 2011, 10:46
 */

#ifndef CPOS_H
#define	CPOS_H
#include "../CFunctions.h"
class CGrid;
class CPos {
public:
	CPos();
	CPos(CPos& pos);
	CPos(int32_t x, int32_t y, int32_t z, int32_t d);
	int32_t x;
	int32_t y;
	int32_t z;
	int32_t d;
	CGrid* grid;
        void moveFw(uint32_t deltaTime);
        void moveBw(uint32_t deltaTime);
        void TurnL(uint32_t deltaTime);
        void TurnR(uint32_t deltaTime);       
	void turn(int32_t deg);
	virtual ~CPos();
private:

};

#endif	/* CPOS_H */

