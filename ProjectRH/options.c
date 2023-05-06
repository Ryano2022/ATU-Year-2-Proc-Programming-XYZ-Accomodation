#include <stdio.h>
#include "options.h"
#include "database.h"

void optionsMenu() {
	int userInput;

	// DEBUG
	//printf("\n\nTest for options.c");

	printf("Please choose one of the following options:\n\n[\033[1;96m1\033[0m] : Add accommodation.\n[\033[1;96m2\033[0m] : Display all accommodations.\n[\033[1;96m3\033[0m] : Display details of an accommodation.\n[\033[1;96m4\033[0m] : Edit an accommodation.\n[\033[1;96m5\033[0m] : Delete an accommodation.\n[\033[1;96m6\033[0m] : Generate statistics.\n[\033[1;96m7\033[0m] : Print all accommodations to file.\n[\033[1;96m8\033[0m] : Order all accommodations by monthly rental.\n[\033[1;96m-1\033[0m]: Exit\n\n");
	scanf("%d", &userInput);
	
	while (userInput != -1) {
		if (userInput == 1) { // Add
			accommodationAdd(0);
		}
		else if (userInput == 2) { // Display All
			accommodationDisplay(0);
		}
		else if (userInput == 3) { // Display One
			accommodationDisplay(1);
		}
		else if (userInput == 4) { // Edit
			accommodationEdit();
		}
		else if (userInput == 5) { // Delete
			accommodationDelete();
		}
		else if (userInput == 6) { // Generate Statistics
			accommodationGenStatistics();
		}
		else if (userInput == 7) { // Print to File
			accommodationSaveToFile();
		}
		else if (userInput == 8) { // Bubble Sort
			accommodationSortByMonthly();
		}
		else { 
			printf("\n\033[1;96m!\033[0m Invalid selection.\n");
		}
		
		printf("Please choose one of the following options:\n\n[\033[1;96m1\033[0m] : Add accommodation.\n[\033[1;96m2\033[0m] : Display all accommodations.\n[\033[1;96m3\033[0m] : Display details of an accommodation.\n[\033[1;96m4\033[0m] : Edit an accommodation.\n[\033[1;96m5\033[0m] : Delete an accommodation.\n[\033[1;96m6\033[0m] : Generate statistics.\n[\033[1;96m7\033[0m] : Print all accommodations to file.\n[\033[1;96m8\033[0m] : Order all accommodations by monthly rental.\n[\033[1;96m-1\033[0m]: Exit\n\n"); 
		scanf("%d", &userInput);
	}
}
