// Windows specific Warning suppression
#if defined(_WIN32) || defined(_WIN64)
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef __GREYTEAM_H__
#define __GREYTEAM_H__

#include <stdio.h>
#define LOG_FILE "user_choices.log"


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


/**
* ## Grey Team
* @brief Displays a menu with options.
*/
void displayMenu();


/**
* ## Grey Team
* @brief Gets a valid user's choice.
*
* @return The user's choice as an integer.
*/
int getUserChoice();


/**
* ## Grey Team 
* @brief Logs the user's choice and updates the choices count array.
*
* This function increments the count for the user's choice (either option 1 or option 2),
* updates the log file with the new counts and averages, and returns the updated choices count array.
*
* @param choice The user's choice, expected to be either 1 or 2.
* @param countChoices An integer array where the choices count is stored.
*                     countChoices[0] holds the count for option 1,
*                     and countChoices[1] holds the count for option 2.
*
* @return The updated countChoices array.
*/
int* logUserChoices(int choice, int countChoices[]);


#endif // __GREYTEAM_H__
