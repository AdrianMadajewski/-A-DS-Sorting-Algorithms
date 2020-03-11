#include <iostream>
#include "Input.h"
#include "Data.h"
#include "Sort.h"
#include "Info.h"
#include "Test.h"

int main(int argc, char* argsv[])
{
	bool userData = askUser("User data: (1) -> true, (0) -> false");

	if (userData)
	{
		std::cout << "Current stream is set to std::cout. No redirect\n";

		auto vect = generate::user_vector("Enter how many elements");

		std::cout << "Entered data:" << '\n';
		info::print_vector(std::cout, vect);

		sorts_to_execute(std::cout, vect);

		std::cout << "Data after sorting:" << '\n';
		info::print_vector(std::cout, vect);
	}

	std::cout << "\n\n";

	bool fileData = askUser("File data: (1) -> true, (0) -> false");

	if (fileData)
	{
		std::cout << "Enter filename to open a file (with filename.format)" << '\n';
		std::string filename;
		std::cin >> filename;

		auto vect = generate::file_vector(filename);
		std::cout << "Entered data:" << '\n';
		info::print_vector(std::cout, vect);
		
		std::cout << "Current stream is set to std::cout. Would you like to change?" << '\n';
		bool redirectStream = askUser("Type (1) -> true, or (0) -> false");
		
		if (redirectStream)
		{
			std::cout << "Enter a filename to redirect:" << '\n';
			std::string filename{};
			std::cin >> filename;

			std::ofstream file;
			file.open(filename, std::ios::out);

			if (!file.is_open())
			{
				std::cout << "Couldn't open file " << filename << '\n';
				std::cout << "Please restart" << '\n';
				std::cin.get();
				exit(-1);
			}
			else
			{
				std::cout << "File opened - log will be set to '" << filename << "'" << '\n';
				sorts_to_execute(file, vect);
			}
		}
		sorts_to_execute(std::cout, vect);
	}

	std::cout << "\n\n";
	
	bool testData = askUser("Test data: (1) -> true, (0) -> false");

	if (testData)
	{
		std::cout << "\n\n";

		std::cout << "This unit is for testing the program with randomized data sets." << '\n';
		std::cout << "Please enter maximum range of elements you wish to generate." << '\n';
		std::cout << "Range is by default from 10 elements to k (given by the user)." << '\n';
		auto max_elements = getUserMaxElementsRange("Enter the 'k' value.");

		std::cout << "\n\n";
		std::cout << "Program will generate sets of number." << '\n';
		std::cout << "(randomized, ascending, descending, v-shaped, a-shaped)." << '\n';
		std::cout << "Performing each of the sorting algorythm with each sets of size from 10 to " << max_elements << ".\n";

		bool full_info_mode = askUser("Enable full-info mode? (1) -> yes, (0) -> no");

		std::cout << "Default stream is std::cout. It's better to change it to a file." << '\n';

		bool redirectStream = askUser("Type (1) -> true, or (0) -> false to change.");

		if (redirectStream)
		{
			std::cout << "Enter a filename to redirect:" << '\n';
			std::string filename{};
			std::cin >> filename;

			std::ofstream file;
			file.open(filename, std::ios::out);

			if (!file.is_open())
			{
				std::cout << "Couldn't open file " << filename << '\n';
				std::cout << "Please restart" << '\n';
				std::cin.get();
				exit(-1);
			}
			else
				std::cout << "File opened - log will be set to '" << filename << "'" << '\n';

			std::cout << "\n\n";
			
			performTesting(max_elements, full_info_mode, file);
		}
		else 
			performTesting(max_elements, full_info_mode, std::cout);
	}

	std::cout << "\n\n";
	std::cout << "Thanks for using the program - press enter to quit\n";
	std::cin.get();

	return 0;
}

