/* 
 * File:   Serialize.h
 * Author: karsten
 *
 * Created on 23. april 2011, 11:17
 */

#ifndef SERIALIZE_H
#define	SERIALIZE_H


namespace SerialType{
	/** Identifiers for each serializable type
	  */
	enum Enum{
		/** Dummy entry for serialization of incomplete types
		  */
		Invalid = 0,
                SerialTime= 1,
                SerialReqJoin = 2,
				SerialTakeDmgHeal = 3,
				SerialBeginCast = 4,
				SerialCast = 5,
				SerialKillUnit = 6,
				SerialCreature = 7,
				SerialPower = 8,
				SerialPowerType = 9,
				SerialPlayerStats = 10,
                                SerialReqActivatePowerT = 11,
                                SerialReqMove = 12,
                                SerialConfMove = 13,
	};
}

struct SerialData{
    /** Type identifier of the serialized object
      */
    SerialType::Enum _type;

    /** Size of the buffer used for serialization of this object
      */
    uint32_t _size;
    uint32_t _time;
}__attribute__((__packed__));

struct SerialPos{
    int32_t x;
    int32_t y;
    int32_t z;
    int32_t d;
};

struct SerialTime : public SerialData{ //id = 1
    uint32_t _sendtime;
    uint32_t _local;
};

struct SerialReqJoin : public SerialData{ //id = 2
    uint32_t _unitId;
    uint32_t _pass;
};

struct SerialTakeDmgHeal : public SerialData{ //id = 3
    uint32_t _unitId;
    uint32_t _casterId;
    int32_t _value;
    uint32_t _newvalue;
    uint32_t _powerid;
};


struct SerialBeginCast : public SerialData{ //id = 4
    uint32_t _unitId;
    uint32_t _powerid;
    uint32_t _castTime;
};

struct SerialCast : public SerialData{ //id = 5
    uint32_t _unitId;
    uint32_t _targetId;
    uint32_t _powerid;
};

struct SerialKillUnit : public SerialData{ //id = 6
    uint32_t _unitId;
};
struct SerialCreature : public SerialData{ //id = 7
    uint32_t _unitId;
    uint32_t _playerId;
    uint32_t _hpp;
    uint32_t _mpp;
    uint32_t _epp;
    int32_t _x;
    int32_t _y;
    int32_t _z;
    int32_t _d;
};

struct SerialPower : public SerialData{ //id = 8
    uint32_t _unitId;
    uint32_t _powerId;
    uint32_t _iconId;
    uint32_t _cd;
    uint32_t _castTime;
    uint32_t _hpCost;
    uint32_t _manaCost;
    uint32_t _energyCost;
};



struct SerialPlayerStatsSingle{
    Attributes::Enum _attribute;
    uint32_t _value;
};
		
		
struct SerialPlayerStats : public SerialData{ //id = 10
    uint32_t _unitId;
    uint32_t _NoAttributes;
	
};

struct SerialReqActivatePowerT : public SerialData{ //id = 10
    uint32_t _unitId;
    uint32_t _targetId;
    uint32_t _powerId;
};

struct SerialReqMove : public SerialData{ //id = 12
    uint32_t _unitId;
    SerialPos _pos;
};
struct SerialConfMove : public SerialData{ //id = 13
    uint32_t _unitId;
    SerialPos _pos;
};

#endif	/* SERIALIZE_H */

