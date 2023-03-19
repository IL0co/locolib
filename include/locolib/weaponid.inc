#if defined _locolib_weaponid_included
 #endinput
#endif
#define _locolib_weaponid_included

#include "../locolib"

methodmap CSWeaponID {
	/**
	 * 	Get the index of a weapon by its class name or an alias.
	 * 
	 * 	@return weapon index.
	 */
	public static CSWeaponID FromClassName(const char[] className) {
		return CS_AliasToWeaponID(className);
	}
	
	/**
	 *  Get a weapon alias.
	 *  
	 * 	@param buffer				The buffer where the result will be placed.
	 * 	@param maxLength			The maximum length of the buffer.
	 * 
	 * 	@return The number of bytes written.
	 */
	public int GetAlias(char[] buffer, int maxLength) {
		return CS_WeaponIDToAlias(this, buffer, maxLength);
	}
	
	/**
	 * 	Give the player this weapon.
	 *  
	 * 	@param client				Player index.
	 * 	@param count				The number of issued weapons.
	 * 	@param equip				True - to set the weapon to the player, false - just drop next to it.
	 * 
	 * 	@return The index of the last issued weapon.
	 */
	public Weapon Give(int client, int count = 1, bool equip = true) {
		char alias[MAX_ALIAS_LENGTH];
		CS_WeaponIDToAlias(this, alias, sizeof alias);
		return Weapon.GiveByAlias(client, alias, count, equip);
	}
	
	/**
	 * 	Check the validity of the index.
	 * 
	 * 	@return true on success, false otherwise.
	 */
	property bool IsValid {
		public get() {
			return CS_IsValidWeaponID(this);
		}
	}
	
	/**
	 * 	Get the weapon class index.
	 * 
	 * 	@return weapon class index.
	 */
	property WeaponDefIndex DefIndex {
		public get() {
			return view_as<WeaponDefIndex>(CS_WeaponIDToItemDefIndex(this));
		}
	}
	
	/**
	 * 	Get a weapon slot.
	 * 
	 * 	@return slot index from WeaponSlot.
	 */
	property WeaponSlot Slot {
		public get() {
			if(!this.IsValid) {
				return Slot_Invalid;
			}

			if(this > CSWeapon_MAX_WEAPONS_NO_KNIFES && this < CSWeapon_MAX_WEAPONS) {
				return Slot_Knife;
			}
			
			switch(this) {
				case CSWeapon_KEVLAR, CSWeapon_ASSAULTSUIT, CSWeapon_DEFUSER, CSWeapon_HEAVYASSAULTSUIT, CSWeapon_CUTTERS: {
					return Slot_Invalid;
				}
				case CSWeapon_C4, CSWeapon_BUMPMINE, CSWeapon_BREACHCHARGE: {
					return Slot_C4;
				}
				case CSWeapon_TABLET: {
					return Slot_Utility;
				}
				case CSWeapon_P228, CSWeapon_GLOCK, CSWeapon_ELITE, CSWeapon_FIVESEVEN, CSWeapon_USP, CSWeapon_DEAGLE, CSWeapon_TEC9, CSWeapon_P250, CSWeapon_USP_SILENCER, CSWeapon_REVOLVER, CSWeapon_HKP2000, CSWeapon_CZ75A: {
					return Slot_Secondary;
				}
				case CSWeapon_HEGRENADE, CSWeapon_SMOKEGRENADE, CSWeapon_FLASHBANG, CSWeapon_INCGRENADE, CSWeapon_DECOY, CSWeapon_MOLOTOV, CSWeapon_TAGGRENADE, CSWeapon_FRAGGRENADE, CSWeapon_SNOWBALL, CSWeapon_DIVERSION, CSWeapon_FIREBOMB: {
					return Slot_Grenade;
				}
				case CSWeapon_HEALTHSHOT, CSWeapon_SHIELD: {
					return Slot_Boost;
				}
				case CSWeapon_KNIFE, CSWeapon_TASER, CSWeapon_KNIFE_GG, CSWeapon_KNIFE_T, CSWeapon_FISTS, CSWeapon_MELEE, CSWeapon_AXE, CSWeapon_HAMMER, CSWeapon_SPANNER, CSWeapon_KNIFE_GHOST: {
					return Slot_Knife;
				}
				default: {
					return Slot_Primary;
				}
			}
		}
	}
}