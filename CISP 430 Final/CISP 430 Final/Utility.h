#ifndef UTILTIY_H
#define UTILTIY_H

#include <iostream>
#include <fstream>
#include <map>

void initializeData(std::map <std::string, std::string>& phoneBook);
int displayMenu();
int gatherInput();
void handleInput(const int choice, std::map<std::string, std::string>& phoneBook);



#endif