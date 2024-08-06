#include "greenTeam.h"


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */


char* duplicateString(const char* original) {
    if (original == NULL)
    {
        return NULL;
    }
    // Calculate the length of the original string
    size_t length = strlen(original);

    // Allocate memory for the new string
    char* copy = (char*)malloc(length + 1); // + 1 for the null terminator
    if (copy == NULL) {
        // Memory allocation failed, return NULL
        printf("Failed to allocate memory\n");
        return NULL;
    }

    // Copy the original string to the new memory location
    for (int i = 0; i < length; i++) {
        copy[i] = original[i];
    }
    copy[length] = '\0'; // Null-terminate the new string

    return copy;
}


char* getUnixTimestamp()
{
    // Get the current time
    time_t currentTime = time(NULL);

    // Allocate memory for string
    char* timestampString = malloc(MAX_TIMESTAMP_LENGTH);
    if (timestampString == NULL) {
        printf("Failed to allocate memory.\n");
        // if memory allocation fails, return NULL
        return NULL;
    }

    // Format the time as a string, making sure it does not exceed MAX_TIMESTAMP_LENGTH characters
    snprintf(timestampString, MAX_TIMESTAMP_LENGTH, "%ld", currentTime);

    return timestampString;
}


char* getFileSuffix(char* filePath)
{
    // Find the last occurrence of '.' using built-in string function strrchr
    char* dot = strrchr(filePath, '.'); // pointer to last '.' in filePath
    if (dot == NULL || dot == filePath) {
        // No file extension found OR the filePath only has '.' in the beginning
        return NULL;
    }

    // Allocate memory for the suffix
    char* suffix = duplicateString(dot);
    if (suffix == NULL) {
        // memory allocation failed, return NULL
        printf("Failed to allocate memory");
        dot = NULL;
        return NULL;
    }
    return suffix;
}


char* allocateNewFileName(char* fileSuffix, char* unixTimestamp)
{
    // Calculating the length of the new line ( + 1 for the '\0')
    int totalLength = strlen(unixTimestamp) + strlen(fileSuffix) + 1;

    // Allocate memory for newline
    char* newFileName = (char*)malloc(totalLength * sizeof(char));
    if (newFileName == NULL)
    {
        // If memory allocation fails, return NULL
        return NULL;
    }

    // Form the new file name, making sure it does not exceed totalLength
    snprintf(newFileName, totalLength, "%s%s", unixTimestamp, fileSuffix);

    // Return a pointer to the new file name
    return newFileName;
}


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


char* generateNewFileName(char* filePath)
{
    if (isAbsolutePath(filePath))
    {
        // an absolute file path is not a relative file path, return NULL
        printf("File path (%s) is not a relative file path.\n", filePath);
        return NULL;
    }

    char* unixTimestamp = getUnixTimestamp();
    if (unixTimestamp == NULL)
    {
        // if memory allocation fails, return NULL
        return NULL;
    }

    char* fileSuffix = getFileSuffix(filePath);
    if (fileSuffix == NULL)
    {
        // if memory allocation fails, clean resources and return NULL
        free(unixTimestamp);
        return NULL;
    }

    char* newFileName = allocateNewFileName(fileSuffix, unixTimestamp);
    if (newFileName == NULL)
    {
        // if memory allocation fails, clean resources and return NULL
        free(unixTimestamp);
        free(fileSuffix);
        return NULL;
    }

    // clean resources and return generated file name
    free(unixTimestamp);
    free(fileSuffix);
    return newFileName;
}


int writeReverseStringToFile(char* str, char* filePath)
{
    if (str == NULL)
    {
        printf("The string provided was NULL.\n");
        return -1;
    }

    // Open the file for writing
    FILE* file = fopen(filePath, "w");
    if (file == NULL)
    {
        // if file opening fails, return -1
        printf("Failed to open file.\n");
        return -1;
    }

    // Duplicate original string in order to maintain the original
    char* strToReverse = duplicateString(str);
    if (strToReverse == NULL)
    {
        // if memory allocation fails, free resources and return -1
        printf("Failed to allocate memory.\n");
        fclose(file);
        file = NULL;
        return -1;
    }

    // Reverse the string
    reverseString(strToReverse);

    // Write the reversed string to the file
    fprintf(file, "%s", strToReverse);

    // Clean up
    fclose(file);
    free(strToReverse);
    file = NULL;
    printf("Successfully wrote to the file: %s\n", filePath);
    return 0;
}
