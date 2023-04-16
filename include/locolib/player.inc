#if defined _locolib_player_included
 #endinput
#endif
#define _locolib_player_included

#include "../locolib"

methodmap Player < Entity {
	/**
	 * 	Get a unique player number.
	 * 
	 * 	@return user id.
	 */
	property UserId UserId {
		public get() {
			return view_as<UserId>(GetClientUserId(int(this)));
		}
	}
	
	/**
	 * 	Get the player's team index.
	 * 
	 * 	@return command index.
	 */
	property PlayerTeam Team {
		public get() {
			return PlayerTeam(GetClientTeam(int(this)));
		}
	}

	/**
	 * 	Get or give out armor for the player.
	 * 
	 * 	@return current amount of armor.
	 */
	property int Armor {
		public get() {
			return this.GetData(OffsetPlayer.Armor());
		}
		public set(int value) {
			this.SetData(OffsetPlayer.Armor(), value);
		}
	}

	/**
	 * 	Get or set the player's current active weapon.
	 * 
	 * 	@param weapon				Weapon entity index.
	 * 
	 * 	@return Weapon entity index.
	 */
	property Weapon ActiveWeapon {
		public get() {
			return this.GetDataEnt(OffsetPlayer.ActiveWeapon());
		}
		public set(Weapon weapon) {
			this.SetDataEnt(OffsetPlayer.ActiveWeapon(), weapon);
		}
	}

	/**
	 * 	Take the weapon from the player.
	 * 
	 * 	@param weapon				Weapon entity index.
	 * 
	 * 	@return True on success, false otherwise.
	 */
	public bool RemoveWeapon(any weapon) {
		return RemovePlayerItem(int(this), weapon);
	}

	/**
	 * 	Obtain a weapon from the player's slot.
	 * 
	 * 	@param slot					Weapon slot index.
	 * 
	 * 	@return weapon entity index or -1 if there is no weapon.
	 */
	public Weapon GetWeapon(any slot) {
		return view_as<Weapon>(GetPlayerWeaponSlot(int(this), slot));
	}

	/**
	 * 	And disarm the player from all weapons.
	 * 
	 * 	@param deleteWeapon			Should you delete the weapon?
	 * 	@param toss					True to toss weapon (with velocity) or false to just drop weapon.
	 * 	@param blockHook			Set to true to stop the corresponding CS_OnCSWeaponDrop.
	 */
	public void Disarm(bool deleteWeapon = true, bool toss = false, bool blockHook = false) {
		Weapon weapon;
		int attempts;

		for(WeaponSlot slot; slot < Slot_Length; slot++) {
			attempts = 20;

			while(--attempts && (weapon = this.GetWeapon(slot)) > Weapon_Invalid) {
				CS_DropWeapon(int(this), int(weapon), toss, blockHook);

				if(deleteWeapon) {
					weapon.Remove();
				}
			}

		}
	}
}