/* 
 * File:   SC_RemoveSubscriber.h
 * Author: karsten
 *
 * Created on 23. september 2013, 22:59
 */

#ifndef SC_REMOVESUBSCRIBER_H
#define	SC_REMOVESUBSCRIBER_H
#include "SCommand.h"

class SC_RemoveSubscriber  : public SCommand  {
public:
	SC_RemoveSubscriber(uint32_t time, SObj* procesUnit, Client* client);
	virtual uint32_t execute();
	virtual ~SC_RemoveSubscriber();
private:
	Client* _client;
};

#endif	/* SC_REMOVESUBSCRIBER_H */

