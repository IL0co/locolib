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
	 * 	And disarm the player from all weapons.
	 * 
	 * 	@param deleteWeapon			Should you delete the weapon?
	 */
	public void Disarm(bool deleteWeapon = true) {
		int weapon, offset = OffsetPlayer.WeaponsList();
		
		do {
			if((weapon = GetEntDataEnt2(int(this), offset)) != -1) {
				RemovePlayerItem(int(this), weapon);

				if(deleteWeapon && weapon > MaxClients) {
					RemoveEntity(weapon);
				}
			}
		} while(weapon != -1);
	}
}