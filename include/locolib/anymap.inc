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

	/**
	 *	Set string to hash map.
	 *
	 *	@param key 					Cell key.
	 *	@param buffer 				The string to save.
	 *	@param replace				If false, it will not replace the existing value for the given key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool SetString(any key, const char[] buffer, bool replace = true) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).SetString(buff, buffer, replace);
	}

	/**
	 *	Get the value from the hash map into an argument.
	 *
	 *	@param key 					Cell key.
	 *	@param buffer 				The buffer where the result will be placed.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool GetValueIn(any key, any &buffer) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).GetValue(buff, buffer);
	}

	/**
	 *	Get value from hash map.
	 *
	 *	@param key 					Cell key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public any GetValue(any key) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		any value;
		view_as<StringMap>(this).GetValue(buff, value);

		return value;
	}

	/**
	 *	Get an array into a hash map.
	 *
	 *	@param key 					Cell key.
	 *	@param buffer 				The buffer where the result will be placed.
	 *	@param maxLength			The length of the array.
	 *	@param size					(optional) A buffer where the number of items in the array will be written.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool GetArray(any key, any[] buffer, int maxLength, int &size) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).GetArray(buff, buffer, maxLength);
	}

	/**
	 *	Get string from hash map.
	 *
	 *	@param key 					Cell key.
	 *	@param buffer 				The buffer where the result will be placed.
	 *	@param maxLength			The maximum length of a string.
	 *	@param size					(optional) A buffer where the number of bytes in the string will be written.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool GetString(any key, char[] buffer, int maxLength, int &size) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).GetString(buff, buffer, maxLength, size);
	}

	/**
	 *	Check for the presence of a key in the hash map.
	 *
	 *	@param key 					Cell key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool ContainsKey(any key) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).ContainsKey(buff);
	}

	/**
	 *	Remove the key and its value from the hash map.
	 *
	 *	@param key 					Cell key.
	 *
	 *	@return true on success, false otherwise.
	 */
	public bool Remove(any key) {
		char buff[ANYMAP_MAXLENTH];
		FormatEx(buff, sizeof buff, "%08X", key);

		return view_as<StringMap>(this).Remove(buff);
	}

	/**
	 *	Removes all keys and their values ​​from the hash map.
	 */
	public void Clear() {
		view_as<StringMap>(this).Clear();
	}

	/**
	 *	Create a snapshot of the keys in the hash map.
	 *	@note You must remove (close) Handle after use.
	 *
	 *	@return The hash map snapshot handle.
	 */
	public AnyMapSnapshot Snapshot() {
		return view_as<AnyMapSnapshot>(view_as<StringMap>(this).Snapshot());
	}

	/**
	 *	Get the number of keys in the hash map.
	 *	
	 *	@return number of keys.
	 */
	property int Size {
		public get() {
			return view_as<StringMap>(this).Size;
		}
	}
}

methodmap AnyMapSnapshot < Handle {

}