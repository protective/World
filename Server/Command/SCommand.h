/* 
 * File:   SCommand.h
 * Author: karsten
 *
 * Created on 31. oktober 2012, 16:01
 */

#ifndef SCOMMAND_H
#define	SCOMMAND_H
#include "../SFunctions.h"
class SObj;
class SCommand {
public:
	SCommand(uint32_t time, SObj* unit);
	virtual uint32_t execute(){cerr<<"EXE command"<<_time<<endl; return 0;};
	uint32_t getTime(){return _time;}
	virtual ~SCommand();
protected:
	uint32_t _time;
	SObj* _unit;
};

#endif	/* SCOMMAND_H */

