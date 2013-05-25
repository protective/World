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
    SC_MoveObj(uint32_t time, SObj* procesUnit, SPos pos);
    virtual uint32_t execute();
    virtual SC_MoveObj* isMoveObj(){return this;}
    void setPos(SPos pos){_pos = pos;}
    virtual ~SC_MoveObj();
private:
    SPos _pos;
};

#endif	/* SC_MOVEOBJ_H */

