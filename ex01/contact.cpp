#include "Contact.hpp"

void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick, long long phone, const std::string& darkest)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = darkest;
}

void Contact::display() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

long long Contact::setPhoneNumber(const std::string& phone)
{
	long long phoneNumber;
	std::string::const_iterator it = phone.begin();
	while (it != phone.end())
	{
		if (!std::isdigit(*it))
			return -1;
		it++;
	}
	std::istringstream iss(phone);
	iss >> phoneNumber;
	return phoneNumber;
}

long long Contact::setNumber(const std::string &prompt)
{
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

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

long long Contact::getPhoneNumber() const
{
	return phoneNumber;
}
