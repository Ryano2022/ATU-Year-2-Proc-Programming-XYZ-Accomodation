#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "database.h"

typedef struct accommodationDetails {
	int   propertyID;					// Identification number of the property.
	char  ownerFirstName[20];			// Owner's first name.
	char  ownerLastName[20];			// Owner's last name.
	int   propertyBuildYear;			// Year the property was built.
	float propertyRentalCost;			// How much to rent the property each month.
	char  ownerEmail[50];				// Owner's e-mail address.
	int   accommodationType;				// Which type of accommodation is available. 1 = Single room. 2 = Apartment. 3 = Bungalow. 4 = Two story.
	int   propertyBedroomCount;			// Number of bedrooms in the property.
	bool  propertyPetsAllowed;			// Are pets allowed in the property? True/False
	int   propertyAvgStay;				// How long are you staying in the property.

	struct accommodationDetails* NEXT;	// Pointer to next node in the linked list.
}accommodationDetailsT;

accommodationDetailsT* headPtr = NULL;
accommodationDetailsT* current;
accommodationDetailsT* previous;

void accommodationAdd(int editMode) {
	int tempForPets;					// Temporary variable for the boolean variable propertyPetsAllowed.
	int tempForID;						// Temporary variable for the checking of duplicates.
	char emailCheckAt[10] = "@";		// Substring for e-mail check. "@"
	char emailCheckCom[10] = ".com";	// Substring for e-mail check. ".com"
	char tempForFirstName[20];			// Temporary variable for the checking of duplicates.
	char tempForLastName[20];			// Temporary variable for the checking of duplicates.

	// Creating and populating the node.
	if (editMode != 1) {
		current = (accommodationDetailsT*)malloc(sizeof(accommodationDetailsT) * 1);
	}
	
	// Unique property ID.
	if (editMode != 1) {
		printf("\nPlease enter the details for your new accommodation.\nProperty ID            : ");
	}
	else {
		printf("\nPlease enter the details to edit the accommodation.\nProperty ID            : ");
	}
	scanf("%d", &tempForID);
	

	if (editMode != 1) {
		accommodationDetailsT* temp = headPtr; // Temporary for the checking of duplicates.
		while (temp != NULL) {
			if (temp->propertyID == tempForID) {
				printf("\nDuplicate detected. Editing instead.");
				accommodationEdit();
				return;
			}
			temp = temp->NEXT;
		}
	}
	current->propertyID = tempForID;

	// Owner's full name.
	printf("Owner full name        : ");
	scanf("%s", tempForFirstName);
	scanf("%s", tempForLastName);

	if (editMode != 1) {
		accommodationDetailsT* temp = headPtr;
		while (temp != NULL) {
			if (strcmp(tempForFirstName, temp->ownerFirstName) == 0 && strcmp(tempForLastName, temp->ownerLastName) == 0) {
				printf("\nDuplicate detected. Editing instead.");
				accommodationEdit();
				return;
			}
			temp = temp->NEXT;
		}
	}
	strcpy(current->ownerFirstName, tempForFirstName);
	strcpy(current->ownerLastName, tempForLastName);
	
	// Year the property was built. Must be greater than or equal to 0.
	printf("Year property was built: ");
	scanf("%d", &current->propertyBuildYear);
	while (current->propertyBuildYear < 0) {
		printf("\nProperty build year cannot be BC/BCE.\n\nYear property was built: ");
		scanf("%d", &current->propertyBuildYear);
	}
	
	// Monthly rental cost of the property. Must be greater than 0.
	printf("Monthly rental cost    : ");
	scanf("%f", &current->propertyRentalCost);
	while (current->propertyRentalCost < 1) {
		printf("\nProperty rental must be greater than \033[1;96m0\033[0m.\n\nMonthly rental cost    : ");
		scanf("%f", &current->propertyRentalCost);
	}
	
	// Owner's e-mail address. Must contain an '@' and a ".com".
	printf("E-mail address         : ");
	scanf("%s", current->ownerEmail);
	while (strstr(current->ownerEmail, emailCheckAt) == NULL || strstr(current->ownerEmail, emailCheckCom) == NULL) {
		printf("\nAn \033[1;31;40m@ \033[0;37;40mor \033[1;31;40m.com\033[0;37;40m was missing, please try again.\n\nE-mail address         : ");
		scanf("%s", current->ownerEmail);
	}

	// What type of accommodation?
	printf("\n\033[1;96m1\033[0m: Single room.\n\033[1;96m2\033[0m: Apartment\n\033[1;96m3\033[0m: Bungalow\n\033[1;96m4\033[0m: Two story.\n\nAccommodation type      : ");
	scanf("%d", &current->accommodationType);
	while (current->accommodationType != 1 && current->accommodationType != 2 && current->accommodationType != 3 && current->accommodationType != 4) {
		printf("\n\033[1;96m!\033[0m Invalid selection.\n\n\033[1;96m1\033[0m: Single room.\n\033[1;96m2\033[0m: Apartment\n\033[1;96m3\033[0m: Bungalow\n\033[1;96m4\033[0m: Two story.\n\nAccommodation type      : ");
		scanf("%d", &current->accommodationType);
	}
	
	// How many bedrooms?
	printf("\n\033[1;96m1\033[0m, \033[1;96m2\033[0m, \033[1;96m3\033[0m, \033[1;96m4\033[0m, \033[1;96m5+\033[0m\n\nNumber of bedrooms     : ");
	scanf("%d", &current->propertyBedroomCount);
	while (current->propertyBedroomCount != 1 && current->propertyBedroomCount != 2 && current->propertyBedroomCount != 3 && current->propertyBedroomCount != 4 && current->propertyBedroomCount != 5) {
		printf("\n\033[1;96m!\033[0m Invalid selection.\n\n\033[1;96m1\033[0m, \033[1;96m2\033[0m, \033[1;96m3\033[0m, \033[1;96m4\033[0m, \033[1;96m5+\033[0m\n\nNumber of bedrooms     : ");
		scanf("%d", &current->propertyBedroomCount);
	}
	
	// Pets allowed? Yes or no.
	printf("Are pets allowed? \033[1;96m1\033[0m/\033[1;96m0\033[0m  : ");
	scanf("%d", &tempForPets);
	while (tempForPets != 0 && tempForPets != 1) {
		printf("\nMust be a \033[1;96m1\033[0m (\033[1;96mYes\033[0m) or \033[1;96m0\033[0m (\033[1;96mNo\033[0m).\nAre pets allowed? \033[1;96m1\033[0m/\033[1;96m0\033[0m  : ");
		scanf("%d", &tempForPets);
	}
	if (tempForPets == 0) {
		current->propertyPetsAllowed = false;
	}
	else if (tempForPets == 1) {
		current->propertyPetsAllowed = true;
	}
	
	// Stay duration.
	printf("\n\033[1;96m1\033[0m: 1 Day.\n\033[1;96m2\033[0m: >3 Days\n\033[1;96m3\033[0m: >7 Days\n\033[1;96m4\033[0m: 7+ Days.\n\nAverage stay duration  : ");
	scanf("%d", &current->propertyAvgStay);
	while (current->propertyAvgStay != 1 && current->propertyAvgStay != 2 && current->propertyAvgStay != 3 && current->propertyAvgStay != 4) {
		printf("\n\033[1;96m!\033[0m Invalid selection.\n\n\033[1;96m1\033[0m: 1 Day.\n\033[1;96m2\033[0m: >3 Days\n\033[1;96m3\033[0m: >7 Days\n\033[1;96m4\033[0m: 7+ Days.\n\nAverage stay duration  : ");
		scanf("%d", &current->propertyAvgStay);
	}

	// Connecting the node to the list.
	if (editMode != 1) {
		current->NEXT = headPtr;
		headPtr = current;

		printf("\n\033[1;96mAccommodation added.\033[0m\n");
	}
	else {
		printf("\n\033[1;96mAccommodation edited.\033[0m\n");
	}
}

