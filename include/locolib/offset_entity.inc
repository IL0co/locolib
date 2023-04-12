#if defined _locolib_offset_entity_included
 #endinput
#endif
#define _locolib_offset_entity_included

#include "../locolib"

methodmap OffsetEntity {
	/**
	 *	Get the offset from the HammerID index of the entity.
	 * 
	 * 	@return offset to access the variable.
	 */
	public static int HammerID() {
		RETURN_STATIC_OFFSET("CBaseEntity", "m_iHammerID");
	}
}