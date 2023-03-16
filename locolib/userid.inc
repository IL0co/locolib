#if defined _locolib_userid_included
 #endinput
#endif
#define _locolib_userid_included

#include "../locolib"

enum UserId {
	UserId_Invalid = 0,
};

methodmap UserId {
	/**
	 * 	Get the player's index.
	 * 
	 * 	@return player index.
	 */
	property Player Player {
		public get() {
			return view_as<Player>(GetClientOfUserId(int(this)));
		}
	}
}