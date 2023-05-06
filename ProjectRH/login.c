#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "login.h"

void login() {
    int i;
    FILE* fp;                           // File pointer.
    char nameGuess[30];                 // User entered username.
    char nameStored[30];                // The actual username.
    char passGuess[PASS_LENGTH];        // User entered password.
    char passStored[PASS_LENGTH];       // The actual password.
    char loginFile[10] = "login.txt";   // File name of the log-in file.

    // Log-in file.
    fp = fopen(loginFile, "r");
    if (fp != NULL) {
        fscanf(fp, "%s", nameStored);
        fscanf(fp, "%s", passStored);
        fclose(fp);

        // DEBUG
        //printf("%s", nameStored);
        //printf("%s", passStored);
    }
    else { // Making a default user name and password in a file called login.txt
        printf("%s not found!\nCreating the file and adding the default username (default@xyzaccommodation.com) and password (111111). ", loginFile);
        fp = fopen(loginFile, "w");
        fprintf(fp, "default@xyzaccommodation.com\n");
        strcpy(nameStored, "default@xyzaccommodation.com");
        fprintf(fp, "111111");
        strcpy(passStored, "111111");
        fclose(fp);
        printf("\nFile created.\n\n");
    }
    
    while (strcmp(nameGuess, nameStored) != 0) { // Checking to make sure the names match.
        printf("Please enter your username: ");
        scanf("%s", nameGuess);

        if (strcmp(nameGuess, nameStored) == 0) {
            printf("\n");
        }
        else {
            printf("Username is incorrect or does not exist.\nPlease note that you need to include @xyzaccommodation.com in your username.\n\n");
        }
    }
    
    while (strcmp(passGuess, passStored) != 0) { // Checking to make sure the passwords match.
        printf("Password: ");
        // Code from the next eleven lines has been taken (and modified to fit this program) from
        // the following site: https://www.geeksforgeeks.org/getch-function-in-c-with-examples/
        for (i = 0; i < (PASS_LENGTH - 1); i++) {
            // Get the hidden input
            // using getch() method
            passGuess[i] = getch();

            // Print * to show that
            // a character is entered
            printf("*");
        }
        passGuess[i] = '\0';
        printf("\n");

        if (strcmp(passGuess, passStored) == 0) {
            printf("Password is correct.\n\n");
        }
        else {
            printf("Password is incorrect.\nPlease note that may only use numbers in your password.\n\n");
        }

        // DEBUG
        //printf("\nLog-in File: %s\nPass       : %s\nGuess      : %s\n", loginFile, passStored, passGuess);
    }

    if (strcmp(nameGuess, nameStored) == 0 && strcmp(passGuess, passStored) == 0) { // Finally just a confirmation of log-in.
        printf("Log-in successful. Access to the database has been granted.\n");
    }
    else {
        // I'm not sure how you'd make it to this stage with all the previous checks but just in case.
        printf("\n\nLog-in unsuccessful. Access to the database has been denied.\n");
        exit(0);
    }
}
