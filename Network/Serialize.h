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
};

struct SerialCast : public SerialData{ //id = 5
    uint32_t _unitId;
	uint32_t _targetId;
	uint32_t _powerid;
};


#endif	/* SERIALIZE_H */

