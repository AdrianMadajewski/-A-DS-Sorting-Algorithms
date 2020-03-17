#include "Utility.h"

std::ofstream redirect_to_file()
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
		return file;
	}
}

void ask_for_execution(std::ostream& stream, Vect& vect)
{
	std::cout << "Which algoritm to execute (1) or (0): default: (0)" << '\n';
	std::vector<bool> exec(SORTS_TO_USE, false);
	for (int i = 0; i < SORTS_TO_USE; ++i)
	{
		std::string sort_type = SortType_toString(static_cast<SortType>(i));
		std::cout << sort_type << ": ";
		exec.at(i) = askUser();
	}

	bool full_info_mode = askUser("Enable full-info mode? -> 1 = yes, 0 = no");
	std::cout << "SORTING STARTED..." << '\n';

	for (auto i{ 0 }; i < SORTS_TO_USE; ++i) {
		SortType type = static_cast<SortType>(i);
		if (exec.at(i))
			execute_algorithm(type, vect, stream, full_info_mode);
	}
	std::cout << "SORTING ENDED..." << '\n';
}
