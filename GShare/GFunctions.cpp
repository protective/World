/* 
 * File:   GFunctions.cpp
 * Author: karsten
 * 
 * Created on 23. april 2011, 10:43
 */

#include <math.h>

#include "GFunctions.h"
#include "../Network/Serialize.h"
void printBuffer(char* buffer, uint32_t len){
	int offset = 0;
	int loopoffset = 0;
	if (printbufferbool){
		while (offset < len){
			//cerr<<"offset "<<offset<<endl;
			SerialData* temp = (SerialData*)(buffer + offset);
			if (len - offset >= sizeof(uint32_t)*2 && temp->_size <= len - offset){
				cerr<<"parse len "<< temp->_size<<endl;
				SerialData* st = (SerialData*)(buffer+offset);
				cerr<<"Recived ********************"<<endl
						<<"\ttype "<<st->_type <<endl
						<<"\tsize "<<st->_size<<endl
						<<"\ttime "<<st->_time<<endl;	
				switch(temp->_type)
				{
					case SerialType::SerialTime:{
						SerialTime* st = (SerialTime*)(buffer+offset);
						cerr<<"Recived RegTime*************"<<endl
						<<"\tTime "<<st->_sendtime<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialReqJoin:{
						SerialReqJoin* st = (SerialReqJoin*)(buffer+offset);
						cerr<<"Recived RegJoin*************"<<endl
						<<"\tid "<<st->_unitId<<endl
						<<"\tpass "<<st->_pass<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialBeginCast:{
						SerialBeginCast* st = (SerialBeginCast*)(buffer+offset);
						cerr<<"Recived SerialBeginCast*************"<<endl
						<<"\tpowerid "<<st->_powerid<<endl
						<<"\tunitid "<<st->_unitId<<endl
						<<"\tcastTime "<<st->_castTime<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialCast:{
						SerialCast* st = (SerialCast*)(buffer+offset);
						cerr<<"Recived SerialCast*************"<<endl
						<<"\tpowerid "<<st->_powerid<<endl
						<<"\tunitid "<<st->_unitId<<endl
						<<"\ttargetid "<<st->_targetId<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialTakeDmgHeal:{
						SerialTakeDmgHeal* st = (SerialTakeDmgHeal*)(buffer+offset);
						cerr<<"Recived SerialTakeDmgHeal*************"<<endl
						<<"\tpowerid "<<st->_powerid<<endl
						<<"\tunitid "<<st->_unitId<<endl
						<<"\tcasterid "<<st->_casterId<<endl
						<<"\tflags "<<st->_flags<<endl
						<<"\tvalue "<<st->_value<<endl
						<<"\tnewvalue "<<st->_newvalue<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialAttribute:{
						SerialAttribute* st = (SerialAttribute*)(buffer+offset);
						cerr<<"Recived SerialAttribute*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tattribute "<<st->_attribute<<endl
						<<"\tvalue "<<st->_value<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialCreature:{
						SerialCreature* st = (SerialCreature*)(buffer+offset);
						cerr<<"Recived SerialCreature*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tplayerId "<<st->_playerId<<endl
						<<"\thpp "<<st->_hpp<<endl
						<<"\tmpp "<<st->_mpp<<endl
						<<"\tepp "<<st->_epp<<endl
						<<"\tx "<<st->_x<<endl
						<<"\ty "<<st->_y<<endl
						<<"\tz "<<st->_z<<endl
						<<"\td "<<st->_d<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialPower:{
						SerialPower* st = (SerialPower*)(buffer+offset);
						cerr<<"Recived SerialPower*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tpowerId "<<st->_powerId<<endl
						<<"\ticonId "<<st->_iconId<<endl
						<<"\tcd "<<st->_cd<<endl
						<<"\tcastTime "<<st->_castTime<<endl
						<<"\thpCost "<<st->_hpCost<<endl
						<<"\tmanaCost "<<st->_manaCost<<endl
						<<"\tenergyCost"<<st->_energyCost<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialReqActivatePowerT:{
						SerialReqActivatePowerT* st = (SerialReqActivatePowerT*)(buffer+offset);
						cerr<<"Recived SerialReqActivatePowerT*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tpowerId "<<st->_powerId<<endl
						<<"\ttargetId "<<st->_targetId<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialReqMove:{
						SerialReqMove* st = (SerialReqMove*)(buffer+offset);
						cerr<<"Recived SerialReqMove*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tbTime "<<st->_btime<<endl		
						<<"\t\tposX "<<st->_pos.x<<endl
						<<"\t\tposY"<<st->_pos.y<<endl
						<<"\t\tposZ"<<st->_pos.z<<endl
						<<"\t\tposD"<<st->_pos.d<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialNotisMove:{
						SerialNotisMove* st = (SerialNotisMove*)(buffer+offset);
						cerr<<"Recived SerialNotisMove*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tetime "<<st->_etime<<endl
						<<"\t\tposX "<<st->_pos.x<<endl
						<<"\t\tposY"<<st->_pos.y<<endl
						<<"\t\tposZ"<<st->_pos.z<<endl
						<<"\t\tposD"<<st->_pos.d<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialStatsAbs:{
						SerialStatsAbs* st = (SerialStatsAbs*)(buffer+offset);
						cerr<<"Recived SerialStatsAbs*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\t\thp "<<st->_hp<<endl
						<<"\t\tmana "<<st->_mana<<endl
						<<"\t\tfocus "<<st->_focus<<endl
						<<"\t\tmaxhp "<<st->_maxhp<<endl
						<<"\t\tmaxmana "<<st->_maxmana<<endl
						<<"\t\tmaxfocus "<<st->_maxfocus<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialStatsRel:{
						SerialStatsRel* st = (SerialStatsRel*)(buffer+offset);
						cerr<<"Recived SerialStatsRel*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\t\thpP "<<st->_hpP<<endl
						<<"\t\tmanaP "<<st->_manaP<<endl
						<<"\t\tfocusP "<<st->_focusP<<endl;
						cerr<<"****************************"<<endl;
						break;
					}
					case SerialType::SerialBuff:{
						SerialBuff* st = (SerialBuff*)(buffer+offset);
						cerr<<"Recived SerialBuff*************"<<endl
						<<"\tunitId "<<st->_unitId<<endl
						<<"\tpowerId "<<st->_iconId<<endl
						<<"\tduration"<<st->_duration<<endl
						<<"\tmaxDuration"<<st->_maxDuration<<endl
						<<"\tXvisualEffects"<<st->_XVisualEffects<<endl;
						for(uint32_t i = 0; i < st->_XVisualEffects;i++){
							SerialBuffVisualEffect* st2 = (SerialBuffVisualEffect*)(buffer+offset+(sizeof(SerialBuff)+(sizeof(SerialBuffVisualEffect)*i)));
							cerr<<"\t "<<st2->_effect<<endl
							<<"\t "<<st2->_value<<endl;
						}
						
						cerr<<"****************************"<<endl;
						break;
					}
					default:{
						cerr<<"error recived unknown packate in GLobal"<<endl;
						offset = len;
						break;
					}
				}
				cerr<<"offset += "<<temp->_size<<endl;
		
				offset += temp->_size;

			}else{
				cerr<<"missing data "<<endl;
				break;
			}
		}
	}
}

uint32_t myrandom(uint32_t min,uint32_t max){

	return ((rand()+ (rand()<<16)) % (1+max-min)) + min;
}

int32_t Deg(double x, double y){

	if(x > 0 && y == 0)
		return 0;
	else if(x > 0 && y < 0 )
		return 180 * atan((0-y)/x)/PI;
	else if(x == 0 && y < 0)
		return 90;
	else if(x < 0 && y < 0)
		return (180 * atan((0-x)/(0-y))/PI) +90;
	else if(x < 0 && y == 0)
		return 180;
	else if(x < 0 && y > 0)
		return (180 * atan(y/(0-x))/PI) +180;
	else if(x == 0 && y > 0)
		return 270;
	else if(x > 0 && y > 0)
		return (180 * atan(x/y)/PI) +270;
	return 0;
}

double VektorUnitX(uint32_t deg){
	if (deg >= 0 || deg < 360)
		return MyCos[deg];
	else
		cerr<<"ERROR out of degs rage"<<endl;
	return 0;
}

double VektorUnitY(uint32_t deg){
	if (deg >= 0 || deg < 360)
		return MySin[deg];
	else
		cerr<<"ERROR out of degs rage"<<endl;
	return 0;
}

uint32_t Rangecord(int32_t p1x,  int32_t p1y, int32_t p2x,int32_t p2y)
{
	p1x = p1x/100;
	p2x = p2x/100;
	p1y = p1y/100;
	p2y = p2y/100;

	return 100* sqrt(((p1x - p2x)*(p1x - p2x)) + ((p1y - p2y)*(p1y - p2y)));
}


bool LinePointIntersect(int32_t p1x,  int32_t p1y, int32_t p2x,int32_t p2y, int32_t pointx, int32_t pointy, int32_t range){
double a = 100 * Rangecord(p1x,p1y,p2x,p2y);
	if(a < range/2){
		int32_t x1 = p1x - pointx;
		int32_t y1 = p1y - pointy;
		int32_t x2 = p1x+p2x - pointx;
		int32_t y2 = p1y+p2y - pointy;

		int32_t dx = x2 - x1;
		int32_t dy = y2 - y1;
		double dr = sqrt((dx*dx)+(dy*dy));
		double D = x1*y2 - x2*y1;
		double dis = ((range/2)*(range/2))*(dr*dr)-(D*D);

		if(dis >= 0)
			return true;
		else
			return false;
	}
}

int32_t dirDiff(uint32_t d1, uint32_t d2){
	int32_t dd = d1 - d2;
	if(dd < 0)
		dd += 36000;

	if(dd > 18000)
		return  36000 - dd;
	else
		return dd;
}

