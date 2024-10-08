#include "Phonebook.hpp"
#include <unistd.h>

std::string getInput(const std::string &prompt)
{
	std::string input;
	do{
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input.empty());
	return input;
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
				newContact.getInput("Enter first name: "),
				newContact.getInput("Enter last name: "),
				newContact.getInput("Enter nickname: "),
				newContact.setNumber("Enter phone number: "),
				newContact.getInput("Enter darkest secret: ")
			);
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH") {
			phoneBook.searchContacts();
			int index;
			index = phoneBook.setNumber("Enter index to display: ");			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
		// sleep(100);
	}

	std::cout << "Goodbye! All contacts are lost forever!" << std::endl;
	return 0;
}