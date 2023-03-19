#if defined _locolib_value_included
 #endinput
#endif
#define _locolib_value_included

#include "../locolib"

/**
 * 	Returns the absolute value of a value.
 *
 * 	@param value 				Value.
 *
 * 	@return Absolute value.
 */
stock any AbsValue(any value) {
    return value < 0 ? -value : value;
}