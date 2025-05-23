#ifndef __GREENTEAM_H__
#define __GREENTEAM_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blueTeam.h"
#include "redTeam.h"

#define MAX_TIMESTAMP_LENGTH 30


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */


/**
* ## Green team
* @brief Duplicates a string without using built-in string functions.
* This function creates a duplicate of the given string by manually calculating
* its length, allocating the required memory, and copying each character to the
* newly allocated memory. The caller is responsible for freeing the allocated memory.
*
* @param original The original string to be duplicated.
* @return A pointer to the newly allocated duplicate string, or NULL if memory allocation fails.
*/
char* duplicateString(const char* original);


/**
* ## Green team
* @brief Function generates new string of the current unix timestamp (seconds since epoch - 00:00:00 01/01/1970)
*
* @return Pointer to allocated string representing the current unix timestamp in seconds,
* or NULL if allocation failed
*/
char* getUnixTimestamp();

/**
* ## Green team 
* @brief Function extracts and returns a string representing a file suffix (ending) from a file path.
*
* @param filePath : File path to extract from
* @return String representing file suffix, or NULL if allocation fails.
*/
char* getFileSuffix(char* filePath);


/**
* ## Green team 
* @brief Function allocates memory for a new string - representing a new file name made from:
* the current Unix timestamp, with a given file suffix.
*
* @param fileSuffix String representing file suffix (".txt" / ".log" / ...)
* @param unixTimestamp String representing universal timestamp (seconds since epoch - 00:00:00 01/01/1970)
* @return Pointer to allocated string representing new file name, or NULL if the allocation fails.
*/
char* allocateNewFileName(char* fileSuffix, char* unixTimestamp);


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


/**
* ## Green team 
* @brief Function builds a new file name by taking the current Unix timestamp (in seconds),
* adding to it the file extension of a relative file path.
*
* @param filePath Pointer to a string representing a relative file path.
* @return Pointer to a new allocated string representing the new file name with the correct naming convention,
* or NULL if allocation fails / filePath is not a relative file path.
*/
char* generateNewFileName(char* filePath);

/**
* ## Green team 
* @brief Function writes given message in reverse to the provided file path
*
* @param str Pointer to a string of the message to be reversed
* @param filePath Pointer to the string representing the file to write to
* @return 0 if operation is successful, -1 otherwise
*/
int writeReverseStringToFile(char* str, char* filePath);


#endif // __GREEN_TEAM_H__
