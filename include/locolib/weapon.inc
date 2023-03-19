#if defined _locolib_weapon_included
 #endinput
#endif
#define _locolib_weapon_included

#include "../locolib"

enum Weapon {
	Weapon_Invalid,
};

methodmap Weapon < Entity {
	/**
	 * 	Get the weapon class index.
	 * 
	 * 	@return weapon class index.
	 */
	property WeaponDefIndex DefIndex {
		public get() {
			return this.GetData(OffsetWeapon.DefIndex());
		}
	}
	
	/**
	 * 	Get the weapon's entity index from the player's slot.
	 * 
	 * 	@return weapon class index.
	 */
	public static Weapon FromPlayerSlot(any client, WeaponSlot slot) {
		return view_as<Weapon>(GetPlayerWeaponSlot(client, int(slot)));
	}
	
	/**
	 * 	Check if the player has a weapon.
	 *  
	 * 	@param client				Player index.
	 * 
	 * 	@return true on success, false otherwise.
	 */
	public bool IsHaveInPlayer(any client) {
		int index, offset = OffsetPlayer.WeaponsList();
		
		do {
			if((index = GetEntDataEnt2(client, offset)) == int(this)) {
				return true;
			}

			offset += 4;
		} while(index != -1);

		return false;
	}

	/**
	 * 	Give the player a weapon by its name.
	 *  
	 * 	@param client				Player index.
	 * 	@param alias				The name of the weapon.
	 * 	@param count				The number of issued weapons.
	 */
	public static void GiveByAlias(any client, const char[] alias, int count = 1) {
		int maxLength = strlen(WEAPON_PREFIX) + strlen(alias) + 1;
		char[] className = new char[maxLength];
		FormatEx(className, maxLength, WEAPON_PREFIX ... "%s", alias);

		while(count--) {
			EquipPlayerWeapon(client, GivePlayerItem(client, className));
		}
	}
}