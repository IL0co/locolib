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
}