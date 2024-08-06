#include "blueTeam.h"


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */


bool checkSpaceToCharRatio(char* str) {
    if (str == NULL)
    {
        printf("The given string is NULL.\n");
        return false;
    }
    int spaceCount = 0;
    int charCount = 0;

    // Count spaces and non-space characters
    for (unsigned short index = 0; str[index] != '\0'; index++) {
        if (str[index] == ' ') {
            spaceCount++;
        }
        else {
            charCount++;
        }
    }

    // Check if spaces are less than half of total characters
    if (spaceCount * 2 < charCount) {
        return true;
    }
    else {
        return false;
    }
}


bool isUpperCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    else {
        return false;
    }
}


bool isLowerCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    else {
        return false;
    }
}


bool checkStartEndCharacters(char* str) {
    if (str == NULL)
    {
        printf("The given string is NULL.\n");
        return false;
    }
    int len = strlen(str);

    // Check for empty string
    if (len == 0) {
        return false;
    }

    // Check first and last characters
    if (isUpperCase(str[0]) && isLowerCase(str[len - 1])) {
        return true;
    }
    else {
        return false;
    }
}


bool checkUppercasePosition(char* str) {
    if (str == NULL)
    {
        printf("The given string is NULL.\n");
        return false;
    }
    unsigned short i = 0;

    // Check the first character if it's uppercase
    if (str[i] != '\0' && isUpperCase(str[i])) {
        i++;
    }

    // Traverse through the string
    while (str[i] != '\0') {
        // If an uppercase letter is found not at the beginning or after a space, return false
        if (isUpperCase(str[i]) && str[i - 1] != ' ') {
            return false;
        }
        i++;
    }
    return true;
}


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


bool checkStringConditions(char* str) {
    if (str == NULL)
    {
        printf("The given string is NULL.\n");
        return false;
    }
    // Check each condition
    if (!checkSpaceToCharRatio(str)) {
        return false;
    }
    if (!checkStartEndCharacters(str)) {
        return false;
    }
    if (!checkUppercasePosition(str)) {
        return false;
    }
    return true;
}


void changeString(char* str, char replaceChar) {
    if (str == NULL || replaceChar == NULL)
    {
        printf("The given variable is NULL.\n");
        return;
    }
    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // If the character is an uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Convert to lowercase
            str[i] = str[i] + ('a' - 'A');
        }
        // If the character is a lowercase letter
        else if (str[i] >= 'a' && str[i] <= 'z') {
            // Convert to uppercase
            str[i] = str[i] - ('a' - 'A');
        }
        // If the character is a space
        else if (str[i] == ' ') {
            // Replace with the specified character
            str[i] = replaceChar;
        }
    }
}


void reverseString(char* str) {
    if (str != NULL)
    {
        int length = strlen(str);  // Length of the string
        int start = 0;             // Start index of the string
        int end = length - 1;      // End index of the string
        char temp;                 // Temporary variable for swapping

        // Loop to swap characters from both ends
        while (start < end) {
            // Swap the characters
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;

            // Move the indices towards the center
            start++;
            end--;
        }
    }
    else
    {
        printf("The given string is NULL.\n");
    }
}

