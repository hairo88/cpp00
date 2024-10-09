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

// long long getNumber(const std::string &prompt)
// {
// 	std::string input;
// 	long long number;

// 	while (true)
// 	{
// 		for (char c : input) {
// 			if (!isdigit(c))
// 				throw std::out_of_range("Invalid number");
// 		}

// 		try{
// 			std::istringstream iss(input);
// 			iss >> number;
// 			printf("istringstream = [%lld]\n", number);
// 			break;
// 		} 
// 		catch (const std::out_of_range& e) {
// 			std::cerr << "Number out of range" << std::endl;
// 		}
// 		catch (const std::exception &e) {
// 			std::cout << "Invalid input" << std::endl;
// 		} 
// 	}
// 	return number;
// }

long long getNumber(const std::string &prompt) {
	std::string input;
	long long 	number;

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);

		bool valid = true;
		for (std::string::size_type i = 0; i < input.size(); i++)	{
			char c = input[i];
			if (!isdigit(c)) {
				valid = false;
				break;
			}
		}

		if (valid) {
			try {
				std::istringstream iss(input);
				iss >> number;
				std:: cout << "istringstram = [" << number << "]\n";
				return number;
			} catch (const std::exception &e) {
				std::cerr << "Invalid input" << std::endl;
			}
		} else {
			std::cerr << "Invalid input: Please enter only numbers." << std::endl;
		}
	}
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

	std::cout << "Goodbye! All contacts are lost forever!" << std::endl;
	return 0;
}