/* 
 * File:   SCommand.h
 * Author: karsten
 *
 * Created on 31. oktober 2012, 16:01
 */

#ifndef SCOMMAND_H
#define	SCOMMAND_H
#include "../SFunctions.h"
#include "../Powers/SPowerType.h"
#include "../Powers/SPowerTypeSpellDD.h"
#include "../Powers/SPowerTypeSpellDebuff.h"
#include "../Powers/SPowerSpellType.h"
class SC_MoveObj;
class SObj;
class SCommand {
public:
	SCommand(uint32_t time, SObj* procesUnit);
	virtual uint32_t execute(){cerr<<"EXE command"<<_time<<endl; return 0;};
	virtual uint32_t remove();
	uint32_t getTime(){return _time;}
	SObj* getProcesUnit(){return _procesUnit;}
	virtual uint32_t resetTime(uint32_t newtime);
    virtual SC_MoveObj* isMoveObj(){return NULL;}
	virtual ~SCommand();
protected:
	uint32_t _time;
	SObj* _procesUnit;

};

#endif	/* SCOMMAND_H */

