#include "greyTeam.h"


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


void displayMenu()
{
    printf("1. Option 1 - Reverse and toggle case of file content\n");
    printf("2. Option 2 - Reverse file content and save with new name\n");
    printf("3. Exit Program\n");
}


int getUserChoice()
{
    char buffer[10];
    int choice;
    // Loop until the user enters a valid choice between 1 and 3
    while (1)
    {
        printf("Enter your choice (1-3): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {

            if (sscanf(buffer, "%d", &choice) == 1 && (choice >= 1 && choice <= 3))
            {
                break;
            }
        }
        printf("Invalid choice. Please try again.\n");
    }
    return choice;
}



int* logUserChoices(int choice, int countChoices[])
{

    // Defining the totalChoices to be the sum of the two choices
    int totalChoices = countChoices[0] + countChoices[1];

    if (choice == 1 || choice == 2)
    {
        countChoices[choice - 1]++;
        totalChoices++;
    }

    FILE* logFile = fopen(LOG_FILE, "w");
    if (logFile)
    {
        // Writing to file the current counts and ratios in a % format.
        fprintf(logFile, "Option 1 choices: %d, Ratio: %.2f%%\n", countChoices[0], ((double)countChoices[0] / totalChoices) * 100);
        fprintf(logFile, "Option 2 choices: %d, Ratio: %.2f%%\n", countChoices[1], ((double)countChoices[1] / totalChoices) * 100);
        fclose(logFile);
    }
    return countChoices;

}





