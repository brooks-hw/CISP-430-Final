#include <iostream>
#include <map>
#include "Utility.h"

int main() {

	//create and initialize hash map data structure 
	std::map <std::string, std::string> phoneBook;
	initializeData(phoneBook);

	//program continually prompts user for input until user chooses to exit
	while (true) {
		//gather input and handle choice
		int choice = displayMenu();
		handleInput(choice, phoneBook);
	}

	return 0;
}
