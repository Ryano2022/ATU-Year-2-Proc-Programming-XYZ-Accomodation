#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "database.h"

typedef struct accomodationDetails {
	int   propertyID;					// Identification number of the property.
	char  ownerFirstName[20];			// Owner's first name.
	char  ownerLastName[20];			// Owner's last name.
	int   propertyBuildYear;			// Year the property was built.
	float propertyRentalCost;			// How much to rent the property each month.
	char  ownerEmail[50];				// Owner's e-mail address.
	int   accomodationType;				// Which type of accomodation is available. 1 = Single room. 2 = Apartment. 3 = Bungalow. 4 = Two story.
	int   propertyBedroomCount;			// Number of bedrooms in the property.
	bool  propertyPetsAllowed;			// Are pets allowed in the property? True/False
	int   propertyAvgStay;				// How long are you staying in the property.

	struct accomodationDetails* NEXT;	// Pointer to next node in the linked list.
}accomodationDetailsT;

accomodationDetailsT* headPtr = NULL;
accomodationDetailsT* current;

void accomodationAdd() {
	int tempForPets;					// Temporary variable for the boolean variable propertyPetsAllowed.
	int tempForID;						// Temporary variable for the checking of duplicates.
	char emailCheckAt[10] = "@";		// Substring for e-mail check. "@"
	char emailCheckCom[10] = ".com";	// Substring for e-mail check. ".com"

	// Creating and populating the node.
	current = (accomodationDetailsT*)malloc(sizeof(accomodationDetailsT) * 1);
	
	// Unique property ID.
	printf("\nPlease enter the details for your new accomodation.\nProperty ID            : ");
	scanf("%d", &tempForID);
	
	accomodationDetailsT* temp = headPtr;
	while (temp != NULL) {
		if (temp->propertyID == tempForID) {
			printf("Duplicate detected. Editing instead.");
			accomodationEdit();
			return;
		}
		temp = temp->NEXT;
	}

	current->propertyID = tempForID;

	
	// Owner's full name.
	printf("Owner full name        : ");
	scanf("%s", current->ownerFirstName);
	scanf("%s", current->ownerLastName);
	
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

	
	// What type of accomodation?
	printf("\n\033[1;96m1\033[0m: Single room.\n\033[1;96m2\033[0m: Apartment\n\033[1;96m3\033[0m: Bungalow\n\033[1;96m4\033[0m: Two story.\n\nAccomodation type      : ");
	scanf("%d", &current->accomodationType);
	while (current->accomodationType != 1 && current->accomodationType != 2 && current->accomodationType != 3 && current->accomodationType != 4) {
		printf("\n\033[1;96m!\033[0m Invalid selection.\n\n\033[1;96m1\033[0m: Single room.\n\033[1;96m2\033[0m: Apartment\n\033[1;96m3\033[0m: Bungalow\n\033[1;96m4\033[0m: Two story.\n\nAccomodation type      : ");
		scanf("%d", &current->accomodationType);
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
	current->NEXT = headPtr;
	headPtr = current;

	printf("\n\033[1;96mAccomodation added.\033[0m\n");
}

void accomodationDisplay(int version) {
	if (version == 0) { // Display All
		current = headPtr;
		printf("\n\033[1;96m!\033[0m Displaying all accomodation entries in the database...\n");
		while (current != NULL) {
			printf("\nProperty ID      : %d\nOwner Name       : %s %s\nYear Built       : %d\nMonthly Rental   : %.2f\nOwner E-Mail     : %s\nAccomodation Type: %d\nBedroom Count    : %d\nPets Allowed?    : %d\nAvg Stay         : %d Day(s)", current->propertyID, current->ownerFirstName, current->ownerLastName, current->propertyBuildYear, current->propertyRentalCost, current->ownerEmail, current->accomodationType, current->propertyBedroomCount, current->propertyPetsAllowed, current->propertyAvgStay);

			current = current->NEXT;
		}
		printf("\n");
	}
	else { // Display One
		printf("\n\033[1;96mDisplay one unimplemented.\033[0m\n");
	}
}

void accomodationEdit() {
	printf("\n\033[1;96mEdit unimplemented.\033[0m\n");
}

void accomodationDelete() {
	printf("\n\033[1;96mDelete unimplemented.\033[0m\n");
}

void accomodationGenStatistics() {
	printf("\n\033[1;96mGenerate statistics unimplemented.\033[0m\n");
}

void accomodationSaveToFile() {
	printf("\n\033[1;96mPrint to file unimplemented.\033[0m\n");
}

void accomodationSortByMonthly() {
	printf("\n\033[1;96mBubble sort unimplemented.\033[0m\n");
}
 