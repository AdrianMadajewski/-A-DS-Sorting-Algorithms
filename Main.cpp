#include <iostream>
#include "Input.h"
#include "Vector.h"
#include "Info.h"
#include "Test.h"
#include "Sorting.h"
#include "Utility.h"

int main()
{
	bool userData{ askUser("Enter user data? -> 1 = yes, 0 = no") };

	if (userData)
	{
		std::cout << "Current stream is set to std::cout. No redirect\n";

		auto vect{ create_user_vector("Enter how many elements") };

		std::cout << "Entered data:" << '\n';
		info::print_vector(std::cout, vect);

		ask_for_execution(std::cout, vect);

		std::sort(vect.data.begin(), vect.data.end());

		std::cout << "Data after sorting:" << '\n';
		info::print_vector(std::cout, vect);
	}

	std::cout << '\n';

	bool fileData = askUser("Enter file data? -> 1 = yes, 0 = no");

	if (fileData)
	{
		std::cout << "Enter filename to open a file" << '\n';
		std::string filename;
		std::cin >> filename;

		auto vect{ create_file_vector(filename) };
		std::cout << "Entered data:" << '\n';
		info::print_vector(std::cout, vect);
		
		std::cout << "Current stream is set to std::cout. Would you like to change?" << '\n';
		bool redirectStream = askUser("Type 1 for yes, or 0 for no");
		
		if (redirectStream)
		{
			auto output{ redirect_to_file() };
			ask_for_execution(output, vect);
		}
		else
			ask_for_execution(std::cout, vect);
	}

	std::cout << '\n';
	
	bool testData{ askUser("Run tests? -> 1 = yes, 0 = no") };

	if (testData)
	{
		std::cout << '\n';
		std::cout << "This unit is for testing the program with randomized data sets." << '\n';
		std::cout << "Please enter maximum range of elements you wish to generate." << '\n';
		std::cout << "Range is by default from 10 elements to k (with k given by the user)." << '\n';

		auto max_elements{ getUserMaxElementsRange("Enter the 'k' value.") };

		std::cout << '\n';
		std::cout << "Program will generate the following sets of numbers." << '\n';
		std::cout << "randomized, ascending, descending, v-shaped, a-shaped" << '\n';
		std::cout << "Performing each of the sorting algorythm with each set" << '\n';

		bool full_info_mode{ askUser("Enable full-info mode? -> 1 = yes, 0 = no") };

		std::cout << "Current stream is set to std::cout. Would you like to change?" << '\n';

		bool redirectStream{ askUser("Type 1 for yes, or 0 for no") };

		if (redirectStream)
		{
			auto output{ redirect_to_file() };
			performTesting(max_elements, full_info_mode, output);
		}
		else 
			performTesting(max_elements, full_info_mode, std::cout);
	}

	std::cout << "Press enter to quit" << '\n';
	std::cin.get();

	return 0;
}

