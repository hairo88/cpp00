#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		long long phoneNumber;
		std::string darkestSecret;
	public:
		void setContact(const std::string& first, const std::string& last, const std::string& nick, long long phone, const std::string& darkest);
		void display() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		long long getPhoneNumber() const;
		long long setNumber(const std::string &prompt);
		long long setPhoneNumber(const std::string& phone);
};

#endif