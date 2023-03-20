#if defined _locolib_codec_included
 #endinput
#endif
#define _locolib_codec_included

#include "../locolib"

enum Codec {
	Codec_Invalid,
};

methodmap Codec {
	/**
	 *	Encodes two values into one integer value.
	 *	@note Float numbers are not encoded since it occupies the entire range (sign, mantis, exponent).
	 *
	 *	@param value1 				First value.
	 *	@param value2 				Second value.
	 *	@param maxlengthValue2		The maximum number that can be in the second value.
	 *
	 *	@return encoded value.
	 */
	public static int Encode(any value1, any value2, int maxlengthValue2 = 0xFFFF) {
		return (value1 << GetBitsLength(maxlengthValue2) | value2);
	}

	/**
	 *	Decodes an integer value into two values.
	 *
	 *	@param encoded 				Encoded value.
	 *	@param value1 				First value.
	 *	@param value2 				Second value.
	 *	@param maxlengthValue2		The maximum number that can be in the second value.
	 */
	public static void Decode(any encoded, any &value1, any &value2, int maxlengthValue2 = 0xFFFF) {
		value1 = (encoded >> GetBitsLength(maxlengthValue2));
		value2 = (encoded & maxlengthValue2);
	}
}