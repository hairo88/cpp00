// #include "ex01.h"
// #include "Contact.hpp"
#include "Phonebook.hpp"

std::string getInput(const std::string &prompt)
{
	std::string input;
	do{
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input.empty());
	return input;
}

long long getNumber(const std::string &prompt)
{
	std::string input;
	long long number;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
			continue;
		
		try{
			number = std::stoll(input);
			break;
		} catch (const std::exception &e) {
			std::cout << "Invalid input" << std::endl;
		} catch (const std::out_of_range& e)
		{
			std::cerr << "Number out of range" << std::endl;
		}
	}
	return number;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		command = getInput("Enter command (ADD, SEARCH, EXIT): ");

		for (size_t i = 0; i < command.length(); i++)
			command[i] = std::toupper(command[i]);

		if (command == "ADD") {
			Contact newContact;
			newContact.setContact(
				getInput("Enter first name: "),
				getInput("Enter last name: "),
				getInput("Enter nickname: "),
				getNumber("Enter phone number: "),
				getInput("Enter darkest secret: ")
			);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH") {
			phoneBook.searchContacts();
			int index;
			std::cout << "Enter index to display: ";
			std::cin >> index;
			std::cin.ignore();
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}

	std::cout << "Boodbye! All contacts are lost forever!" << std::endl;
	return 0;
}