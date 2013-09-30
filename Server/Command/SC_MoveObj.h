/* 
 * File:   SC_MoveObj.h
 * Author: karsten
 *
 * Created on 14. marts 2013, 21:08
 */

#ifndef SC_MOVEOBJ_H
#define	SC_MOVEOBJ_H
#include "SCommand.h"
#include "../objects/SObj.h"
class SC_MoveObj : public SCommand{
public:
    SC_MoveObj(uint32_t time, SObj* procesUnit, SPos pos, uint32_t btime, uint32_t etime);
    virtual uint32_t execute();
    virtual SC_MoveObj* isMoveObj(){return this;}
    void setPos(SPos pos){_pos = pos;}
    virtual ~SC_MoveObj();
private:
	void informOthers();
	uint32_t _initTime;
	uint32_t _etime;
	uint32_t _btime;
    SPos _pos;
	bool _active;
};

#endif	/* SC_MOVEOBJ_H */

