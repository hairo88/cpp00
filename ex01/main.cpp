#include "ex01.h"

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
				getInput("Enter phone number: "),
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