void accommodationDisplay(int version) {
	int searchOption;							// Which search option the user chose. 1 = Owner name, 2 = Property ID.
	int userInputID = 0;						// User inputted property ID.
	char userInputFirstName[20] = "Default";	// User inputted first name for the owner.
	char userInputLastName[20] = "Default";		// User inputted last name for the owner.
	bool matchFound;							// Match found in the linked list?

	current = headPtr;
	if (version == 0) { // Display All
		printf("\n\033[1;96m!\033[0m Displaying all accommodation entries in the database...\n");
		while (current != NULL) {
			printf("\nProperty ID      : %d\nOwner Name       : %s %s\nYear Built       : %d\nMonthly Rental   : %.2f\nOwner E-Mail     : %s\nAccommodation Type: %d\nBedroom Count    : %d\nPets Allowed?    : %d\nAvg Stay         : %d Day(s)\n", current->propertyID, current->ownerFirstName, current->ownerLastName, current->propertyBuildYear, current->propertyRentalCost, current->ownerEmail, current->accommodationType, current->propertyBedroomCount, current->propertyPetsAllowed, current->propertyAvgStay);

			current = current->NEXT;
		}
		printf("\n");
	}
	else { // Display One
		printf("\nSearch by name [\033[1;96m1\033[0m] or by property ID [\033[1;96m2\033[0m]? ");
		scanf("%d", &searchOption);
		while (searchOption != 1 && searchOption != 2) {
			printf("\n\033[1;96m!\033[0m Invalid selection.\n");

			printf("\nSearch by name [\033[1;96m1\033[0m] or by property ID [\033[1;96m2\033[0m]? ");
			scanf("%d", &searchOption);
		}

		printf("\nSearch: ");
		if (searchOption == 1) {
			scanf("%s", userInputFirstName);
			scanf("%s", userInputLastName);
		}
		else if (searchOption == 2) {
			scanf("%d", &userInputID);
		}

		printf("\nSearching...\n");

		while (current != NULL) {
			if (strcmp(userInputFirstName, current->ownerFirstName) == 0 && strcmp(userInputLastName, current->ownerLastName) == 0) {
				matchFound = true;
			}
			else if (current->propertyID == userInputID) {
				matchFound = true;
			}
			else {
				matchFound = false;
			}

			if (matchFound == true) {
				printf("\n\033[1;96m!\033[0m Match found! Displaying:\n");
				printf("\nProperty ID      : %d\nOwner Name       : %s %s\nYear Built       : %d\nMonthly Rental   : %.2f\nOwner E-Mail     : %s\nAccommodation Type: %d\nBedroom Count    : %d\nPets Allowed?    : %d\nAvg Stay         : %d Day(s)\n", current->propertyID, current->ownerFirstName, current->ownerLastName, current->propertyBuildYear, current->propertyRentalCost, current->ownerEmail, current->accommodationType, current->propertyBedroomCount, current->propertyPetsAllowed, current->propertyAvgStay);
				return;
			}
			else {
				printf("\nNo match, next.");
				if (current->NEXT == NULL) {
					printf("No matches in the database.\n");
				}
			}
			current = current->NEXT;
		}
	}
}

