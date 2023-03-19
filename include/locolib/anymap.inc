#if defined _locolib_anymap_included
 #endinput
#endif
#define _locolib_anymap_included

#include "../locolib"

methodmap AnyMap < Handle {
	/**
	 *	Create hash map. A complete analog of StrinMap, but numbers are used instead of lowercase keys.
	 *	In fact, it is a wrapper for StringMap, for convenient use with numeric keys.
	 *	@note You must remove (close) Handle after use.
	 *
	 *	@return Handle hash map.
	 */
	public AnyMap() {
		return view_as<AnyMap>(new StringMap());
	}
}