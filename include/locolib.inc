#if defined _locolib_included
 #endinput
#endif
#define _locolib_included

#tryinclude <cstrike>
#tryinclude <sdktools>

#define any(%0)		view_as<any>(%0)
#define int(%0)		view_as<int>(%0)
#define char(%0)	view_as<char>(%0)
#define bool(%0)	view_as<bool>(%0)
#define Player(%0)	view_as<Player>(%0)
#define CSWeaponID(%0)		view_as<CSWeaponID>(%0)
#define PlayerTeam(%0)		view_as<PlayerTeam>(%0)

#define MAX_ALIAS_LENGTH		32

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

enum PlayerTeam {
	Team_Invalid 	= -1,							// Invalid team index.

	Team_Spec		= CS_TEAM_SPECTATOR,			// Observer team.
	Team_None		= CS_TEAM_NONE,					// The player has not selected a team.
	Team_T			= CS_TEAM_T,					// Terrorist team.
	Team_CT			= CS_TEAM_CT,					// Counter-terrorist team.

	Team_Length,									// The total number of commands.
}

#define RETURN_STATIC_OFFSET(%0,%1) \
	static any offset = -1; \
	if(offset == -1) offset = FindSendPropInfo(%0, %1); \
	return offset

#define EVENT_USERID "userid"
#define WEAPON_PREFIX "weapon_"

#include "locolib/value"
#include "locolib/codec"
#include "locolib/anymap"
#include "locolib/offset_entity"
#include "locolib/offset_weapon"
#include "locolib/offset_player"
#include "locolib/weapon_defindex"
#include "locolib/userid"
#include "locolib/entity"
#include "locolib/player"
#include "locolib/weapon"
#include "locolib/weaponid"
#include "locolib/stocks"