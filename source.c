
#include <assert.h>
#include <stdio.h>
#include "redTeam.h"
#include "blueTeam.h"
#include "greenTeam.h"
#include "greyTeam.h"

#define AVAILABLE_CHOICES 2
#define EXIT_CHOICE 3
#define RELATIVE_PATH_TO_FILE "DummyTxtFile.txt"

// Define OS-specific paths
#if defined(_WIN32) || defined(_WIN64)
#define ABSOLUTE_PATH_TO_FILE "C:\\Users\\elads\\Practical Software Engineering\\Year B\\Semester B\\C\\C Final Project\\lastCheck\\DummyTxtFile.txt"
#elif defined(__linux__)
#define ABSOLUTE_PATH_TO_FILE "/home/loaie/handassaim/c-essentials/final-hw/DummyTxtFile.txt"
#endif

/* ----------------------------------------------------- Function declarations ---------------------------------------------------- */


/**
* ## Team Leaders & Representitives
* @brief Function uses Asserts to check each team's main functions
*/
void test();


/**
* ## Team Leaders & Representitives
* @brief Function handles the steps required when a user inputs choice (1)
*
* Reads and saves file content from an absolute file path as a string, checks if it meets Anton's string conditions,
* takes a char as an input from the user, reverses the string - changes uppercase <--> lowercase,
* replaces all ' ' with the char input, and prints the result.
*
* Handles all the memory allocation and deallocation required for the steps.
*/
void handleFirstChoice();


/**
* ## Team Leaders & Representitives
* @brief Function handles the steps required when a user inputs choice (2)
*
* Reads and saves file content from an absolute file path as a string, generates a new file name taken from
* the current Unix timestamp (in seconds) and the file suffix of a relative file path (ex. "712930545.txt").
* Reverses the string of the file content, and writes it to a new file with the matching name.
*
* Handles all the memory allocation and deallocation required for the steps.
*/
void handleSecondChoice();


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


/**
* ## Team Leaders & Representitives
* @brief Main function that the initiates the program.
*
* Takes valid user inputs (1-3) and handles each one accordingly.
* Keeps track of all selected choices that are either '1' or '2'.
* Exits the program when selecting choice '3'.
*/
int main()
{
    // testing the teams' main functions with asserts - commented out by Anton's request
    // test();
    
    printf("Starting the program... \n");
    // Showing the menu to the user
    displayMenu();

    // Setting up variables to keep track of current and overall choices
    int countChoices[AVAILABLE_CHOICES] = { 0 };
    int currChoice = -1;

    while (currChoice != EXIT_CHOICE)
    {
        // Asking the user to input a choice.
        currChoice = getUserChoice();
        if (currChoice == EXIT_CHOICE)
        {
            printf("Thank you for using our program. Exiting...\n");
            break;
        }

        logUserChoices(currChoice, countChoices);

        if (currChoice == 1)
        {
            handleFirstChoice();
        }
        if (currChoice == 2)
        {
            handleSecondChoice();
        }
    }
    return 0;
}


void handleFirstChoice()
{
    // Reading the fileContent and assign it to "fileContent" variable.
    char* fileContent = fileContentToString(ABSOLUTE_PATH_TO_FILE);
    if (fileContent == NULL)
    {
        printf("Error while trying to read from file %s.\n", ABSOLUTE_PATH_TO_FILE);
    }

    else
    { // Successfully read fileContent
        // if string matches Anton's conditions
        if (checkStringConditions(fileContent))
        {
            // Asking the user to insert a char to replace all the spaces..
            printf("Enter desired char that will replace all the spaces: \n");
            char replaceChar;
            do
            {
                replaceChar = fgetc(stdin);
            }
            // Ensure a valid character is read
            while (replaceChar == '\n' || replaceChar == EOF);

            // Clear the input buffer
            while (fgetc(stdin) != '\n');

            //Reversing the file content
            reverseString(fileContent);

            // Converting upper to lower and lower to upper , and replacing all the spaces to the inputted character.
            changeString(fileContent, replaceChar);

            // Printing the file content!
            printf("The file content is:\n%s\n", fileContent);
            free(fileContent);
        }
        else
        {
            printf("The file content does not meet Anton's requirements\n");
            free(fileContent);
        }
    }
}


void handleSecondChoice()
{
    // Reading the fileContent and assign it to "fileContent" variable.
    char* fileContent = fileContentToString(ABSOLUTE_PATH_TO_FILE);
    if (fileContent == NULL)
    {
        printf("Error while trying to read from file %s.\n", ABSOLUTE_PATH_TO_FILE);
    }

    else
    { // Successfully read fileContent
        // Allocating and generating a string for a new file name according to Anton's instructions.
        char* newFileName = generateNewFileName(RELATIVE_PATH_TO_FILE);

        if (newFileName == NULL)
        {
            printf("Error while creating new file name from timestamp and file suffix.\n");
            free(fileContent);
        }

        else
        {
            if (writeReverseStringToFile(fileContent, newFileName) == -1)
            {
                printf("Error while trying to write the reversed file content to %s.\n", newFileName);
            }
            free(fileContent);
            free(newFileName);
        }
    }
}


void test()
{
    // 1. Testing blue team's main functions

    // 1.1 Testing checkStringConditions function
    char checkStringConditionFalse[] = "Google    1";
    char checkStringConditionTrue[] = "Google";
    assert(checkStringConditions(checkStringConditionFalse) == false);
    assert(checkStringConditions(checkStringConditionTrue) == true);

    // 1.2 Testing changeString function
    char changeStringWithSpaces[] = "AAA bbb";
    char changeStringWithoutSpaces[] = "aBaBaBa";

    changeString(changeStringWithSpaces, '$');
    assert(strcmp(changeStringWithSpaces, "aaa$BBB") == 0);

    changeString(changeStringWithoutSpaces, '@');
    assert(strcmp(changeStringWithoutSpaces, "AbAbAbA") == 0);

    // 1.3 Testing reverseString function
    char* reverseStringNULL = NULL;
    char reverseStringValid[] = "Hello world!";

    reverseString(reverseStringNULL);
    assert(reverseStringNULL == NULL);

    reverseString(reverseStringValid);
    assert(strcmp(reverseStringValid, "!dlrow olleH") == 0);


    // 2. Testing green team's main functions

    // 2.1 Testing generateNewFileName function
    char* newFileName = generateNewFileName(RELATIVE_PATH_TO_FILE);
    assert(newFileName != NULL);
    free(newFileName);

    newFileName = generateNewFileName("C:\\absolute\\path.txt");
    assert(newFileName == NULL);

    // 2.2 Testing writeReverseStringToFile function
    char testStr[] = "Hello, World!";
    int result = writeReverseStringToFile(testStr, "test_output.txt");
    assert(result == 0); // Good case

    result = writeReverseStringToFile(NULL, "");
    assert(result == -1); // Bad case


    // 3. Testing red team's main functions

    // 3.1 Testing fileContentToString function
    char* content = fileContentToString(ABSOLUTE_PATH_TO_FILE);
    assert(content != NULL);
    free(content);

    char invalidPath[] = "invalid_path.txt";
    content = fileContentToString(invalidPath);
    assert(content == NULL);


    // 4. Testing grey team's main functions

    // 4.1 Testing logUserChoices function
    int firstChoice = 1;
    int secondChoice = 2;
    int countChoices[AVAILABLE_CHOICES] = { 0 };

    logUserChoices(firstChoice, countChoices);
    assert(countChoices[0] == 1);

    logUserChoices(secondChoice, countChoices);
    assert(countChoices[1] == 1);

    printf("All tests have passed!\n\n");
}
