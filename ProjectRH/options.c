#include <stdio.h>
#include "options.h"
#include "database.h"

void optionsMenu() {
	int input;

	// DEBUG
	//printf("\n\nTest for options.c");

	printf("Please choose one of the following options:\n\n[\033[1;96m1\033[0m] : Add accomodation.\n[\033[1;96m2\033[0m] : Display all accomodations.\n[\033[1;96m3\033[0m] : Display details of an accomodation.\n[\033[1;96m4\033[0m] : Edit an accomodation.\n[\033[1;96m5\033[0m] : Delete an accomodation.\n[\033[1;96m6\033[0m] : Generate statistics.\n[\033[1;96m7\033[0m] : Print all accomodations to file.\n[\033[1;96m8\033[0m] : Order all accomodations by monthly rental.\n[\033[1;96m-1\033[0m]: Exit\n\n");
	scanf("%d", &input);
	
	while (input != -1) {
		if (input == 1) { // Add
			accomodationAdd();
		}
		else if (input == 2) { // Display All
			accomodationDisplay(0);
		}
		else if (input == 3) { // Display One
			accomodationDisplay(1);
		}
		else if (input == 4) { // Edit
			accomodationEdit();
		}
		else if (input == 5) { // Delete
			accomodationDelete();
		}
		else if (input == 6) { // Generate Statistics
			accomodationGenStatistics();
		}
		else if (input == 7) { // Print to File
			accomodationSaveToFile();
		}
		else if (input == 8) { // Bubble Sort
			accomodationSortByMonthly();
		}
		else { 
			printf("\n\033[1;96m!\033[0m Invalid selection.\n");
		}
		
		printf("\nPlease choose one of the following options:\n\n[\033[1;96m1\033[0m] : Add accomodation.\n[\033[1;96m2\033[0m] : Display all accomodations.\n[\033[1;96m3\033[0m] : Display details of an accomodation.\n[\033[1;96m4\033[0m] : Edit an accomodation.\n[\033[1;96m5\033[0m] : Delete an accomodation.\n[\033[1;96m6\033[0m] : Generate statistics.\n[\033[1;96m7\033[0m] : Print all accomodations to file.\n[\033[1;96m8\033[0m] : Order all accomodations by monthly rental.\n[\033[1;96m-1\033[0m]: Exit\n\n"); 
		scanf("%d", &input);
	}
}
