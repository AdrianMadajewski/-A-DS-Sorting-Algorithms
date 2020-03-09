#include <iostream>
#include <string>
#include "Input.h"
#include "Data.h"
#include "Sort.h"
#include "Info.h"

// IDK IF THIS SHOULD BE THERE
constexpr auto SORTS_TO_USE = 5;

// TODO: MOVE THIS
bool askUser(const std::string_view& message = "")
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x = getUserInput();
		if (x == 1)
			return true;
		if (x == 0)
			return false;
		else
			std::cout << "Invalid input - please try again" << '\n';
	}
}

// TODO: MOVE THIS
void sorts_to_execute(std::ostream &stream, Vect &vect)
{
	std::cout << "Which algoritm to execute (1) or (0): default: (0)" << '\n';
	std::vector<bool> exec(SORTS_TO_USE, false);
	for (int i = 0; i < SORTS_TO_USE; ++i)
	{
		std::string sort_type = sort_type_toString(static_cast<SortType>(i));
		std::cout << sort_type << ": ";
		exec.at(i) = askUser();
	}

	bool full_info_mode = askUser("Enable full-info mode? (1) -> yes, (0) -> no");
	std::cout << "SORTING STARTED..." << '\n';
	
	for (int i = 0; i < SORTS_TO_USE; ++i) {
		SortType type = static_cast<SortType>(i);
		std::string s_type = sort_type_toString(type);
		sort_to_use(type, vect, stream, full_info_mode);
	}
	std::cout << "SORTING ENDED..." << '\n';
}

int main(int argc, char* argsv[])
{
	bool userData = askUser("User data: (1) -> true, (0) -> false");

	if (userData)
	{
		std::cout << "Current stream is set to std::cout. No redirect\n";

		Vect vect = generate::user_vector("Enter how many elements");

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
		std::string trash;
		std::cin.clear();
		std::getline(std::cin, filename);

		Vect vect = generate::file_vector(filename);
		std::cout << "Entered data:" << '\n';
		info::print_vector(std::cout, vect);
		
		std::cout << "Current stream is set to std::cout. Would you like to change?" << '\n';
		bool redirectStream = askUser("Type (1) -> true, or (0) -> false");
		
		// TODO:

	}


	
	bool testData = askUser("Test data: (1) -> true, (0) -> false");


	return 0;
}