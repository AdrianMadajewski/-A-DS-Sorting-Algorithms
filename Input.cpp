#include "Input.h"

int getUserInput(const std::string_view &message)
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

int getUserDataSize(const std::string_view& message)
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

int getUserMaxElementsRange(const std::string_view& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x = getUserInput();
		if (x > 10)
			return x;
		else
			std::cout << "Invalid input - please try again." << '\n';
	}
}

bool askUser(const std::string_view& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x = getUserInput();
		switch (x)
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			std::cout << "Invalid input - please try again." << '\n';
			break;
		}
	}
}