void accommodationEdit() {
	int userInputID;
	bool matchFound;
	current = headPtr;

	printf("\nPlease enter the property ID number: ");
	scanf("%d", &userInputID);
	
	while (current != NULL) {
		if (current->propertyID == userInputID) {
			matchFound = true;
		}
		else {
			matchFound = false;
		}

		if (matchFound == true) {
			printf("\n\033[1;96m!\033[0m Match found! Displaying:\n");
			printf("\nProperty ID      : %d\nOwner Name       : %s %s\nYear Built       : %d\nMonthly Rental   : %.2f\nOwner E-Mail     : %s\nAccommodation Type: %d\nBedroom Count    : %d\nPets Allowed?    : %d\nAvg Stay         : %d Day(s)\n", current->propertyID, current->ownerFirstName, current->ownerLastName, current->propertyBuildYear, current->propertyRentalCost, current->ownerEmail, current->accommodationType, current->propertyBedroomCount, current->propertyPetsAllowed, current->propertyAvgStay);
			printf("\n\n\033[1;96m!\033[0m Now entering edit mode.");
			accommodationAdd(1);
			return;
		}
		else {
			printf("\nNo match, next.");
			if (current->NEXT == NULL) {
				printf("No matches in the database.\n");
			}
		}
		current = current->NEXT;
	}
}

void accommodationDelete() {
	int userInputID;
	bool matchFound;
	int areYouSure;
	current = headPtr;
	previous = NULL;

	printf("\nPlease enter the property ID number: ");
	scanf("%d", &userInputID);

	while (current != NULL) {
		if (current->propertyID == userInputID) {
			matchFound = true;
		}
		else {
			matchFound = false;
		}

		if (matchFound == true) {
			printf("\n\033[1;96m!\033[0m Match found!\n\nAre you sure you'd like to remove this accommodation entry? \033[1;96m1\033[0m/\033[1;96m0\033[0m: ");
			scanf("%d", &areYouSure);

			if (areYouSure == 1) {
				if (current = headPtr) {
					headPtr = current->NEXT;
				}
				else {
					previous->NEXT = current->NEXT;
					free(current);
				}
				printf("\n\033[1;96mAccommodation removed.\033[0m\n");
			}
			else {
				printf("\n\033[1;96m!\033[0m Cancelling...\n");
			}
			return;
		}
		else {
			printf("\nNo match, next.");
			if (current->NEXT == NULL) {
				printf("No matches in the database.\n");
			}
		}
		previous = current;
		current = current->NEXT;

	}
}

void accommodationGenStatistics() {
	int rentalMax;		// Maximum int to search for.
	int rentalMin;		// Minimum int to search for.

	printf("Please enter a maximum and a minimum int to generate statistics on.\nMaximum: ");
	scanf("%d", &rentalMax);
	printf("\nMinimum: ");
	scanf("%d", &rentalMin);
}

void accommodationSaveToFile() {
	printf("\n\033[1;96mPrint to file unimplemented.\033[0m\n");
}

void accommodationSortByMonthly() {
	printf("\n\033[1;96mBubble sort unimplemented.\033[0m\n");
}
