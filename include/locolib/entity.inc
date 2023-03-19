#if defined _locolib_entity_included
 #endinput
#endif
#define _locolib_entity_included

#include "../locolib"

enum Entity {
	Entity_Invalid,
};

methodmap Entity {
	/**
	 * 	Get data from an entity variable.
	 * 
	 * 	@param offset				Offset to variable.
	 * 	@param size					Number of bytes to write (valid values are 1, 2, or 4).
	 * 
	 * 	@return data retrieved from a variable.
	 */
	public any GetData(int offset, int size = 4) {
		return GetEntData(int(this), offset, size);
	}

	/**
	 * 	Set data from an entity variable.
	 * 
	 * 	@param offset				Offset to variable.
	 * 	@param value				The value to set.
	 * 	@param size					Number of bytes to write (valid values are 1, 2, or 4).
	 */
	public void SetData(int offset, any value, int size = 4) {
		SetEntData(int(this), offset, value, size);
	}

	/**
	 * 	Get entity from entity variable.
	 * 
	 * 	@param offset				Offset to variable.
	 * 
	 * 	@return received entity from entity variable.
	 */
	public any GetDataEnt(int offset) {
		return GetEntDataEnt2(int(this), offset);
	}
}