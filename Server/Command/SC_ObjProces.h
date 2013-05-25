/* 
 * File:   SC_ObjProces.h
 * Author: karsten
 *
 * Created on 14. maj 2013, 21:26
 */

#ifndef SC_OBJPROCES_H
#define	SC_OBJPROCES_H
#include "SCommand.h"

namespace SC_ObjProcesTask{
	enum Enum{
		Invalid = 0,
		Mana = 1,
		ManaContinue = 2,
		ManaPFS = 3,
		Focus = 4,
	};
}

class SC_ObjProces : public SCommand {
	
	
public:
	SC_ObjProces(uint32_t time, SObj* procesUnit, SC_ObjProcesTask::Enum task);
	virtual uint32_t execute();
	virtual ~SC_ObjProces();
private:
	SC_ObjProcesTask::Enum _task;
};

#endif	/* SC_OBJPROCES_H */

