#ifndef __REDTEAM_H__
#define __REDTEAM_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */

/**
* ## Red Team - Akulov Natalia
* @brief Copies the content of the file at the specified path to the provided buffer.
*
* This function reads the content of a file and stores it in the provided buffer.
* Assumes that the buffer is large enough to hold the file content plus a null terminator.
*
* @param path The file path from which to read the content.
* @param buffer The buffer where the file content will be stored.
* @return A pointer to the buffer if successful, NULL if an error occurred.
*/
char* copyFileContentToBuffer(const char* path, char* buffer);


/**
* ## Red Team - Yarden Halely
* @brief Checks if the given file name has a valid file type.
*
* This function examines the file extension of the given file name to determine
* if it is a valid file type. Valid file types are "txt" and "log" in any case
* (upper or lower).
*
* The function uses the strrchr function to locate the last dot ('.') in the file name,
* and extracts the file extension. If the file extension matches one of the valid types,
* the function returns true. Otherwise, it prints a message indicating the file type
* is not valid and returns false.
*
* @param usersFile The name of the user's file as a string.
* @return true if the file type is valid ("txt" or "log"), false otherwise.
*/
bool isValidFileType(const char* usersFile);


/**
* ## Red Team - Shai Salem
* @brief Checks if the given path is an absolute path.
*
* This function determines whether a given file path is absolute or relative.
* It handles both Unix-like and Windows paths. For Unix-like paths, it checks
* if the path starts with a '/'. For Windows paths, it checks if the path
* starts with a drive letter followed by a colon (e.g., "C:\") and either a
* backslash or a forward slash.
*
* @param path The file path to check.
* @return true if the path is absolute, false otherwise.
*/
bool isAbsolutePath(const char* path);


/**
* ## Red Team - Elad Silam, Aviran Amrominm
* @brief Gets the length of a file.
*
* This function opens the specified file, moves the file pointer to the end of the file,
* and returns the file length.
*
* @param filePath The path to the file.
* @return The length of the file in bytes, or 0 if the file cannot be opened.
*/
size_t getFileLength(const char* filePath);


/**
* ## Red Team - Elad Silam, Aviran Amrominm
* @brief Allocates memory based on size.
*
* This function allocates memory for a given number of bytes and returns a pointer to the allocated memory.
*
* @param size The number of bytes to allocate.
* @return A pointer to the allocated memory, or NULL if the allocation fails.
*/
char* allocateMemory(size_t size);


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


/**
* ## Red Team - Akulov Natalia
* @brief Reads the content of a file into a dynamically allocated string.
*
* This function reads the entire content of a file specified by its path,
* allocates memory for the content plus a null terminator, and returns a pointer
* to the allocated memory. It validates the file type and checks if the path is correct.
* The caller is responsible for freeing the allocated memory.
*
* @param path The path to the file.
* @return A pointer to the allocated string, or NULL if an error occurred.
*/
char* fileContentToString(const char* path);


#endif // __REDTEAM_H__
