#include "Input.h"

int getUserInput(std::string_view message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{};
		std::cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input - please try again." << '\n';
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return x;
		}
	}
}

int getUserDataSize(std::string_view message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x = getUserInput();
		if (x >= 1)
			return x;
		else
			std::cout << "Invalid input - please try again." << '\n';
	}
}