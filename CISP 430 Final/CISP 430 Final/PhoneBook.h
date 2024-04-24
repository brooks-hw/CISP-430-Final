#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

void displayContacts(std::map<std::string, std::string>& phoneBook);
void addAContact(std::map<std::string, std::string>& phoneBook);
void removeAContact(std::map<std::string, std::string>& phoneBook);
void changeContactInfo(std::map<std::string, std::string>& phoneBook);
void updatePhoneBook(std::map<std::string, std::string>& phoneBook);



#endif
