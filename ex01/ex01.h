#ifndef EX01_H
#define EX01_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void setContact(const std::string &first, const std::string &last, const std::string &nick, const std::string &phone, const std::string &darkest)
		{
			firstName = first;
			lastName = last;
			nickname = nick;
			phoneNumber = phone;
			darkestSecret = darkest;
		}
		void	display() const {
			std::cout << "First Name: " << firstName << std::endl;
			std::cout << "Last Name: " << lastName << std::endl;
			std::cout << "Nickname: " << nickname << std::endl;
			std::cout << "Darkest Secret: " << darkestSecret << std::endl;
		}
		std::string getFirstName() const { return firstName; }
		std::string getLastName() const { return lastName; }
		std::string getNickname() const { return nickname; }
};

class PhoneBook {
	private:
		Contact contacts[8];
		int count;
	public:
		PhoneBook() : count(0) {}

		void addContact(const Contact &contact) {
			contacts[count % 8] = contact;
			if (count < 8)
				count++;
		}

		void searchContacts() const {
			std::cout << "|	 Index|First Name| Last Name|  Nickname|" << std::endl;
			for (int i = 0; i < count; i++) {
				std::cout << "|         " << i << "|"
					<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
			}
		}

		void displayContact(int index) const {
			if (index >= 0 && index < count)
				contacts[index].display();
			else
				std::cout << "Invalid index" << std::endl;
		}
	private:
		std::string truncate(const std::string &str) const {
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}
};

std::string getInput(const std::string &prompt)
{
	std::string input;
	do{
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input.empty());
	return input;
}



#endif