#if defined _locolib_weaponid_included
 #endinput
#endif
#define _locolib_weaponid_included

#include "../locolib"

methodmap CSWeaponID {
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
}