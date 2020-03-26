#include <iostream>
#include "Input.h"
#include "Vector.h"
#include "Info.h"
#include "Test.h"
#include "Sorting.h"
#include "Utility.h"

// WHERE_TO_PRINT - SORT_TYPE - VECTOR_TYPE - DATA.SIZE - COMPARISONS - SWAPS - DURATION - ADDITIONAL

namespace TemporaryTestUnit
{
	inline constexpr auto DATA_SIZE = 10;
	void exec()
	{
		auto data = create_random_vector(DATA_SIZE);
		info::print_vector(std::cout, data);

		auto &data_set = data.data;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		std::chrono::time_point<std::chrono::high_resolution_clock> stop;

		int swaps{ 0 };
		int comparisons{ 0 };
		std::vector<int> additional;
		start = std::chrono::high_resolution_clock::now();

		// insertion_sort(data_set, comparisons, swaps);
		// heap_sort(data_set, comparisons, swaps);
		// merge_sort(data_set, 0, data_set.size() - 1, comparisons, swaps);
		// quick_sort(data_set, 0, data_set.size() - 1, comparisons, swaps, additional);
		shell_sort(data_set, comparisons, swaps, additional);

		stop = std::chrono::high_resolution_clock::now();

		auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

		// info::full_info(std::cout, INSERTION_SORT, data.type, DATA_SIZE, comparisons, swaps, duration.count(), additional);
		// info::full_info(std::cout, HEAP_SORT, data.type, DATA_SIZE, comparisons, swaps, duration.count(), additional);
		// info::full_info(std::cout, MERGE_SORT, data.type, DATA_SIZE, comparisons, swaps, duration.count(), additional);
		// info::full_info(std::cout, QUICK_SORT, data.type, DATA_SIZE, comparisons, swaps, duration.count(), additional);
		info::full_info(std::cout, SHELL_SORT, data.type, DATA_SIZE, comparisons, swaps, duration.count(), additional);


		info::print_vector(std::cout, data);
	}
}

int main()
{
	TemporaryTestUnit::exec();
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

