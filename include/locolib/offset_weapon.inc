#if defined _locolib_offset_weapon_included
 #endinput
#endif
#define _locolib_offset_weapon_included

#include "../locolib"

methodmap OffsetWeapon {
	/**
	 * 	Get the weapon class index offset.
	 * 
	 * 	@return offset to access the variable.
	 */
	public static int DefIndex() {
		RETURN_STATIC_OFFSET("CBaseCombatWeapon", "m_iItemDefinitionIndex");
	}

	/**
	 * 	Get the weapon primary ammo offset.
	 * 
	 * 	@return offset to access the variable.
	 */
	public static int Clip1() {
		RETURN_STATIC_OFFSET("CBaseCombatWeapon", "m_iClip1");
	}
}