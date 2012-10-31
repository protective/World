/* 
 * File:   SWorld.h
 * Author: karsten
 *
 * Created on 22. maj 2011, 16:24
 */

#ifndef SWORLD_H
#define	SWORLD_H
#include "../SFunctions.h"
#include "SGrid.h"
class SWorld {
public:
	SWorld();
	void addGrid(SGrid* grid);
	void proces(uint32_t thead_id);

	map<uint32_t, SGrid*>& getGrids();
	map<uint32_t, SObj*>& getObjs();
	uint32_t getprocesTime(){return _procesTime;}
	void setProcesTime(uint32_t time){_procesTime = time;}
	virtual ~SWorld();
private:
	map<uint32_t, SGrid*> grids;
	map<uint32_t, SObj*> objInWorld;
	uint32_t _allDone;
	pthread_mutex_t _lockAllDone;
	uint32_t _procesTime;
};

#endif	/* SWORLD_H */

