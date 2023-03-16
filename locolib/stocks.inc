#if defined _locolib_stocks_included
 #endinput
#endif
#define _locolib_stocks_included

#include "../locolib"

/**
 * 	Convert string to lower case.
 * 
 * 	@param input				Input string. The buffer where the result will be placed.
 * 	@param maxLength			The maximum length of a string.
 */
stock void StringToLowerEx(char[] input, int maxLength) {
	for(int i; i < maxLength && input[i] != '\0'; i++) {
		input[i] = CharToLower(input[i]);
	}
}
