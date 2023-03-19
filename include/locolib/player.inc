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
}