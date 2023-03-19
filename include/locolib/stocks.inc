#if defined _locolib_stocks_included
 #endinput
#endif
#define _locolib_stocks_included

#include "../locolib"

/**
 * 	Convert string to lower case.
 * 
 * 	@param input				Input string.
 * 	@param output				Output string. The buffer where the result will be placed.
 * 	@param maxLength			The maximum length of a output string.
 */
stock void StringToLower(const char[] input, char[] output, int maxLength) {
	int inputLen = strlen(input);

	for(int i; i < inputLen && i < maxLength && input[i] != '\0'; i++) {
		output[i] = CharToLower(input[i]);
	}
}

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

/**
 * 	Convert string to upper case.
 * 
 * 	@param input				Input string.
 * 	@param output				Output string. The buffer where the result will be placed.
 * 	@param maxLength			The maximum length of a output string.
 */
stock void StringToUpper(const char[] input, char[] output, int maxLength) {
	int inputLen = strlen(input);

	for(int i; i < inputLen && i < maxLength && input[i] != '\0'; i++) {
		output[i] = CharToUpper(input[i]);
	}
}

/**
 * 	Convert string to upper case.
 * 
 * 	@param input				Input string. The buffer where the result will be placed.
 * 	@param maxLength			The maximum length of a string.
 */
stock void StringToUpperEx(char[] input, int maxLength) {
	for(int i; i < maxLength && input[i] != '\0'; i++) {
		input[i] = CharToUpper(input[i]);
	}
}
