#include "../includes/PhoneBook.hpp"

int main() {
	PhoneBook book;
	std::string cmd;

	std::cout << "📞 Welcome to PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD | SEARCH | EXIT" << std::endl;

	while (1) {
		std::cout << "\nPhoneBook📞 ";
		std::getline(std::cin, cmd);

		if (std::cin.eof() || cmd == "EXIT") {
			std::cout << "\n👋 Goodbye!" << std::endl;
			break;
		}
		else if (cmd == "ADD")
			book.addContact();
		else if (cmd == "SEARCH")
			book.searchContacts();
		else if (!cmd.empty())
			std::cout << "❓ Unknown command. Use: ADD | SEARCH | EXIT" << std::endl;
	}
}
