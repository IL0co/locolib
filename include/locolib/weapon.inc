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
	 * 	Get weapon index.
	 * 
	 * 	@return weapon index.
	 */
	property CSWeaponID CSWeaponID {
		public get() {
			return this.DefIndex.CSWeaponID;
		}
	}

	/**
	 * 	Get a weapon index slot.
	 * 
	 * 	@return slot index.
	 */
	property WeaponSlot Slot {
		public get() {
			return this.CSWeaponID.Slot;
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
	 * 	Check the visibility of this weapon with one of the players.
	 *  
	 * 	@return client index, or 0 if no one has one.
	 */
	public any IsHaveInAnyPlayer() {
		for(int i = 1; i <= MaxClients; i++) {
			if(IsClientInGame(i) && IsPlayerAlive(i) && this.IsHaveInPlayer(i)) {
				return i;
			}
		}

		return 0;
	}

	/**
	 * 	Give the player a weapon by its name.
	 *  
	 * 	@param client				Player index.
	 * 	@param alias				The name of the weapon.
	 * 	@param count				The number of issued weapons.
	 * 	@param equip				True - to set the weapon to the player, false - just drop next to it.
	 * 
	 * 	@return The index of the last issued weapon.
	 */
	public static Weapon GiveByAlias(any client, const char[] alias, int count = 1, bool equip = true) {
		int maxLength = strlen(WEAPON_PREFIX) + strlen(alias) + 1;
		char[] className = new char[maxLength];
		FormatEx(className, maxLength, WEAPON_PREFIX ... "%s", alias);

		any weapon;

		while(count--) {
			weapon = GivePlayerItem(client, className);
			if(equip) {
				EquipPlayerWeapon(client, weapon);
			}
		}

		return weapon;
	}

	/**
	 * 	Set active for the player.
	 * 	@note The weapon must be equipped by the player.
	 *  
	 * 	@param client				Player index.
	 */
	public void SetActiveTo(any client) {
		view_as<Player>(client).SetDataEnt(OffsetPlayer.ActiveWeapon(), this);
	}
}