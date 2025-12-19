#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

    std::string truncateString(const std::string &str) const;
    std::string getInput(const std::string &prompt) const;
    void displayContactTable() const;
    void showContact(int index) const;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif
