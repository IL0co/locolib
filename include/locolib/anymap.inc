#if defined _locolib_anymap_included
 #endinput
#endif
#define _locolib_anymap_included

#include "../locolib"

#if !defined ANYMAP_MAXLENTH
	#define ANYMAP_MAXLENTH 	9		// The maximum buffer length for a number.
#endif

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

	/**
	 *	Clones the handle and returns a completely new copy that has nothing to do with the original.
	 *
	 *	@return Cloned Handle.
	 */
	public AnyMap Clone() {
		return view_as<AnyMap>(view_as<StringMap>(this).Clone());
	}

	/**
	 *	Set value to hash map.
	 *
	 *	@param key 					Cell key.
	 *	@param value 				The value to save.
	 *	@param replace				If false, it will not replace the existing value for the given key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool SetValue(any key, any value, bool replace = true) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).SetValue(buff, value, replace);
	}

	/**
	 *	Set array to hash map.
	 *
	 *	@param key 					Cell key.
	 *	@param array 				The array to save.
	 *	@param items 				The number of items in the array.
	 *	@param replace				If false, it will not replace the existing value for the given key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool SetArray(any key, const any[] array, int items, bool replace = true) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).SetArray(buff, array, items, replace);
	}
}