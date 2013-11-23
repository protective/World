/* 
 * File:   Enums.h
 * Author: karsten
 *
 * Created on 23. maj 2011, 21:51
 */

#ifndef ENUMS_H
#define	ENUMS_H
#include <string.h>



namespace SerialTakeDmgHealBitF
{
  const uint32_t ValueP = 0x01;
  const uint32_t Critical = 0x02;
  const uint32_t SOME_VALUE2 = 0x04;
  const uint32_t SOME_VALUE3 = 0x08;
}

namespace PSStates{
	enum Enum{
		Default,
		Init,
		Run,
		Term
	};
}

namespace Textures{
	enum Enum{
		Invalid = 0,
		Icons1 = 1,
                Fire1 = 2,
	};
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

namespace StatsMods{
	enum Enum{
		Invalid = 0,
		ArmorAmount = 1,
		ArmorP = 2,
		FireDmg = 3,
		SpellHit = 4,
		SpellCrit = 5,
		SpellPower = 6,
		DeBuffSpeedMod = 7,
		DeBuffSpeedModP = 8,
	};
}
namespace BuffVisualEffects{
	enum Enum{
		Invalid = 0,
		Stunned = 1,
		Frozen = 2,
	};
}

namespace PowerProjectileMods{
	enum Enum{
		Invalid = 0,
		Shit,
		Scrit,
		Spower,
		SpowerBonus,
		SpowerBonusBuff,
		ALevel,
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
		ResistNature = 16,
		ResistShadow = 17,
		ResistArcane = 18,
		ResistForce = 19,
		Hp = 20,
		Mana = 21,
		Focus = 22,
		HpMax = 23,
		ManaMax = 24,
		FocusMax = 25,
		HpP = 26,
		ManaP = 27,
		FocusP = 28,
		SpellPowerBonus = 29,
		SpellPowerBonusBuff= 30,
		
		Spirit = 31,
		Strength = 32,
		Dexterity = 33,
		Constitution = 34,
		Intelligence = 35,
		RegenOFSRP = 36,
		ManaPrF = 37,	
		Speed = 38,
		
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

namespace PowerTypeStats{
	enum Enum{
		Invalid = 0,
		ManaCost = 1,
		EnergyCost = 2,
		CastTime = 3,
		CD = 4,
		projectileSpeed = 5,
		SpellLevel = 6,
		ResistDmgType = 7,
		BonusHit = 8,
		BonusCrit = 9,
	};
}


#endif	/* ENUMS_H */

