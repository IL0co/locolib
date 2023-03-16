#if defined _locolib_included
 #endinput
#endif
#define _locolib_included

#include <cstrike>

#define any(%0)		view_as<any>(%0)
#define int(%0)		view_as<int>(%0)
#define char(%0)	view_as<char>(%0)
#define bool(%0)	view_as<bool>(%0)

enum WeaponSlot {
	Slot_Invalid	= -1,							// Invalid index.

	Slot_Primary 	= CS_SLOT_PRIMARY,				// Primary weapon slot.
	Slot_Secondary 	= CS_SLOT_SECONDARY,			// Secondary weapon slot.
	Slot_Knife 		= CS_SLOT_KNIFE,				// Slot knife.
	Slot_Grenade 	= CS_SLOT_GRENADE,				// Grenade slot.
	Slot_C4    		= CS_SLOT_C4,					// Slot C4.
	Slot_Boost 		= CS_SLOT_BOOST,				// Amplifier slot.
	Slot_Utility 	= CS_SLOT_UTILITY,				// Slot of additional equipment.

	Slot_Length,									// The total number of slots.
}

#include "locolib/offset_weapon"
#include "locolib/entity"
#include "locolib/weapon"
#include "locolib/weaponid"