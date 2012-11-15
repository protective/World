/* 
 * File:   Enums.h
 * Author: karsten
 *
 * Created on 23. maj 2011, 21:51
 */

#ifndef ENUMS_H
#define	ENUMS_H
#include <string.h>



namespace MoveBitF
{
  const uint32_t TargetPosLock = 0x01;
  const uint32_t SOME_VALUE1 = 0x02;
  const uint32_t SOME_VALUE2 = 0x04;
  const uint32_t SOME_VALUE3 = 0x08;
}
namespace EResults{
	enum Enum{
		Invalid = 0,
		SMiss = 1,
		SResist = 2,
		SHit = 3,
		SCrit = 4,
	};
}

namespace EffectTypes{
	enum Enum{
		Invalid = 0,
		ArmorAmount = 1,
		ArmorP = 2,
		FireDmg = 3,
	};
}

namespace Attributes{
	enum Enum{
		Invalid = 0,
		Level = 1,
		AttackPower = 2,
		SpellPower = 3,
		HealingPower = 4,
		Hit = 5,
		SpellHit = 6,
		parry = 7,
		Dodge = 8,
		Block = 9,
		BlockS = 10,
		Armor = 11,
		Crit = 12,
		SpellCrit = 13,
		ResistFire = 14,
		ResistFrost = 15,
		ResistNature = 17,
		ResistShadow = 18,
		ResistArcane = 19,
		ResistForce = 19,
		Hp = 20,
		Mana = 21,
		Focus = 22,
	};
}
namespace DamageTypes{
	enum Enum{
		Invalid = 0,
		physical = 1,
		Fire = 2,
		Frost = 3,
		nature = 4,
		shadow = 5,
		arcane = 6,
		force = 7,
		holy = 8,
	};
}


namespace Textures{
	enum Enum{
		Invalid = 0,
        test = 1,
		BC1 = 2,
		Shot_Laser_I = 3,
		EffectSheet = 4,
		SlotSheet = 5,
		ShotSheet = 6,
		ItemSheet = 7,
		SubItemSheet = 8,
		ObjSheet = 9,
		OwObjSheet = 10,
		EffectSheet2 = 11,
		IconSheet = 12,
	};
}

namespace ParticalTex{
	enum Enum{
		Invalid = 0,
        test = 1,
		eks1 = 2,
		eks2 = 3,
		eks3 = 4,
		eks4 = 5,
		eks5 = 6,
		eks6 = 7,
		eks4l = 8,
		eks5l = 9,
		eks6l = 10,
		eks7l = 11,
		eksshc1 = 12,
		eksshc2 = 13,
		eksshc3 = 14,
		eksshc4 = 15,
		eksshc5 = 16,
		eksshc6 = 17,
		eksshc7 = 18,
		eksshc4l = 19,
		eksshc5l = 20,
		eksshc6l = 21,
		eksshc7l = 22,
		LaserTail1 = 23,
		MissileTail1 = 24,
		eksship1 = 25,
		plasma1 = 26,
	};
}

#endif	/* ENUMS_H */

