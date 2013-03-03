/* 
 * File:   CPower.h
 * Author: karsten
 *
 * Created on 31. januar 2013, 14:32
 */

#ifndef CPOWER_H
#define	CPOWER_H
#include "../CFunctions.h"
class CObj;
class CPower {
public:
    CPower(uint32_t id, CObj* owner, uint32_t iconId, uint32_t castTime);
    virtual ~CPower();
    void setCD(uint32_t cd){this->_cd = cd;}
    void setHpCost(uint32_t hp){this->_cd = _hpCost;}
    void setManaCost(uint32_t mana){this->_cd = _manaCost;}
    void setEnergyCost(uint32_t energy){this->_cd = _energyCost;}
    void activate(CObj* target);
    
    uint32_t getIconId(){return _iconId;}
    CObj* getOwner(){return _owner;}
    uint32_t getId(){return _id;}

private:
    uint32_t _id;
    uint32_t _iconId;
    uint32_t _cd;
    uint32_t _castTime;
    uint32_t _hpCost;
    uint32_t _manaCost;
    uint32_t _energyCost;
    CObj* _owner;
};

#endif	/* CPOWER_H */

