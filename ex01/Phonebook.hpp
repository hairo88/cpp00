#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int count;
	public:
		PhoneBook() : count(0) {};
		void addContact(const Contact &contact);
		void searchContacts() const;
		void displayContact(int index) const;
		int  setNumber(const std::string &prompt);
	private:
		std::string truncate(std::string str) const;
		std::string getFormattedContact(const Contact& contact) const ;
};

#endif