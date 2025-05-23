#ifndef __BLUETEAM_H__
#define __BLUETEAM_H__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */


/**
* ## Blue Team
* @brief Checks if the number of spaces in the string is less than half the number of characters.
*
* @param str The input string.
* @return true if the condition is met, false otherwise.
*/
bool checkSpaceToCharRatio(char* str);


/**
* ## Blue Team
* @brief Checks if a character is an uppercase letter.
*
* @param c The character to check.
* @return true if the character is uppercase, false otherwise.
*/
bool isUpperCase(char c);


/**
* ## Blue Team
* @brief Checks if a character is a lowercase letter.
*
* @param c The character to check.
* @return true if the character is lowercase, false otherwise.
*/
bool isLowerCase(char c);


/**
* ## Blue Team
* @brief Checks if the string starts with an uppercase letter and ends with a lowercase letter.
*
* @param str The input string.
* @return true if the condition is met, false otherwise.
*/
bool checkStartEndCharacters(char* str);


/**
* ## Blue Team
* @brief Checks if uppercase letters appear only at the beginning of the string or after a space character.
*
* @param str The input string.
* @return true if the condition is met, false otherwise.
*/
bool checkUppercasePosition(char* str);


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


/**
* ## Blue Team
* @brief Main function that checks if the string meets all the conditions.
*
* @param str The input string.
* @return true if all conditions are met, false otherwise.
*/
bool checkStringConditions(char* str);


/**
* ## Blue Team
* @brief Converts characters in a string based on specified rules.
* This function modifies the input string by converting uppercase letters to lowercase,
* converting lowercase letters to uppercase, and replacing spaces with a specified character.
*
* @param str Pointer to the string to be modified.
* @param replaceChar The character to replace spaces in the string.
*/
void changeString(char* str, char replaceChar);


/**
* ## Blue Team
* @brief Reverses the characters of a string in place.
*
* @param str Pointer to the string to be reversed.
*/
void reverseString(char* str);

#endif // __BLUETEAM_H__

