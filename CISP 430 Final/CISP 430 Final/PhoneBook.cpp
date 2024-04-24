#include "PhoneBook.h"

//Requires: a reference the phoneBook map data structure
//Effects: displays the entire formatted contents of the phoneBook
//Modifies: Nothing
void displayContacts(std::map<std::string, std::string>& phoneBook) {
	std::cout << "\nDisplaying Contacts: \n\n";
	for (const auto& contact : phoneBook) {		//for each element in phoneBook
		std::cout << std::left << "Name: " << std::setw(10) << contact.first << "Phone Number: " << contact.second << "\n";
	}
	std::cout << "\n";
}

//Requires: a reference the phoneBook map data structure
//Effects: adds a contact to the phoneBook if it doesn't already exists
//Modifies: the phoneBook map, adds one new element
void addAContact(std::map<std::string, std::string>& phoneBook) {
	std::string name, phoneNumber;
	bool validInput = false;

	while (!validInput) {	//continue to gather input until a name that doesn't exist already is entered
		std::cout << "\nEnter the name of the new contact: ";
		std::cin >> name;
		if (phoneBook.find(name) != phoneBook.end()) {
			std::cout << "Name already exists in phonebook, please try again";
		}
		else validInput = true;
	}

		//since name is valid, now enter phone number
	std::cout << "Enter the phone number of the new contact (Form XXX-XXX-XXXX): ";
	std::cin >> phoneNumber;
	phoneBook[name] = phoneNumber;		//add to map
	std::cout << "\nContact Added Successfully\n\n";
}

//Requires: a reference the phoneBook map data structure
//Effects: removes a contact from the phone book if it exists
//Modifies: the phone book, removes one element
void removeAContact(std::map<std::string, std::string>& phoneBook) {
	std::string name;
	std::cout << "\n Enter the name of the contact you wish to remove: ";
	std::cin >> name;

	if (phoneBook.find(name) != phoneBook.end()) {		//verify name is in the hash map
		phoneBook.erase(name);		//erase the contact with entered name
		std::cout << "\nContact Removed Successfully\n\n";
	}
	else std::cout << "Name does not exist in this directory!\n\n";
}

//Requires: a reference the phoneBook map data structure
//Effects: changes a single contact's phone number
//Modifies: the phoneBook map, changing an elements phone number, but not name
void changeContactInfo(std::map<std::string, std::string>& phoneBook) {
	std::string name, newNumber;
	std::cout << "\n Enter the name of the contact you wish to update: ";
	std::cin >> name;

	if (phoneBook.find(name) != phoneBook.end()) {		//verify name is in the hash map
		std::cout << "Enter the new phone number for " << name << ": ";
		std::cin >> newNumber;
		phoneBook[name] = newNumber;	//update contact's phone number
		std::cout << "\nContact Updated Successfully\n\n";
	}
	else std::cout << "Name does not exist in this directory!\n\n";
}

//Requires: a reference the phoneBook map data structure
//Effects: adds a new group of contacts to the phone book
//Modofies: the phoneBook map, adds new elements
void updatePhoneBook(std::map<std::string, std::string>& phoneBook) {
	std::ifstream inFS("updates.txt");		//open updates.txt file 
	try {
		if (!inFS) {
			throw std::string("File Open Error");
		}
		else {
			std::string name, phoneNumber;
			while (inFS >> name >> phoneNumber) {	//use same process to add new elements, are automatically sorted by name
				phoneBook[name] = phoneNumber;
			}
			std::cout << "\nPhone Book Updated Successfully\n\n";
		}
	}
	catch (std::string message) {
		std::cout << message;
		exit(0);
	}
}