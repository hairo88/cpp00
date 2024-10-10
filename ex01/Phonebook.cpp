#include "Phonebook.hpp"

void PhoneBook::addContact(const Contact &contact)
{
	if (count < 8)
	{
		contacts[count] = contact;
		count++;
	}
	else
	{
		std::cout << "Phonebook is full!" << std::endl;
	}
}

void PhoneBook::searchContacts() const
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "|          " << i << "|"
			<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	if (index >= 0 && index < count)
	{
		contacts[index].display();
	}
	else
	{
		std::cout << "Invalid index" << std::endl;
	}
}

int PhoneBook::setNumber(const std::string &prompt)
{
	std::string input;
	int number;

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
				return number;
			} catch (const std::exception &e) {
				std::cerr << "Invalid input" << std::endl;
			}
		} else {
			std::cerr << "Invalid input: Please enter only numbers." << std::endl;
		}
	}
}

std::string PhoneBook::truncate(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return str;
}
