#if defined _locolib_refindex_included
 #endinput
#endif
#define _locolib_refindex_included

#include "../locolib"

enum RefIndex {
	RefIndex_Invalid = INVALID_ENT_REFERENCE,
};

methodmap RefIndex {
	/**
	 * 	Get the entity index.
	 * 
	 * 	@return index entities or -1 if ref is invalid.
	 */
	property Entity Entity {
		public get() {
			return view_as<Entity>(EntRefToEntIndex(int(this)));
		}
	}

	/**
	 * 	Get the weapon index.
	 * 
	 * 	@return weapon index or -1 if ref is invalid.
	 */
	property Weapon Weapon {
		public get() {
			return view_as<Weapon>(this.Entity);
		}
	}
}