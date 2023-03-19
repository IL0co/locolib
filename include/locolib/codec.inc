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
	 *	Decodes two values into one integer value.
	 *	@note Float numbers are not encoded since it occupies the entire range (sign, mantis, exponent).
	 *
	 *	@param value1 				First value.
	 *	@param value2 				Second value.
	 *	@param maxlengthValue2		The maximum number that can be in the second value.
	 *
	 *	@return Decoded value.
	 */
	public static int Decode(any value1, any value2, int maxlengthValue2 = 0xFFFF) {
		return (value1 << GetBitsLength(maxlengthValue2) | value2);
	}

	/**
	 *	Encodes an integer value into two values.
	 *
	 *	@param decoded 				Encoded value.
	 *	@param value1 				First value.
	 *	@param value2 				Second value.
	 *	@param maxlengthValue2		The maximum number that can be in the second value.
	 */
	public static void Encode(any decoded, any &value1, any &value2, int maxlengthValue2 = 0xFFFF) {
		value1 = (decoded >> GetBitsLength(maxlengthValue2));
		value2 = (decoded & maxlengthValue2);
	}
}