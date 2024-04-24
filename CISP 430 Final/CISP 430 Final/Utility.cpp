#include "Utility.h"
#include <iostream>
using std::cout;

void initializeData() {

}

int displayMenu() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|      Welcome to the Phone Book Manager      |\n| Please enter one of the following commands: |\n";
	cout << "-----------------------------------------------\n";
	cout << "| D: Display all contacts                     |\n| A: Add a contact                            |\n| R: Remove a contact                         |\n";
	cout << "| U: Update contact list                      |\n| Q: Exit application                         |\n-----------------------------------------------\n";
	int userChoice = gatherInput();
	return userChoice;
}

int gatherInput() {
	char userInput;
	cout << " Enter choice: ";
	
	while (true) {
		std::cin >> userInput;
		userInput = tolower(userInput);
		if (userInput == 'd') {
			return 1;
		}
		else if (userInput == 'a') {
			return 2;
		}
		else if (userInput == 'r') {
			return 3;
		}
		else if (userInput == 'c') {
			return 4;
		}
		else if (userInput == 'u') {
			return 5;
		}
		else if (userInput == 'q') {
			exit(0);
		}
		else {
			cout << "\nERROR: Invalid input, please try again: ";
		}
	}
}

