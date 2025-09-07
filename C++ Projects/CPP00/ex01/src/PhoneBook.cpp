#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

std::string PhoneBook::truncateString(const std::string &str) const {
	return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

std::string PhoneBook::getInput(const std::string &prompt) const {
	std::string input;
	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "\n👋 Goodbye!" << std::endl;
			exit(0);
		}
		if (input.empty())
			std::cout << "  ⚠️  Field cannot be empty! Try again." << std::endl;
	} while (input.empty());
	return input;
}

void PhoneBook::addContact() {
	Contact c;

	std::cout << "\n📝 Adding new contact..." << std::endl;
	c.setFirstName(getInput("First name: "));
	c.setLastName(getInput("Last name: "));
	c.setNickName(getInput("Nickname: "));
	c.setPhoneNumber(getInput("Phone number: "));
	c.setDarkestSecret(getInput("Darkest secret: "));

	contacts[currentIndex] = c;
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;

	std::cout << "✅ Contact saved successfully!" << std::endl;
}

void PhoneBook::displayContactTable() const {
	std::cout << "\n📋 Phonebook Contacts:" << std::endl;
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "Index" << "│"
			  << std::setw(10) << std::right << "First" << "│"
			  << std::setw(10) << std::right << "Last" << "│"
			  << std::setw(10) << std::right << "Nick" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

	for (int i = 0; i < totalContacts; i++) {
		std::cout << "│" << std::setw(10) << std::right << i << "│"
				  << std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "│"
				  << std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "│"
				  << std::setw(10) << std::right << truncateString(contacts[i].getNickName()) << "│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::showContact(int i) const {
	const Contact &c = contacts[i];
	std::cout << "\n👤 Contact #" << i << " Details:" << std::endl;
	std::cout << "┌─────────────────┬─────────────────────────────────┐" << std::endl;
	std::cout << "│ First Name      │ " << std::setw(31) << std::left << c.getFirstName() << " │" << std::endl;
	std::cout << "│ Last Name       │ " << std::setw(31) << std::left << c.getLastName() << " │" << std::endl;
	std::cout << "│ Nickname        │ " << std::setw(31) << std::left << c.getNickName() << " │" << std::endl;
	std::cout << "│ Phone Number    │ " << std::setw(31) << std::left << c.getPhoneNumber() << " │" << std::endl;
	std::cout << "│ Darkest Secret  │ " << std::setw(31) << std::left << c.getDarkestSecret() << " │" << std::endl;
	std::cout << "└─────────────────┴─────────────────────────────────┘" << std::endl;
}

void PhoneBook::searchContacts() const {
	if (!totalContacts) {
		std::cout << "\n📭 Phonebook is empty! Add contacts first with ADD command." << std::endl;
		return;
	}

	displayContactTable();

	std::string input;
	std::cout << "\n🔍 Enter contact index (0-" << (totalContacts - 1) << "): ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\n👋 Goodbye!" << std::endl;
		exit(0);
	}

	if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + totalContacts)
		showContact(input[0] - '0');
	else
		std::cout << "❌ Invalid index! Please enter a number between 0 and " << (totalContacts - 1) << "." << std::endl;
}
