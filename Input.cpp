#include "Input.h"

int getUserInput(std::string_view message)
{
	while (true)
	{
		if (!message.empty())
			std::cout << message << '\n';

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

std::vector<int> createUserPromptedVector(const int vector_size)
{
	std::cout << "Prompt with " << vector_size << " number to create a vector." << '\n';
	std::vector<int> result{};
	for (int i{ 0 }; i < vector_size; ++i)
	{
		int x{ getUserInput("") };
		result.emplace_back(x);
	}
	return result;
}

int getUserVectorSize(std::string_view message)
{
	while (true)
	{
		int x{ getUserInput(message) };
		if (x > 10 || x < 1)
			std::cout << "You entered a wrong number - must from [1, 10]" << '\n';
		else
			return x;
	}
}