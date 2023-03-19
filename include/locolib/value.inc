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

/**
 * 	Returns the minimum of two values.
 *	
 * 	@param value1 				First value.
 * 	@param value2 				Second value.
 *	
 * 	@return Minimum value.
 */
stock any MinValue(any value1, any value2) {
    return value1 < value2 ? value1 : value2;
}

/**
 *	Returns the maximum of two values.
 *	
 *	@param value1 				First value.
 *	@param value2 				Second value.
 *	
 *	@return Maximum value.
 */
stock any MaxValue(any value1, any value2) {
    return value1 > value2 ? value1 : value2;
}

/**
 *	Get the length of a number in bits.
 *	
 *	@param value 				Value.
 *	
 *	@return Length in bits.
 */
stock int GetBitsLength(any value) {
    int bits = 1;
    value = AbsValue(value);

    while(value > 1) {
        value >>= 1;
        bits++;
    }

    return bits;
}