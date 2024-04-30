#include "Utility.h"
#include "PhoneBook.h"
using std::cout;

//Requires: phoneBook map created in main()
//Effects: initializes map with the data gathered from contacts.txt
//Modifies: the phoneBook map, adds elements with a name and phoneNumber field
void initializeData(std::map <std::string, std::string>& phoneBook) {
	std::ifstream inFS("contacts.txt");
	try {
		if (!inFS) {
			throw std::string("File Open Error");
		}
		else {
			std::string name, phoneNumber;
			while (inFS >> name >> phoneNumber) {
				phoneBook[name] = phoneNumber;
			}
		}
	}
	catch (std::string message) {
		cout << message;
		exit(0);
	}
}

//Requires: nothing
//Effects: displays menu and returns input to main()
//Modifies: nothing
int displayMenu() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|      Welcome to the Phone Book Manager      |\n| Please enter one of the following commands: |\n";
	cout << "-----------------------------------------------\n";
	cout << "| D: Display all contacts                     |\n| A: Add a contact                            |\n| R: Remove a contact                         |\n";
	cout << "| C: Change contact info                      |\n| U: Update contact list                      |\n| Q: Exit application                         |\n";
	cout << "-----------------------------------------------\n";
	int userChoice = gatherInput();
	return userChoice;
}

//Requires: nothing
//Effects: prompts user to enter a character to make menu selection, checks for validity
//Modifies: nothing
int gatherInput() {
	std::string userInput;
	cout << " Enter choice: ";
	
	while (true) {	//if an invalid input is entered, loop will try again
		std::cin >> userInput;
		for (char& c : userInput) {
			c = tolower(c);
		}
		if (userInput == "d") {
			return 1;
		}
		else if (userInput == "a") {
			return 2;
		}
		else if (userInput == "r") {
			return 3;
		}
		else if (userInput == "c") {
			return 4;
		}
		else if (userInput == "u") {
			return 5;
		}
		else if (userInput == "q") {
			exit(0);
		}
		else {
			cout << "\nERROR: Invalid input, please try again: ";
		}
	}
}

//Requires: user's choice in the form of an integer, and phoneBook map
//Effects: handles input by calling function selected by the user
//Modifies: Nothing
void handleInput(const int choice, std::map<std::string, std::string>& phoneBook) {
	//simple switch/case block to handle integer input, phonebook is passed by ref in all functions
	switch (choice) {
	case 1 : {
		displayContacts(phoneBook);
		return;
	}
	case 2: {
		addAContact(phoneBook);
		return;
	}
	case 3: {
		removeAContact(phoneBook);
		return;
	}
	case 4: {
		changeContactInfo(phoneBook);
		return;
	}
	case 5: {
		updatePhoneBook(phoneBook);
		return;
	}
	}
}

