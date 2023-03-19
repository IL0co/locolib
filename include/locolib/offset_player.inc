#if defined _locolib_offset_player_included
 #endinput
#endif
#define _locolib_offset_player_included

#include "../locolib"

methodmap OffsetPlayer {
	/**
	 *	Get the offset of the player's weapon list.
	 *	
	 *	@note to get the next weapon from the list, add <cell number> * 4 to the offset.
	 * 
	 * 	@return offset to access the variable.
	 */
	public static int WeaponsList() {
		RETURN_STATIC_OFFSET("CBasePlayer", "m_hMyWeapons");
	}

	/**
	 *	Get the offset of the player's active weapon.
	 * 
	 * 	@return offset to access the variable.
	 */
	public static int ActiveWeapon() {
		RETURN_STATIC_OFFSET("CBasePlayer", "m_hActiveWeapon");
	}
}