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

	/**
	 * 	Set entity to entity variable.
	 * 
	 * 	@param offset				Offset to variable.
	 * 	@param value				The value to set.
	 * 	@param changeState			If true, change will be sent over the network.
	 */
	public void SetDataEnt(int offset, any value, bool changeState = false) {
		SetEntDataEnt2(int(this), offset, value, changeState);
	}

	/**
	 * 	Check entity validity.
	 * 
	 * 	@return received entity from entity variable.
	 */
	public bool IsValid() {
		return int(this) > 0 && IsValidEntity(int(this));
	}

	/**
	 * 	Remove entity from the world.
	 * 	
	 * 	@note The method does not remove entity 0 (world, aka server).
	 * 
	 * 	@return true on success, false otherwise.
	 */
	public bool Remove() {
		if(int(this) > 0 && int(this) < GetMaxEntities()) {
			RemoveEntity(int(this));
			return true;
		}

		return false;
	}

	/**
	 * 	Get the HammerID index of an entity.
	 * 
	 * 	@return Index HammerID or 0 if it doesn't have one.
	 */
	property int HammerID {
		public get() {
			return this.GetDataEnt(OffsetEntity.HammerID());
		}
	}
	
	/**
	 * 	Convert the entity index to a unique encoded index (reference).
	 * 
	 * 	@error Entity index >= GetMaxEntities() or < 0.
	 * 
	 * 	@return reference index entities.
	 */
	property RefIndex RefIndex {
		public get() {
			return view_as<RefIndex>(EntIndexToEntRef(int(this)));
		}
	}
}