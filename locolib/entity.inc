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
	 * 	@return data retrieved from a variable.
	 */
	public any GetData(int offset, int size = 4) {
		return GetEntData(int(this), offset, size);
	}
}