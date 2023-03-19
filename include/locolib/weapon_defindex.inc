#if defined _locolib_defindex_included
 #endinput
#endif
#define _locolib_defindex_included

#include "../locolib"

methodmap WeaponDefIndex {
	/**
	 * 	Get weapon index.
	 * 
	 * 	@return weapon index.
	 */
	property CSWeaponID CSWeaponID {
		public get() {
			return CS_ItemDefIndexToID(int(this));
		}
	}
}