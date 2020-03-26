#include "Sorting.h"
#include "Input.h"
#include "Info.h"

void execute_algorithm(SortType algo, Vect vector, std::ostream& stream, bool log)
{
	auto& data{ vector.data };

	int comparisons{ 0 };
	int swaps{ 0 };
	std::vector<int> additional = {};

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> stop;

	switch (algo)
	{
	case INSERTION_SORT:
		start = std::chrono::high_resolution_clock::now();
		insertion_sort(data, comparisons, swaps);
		stop = std::chrono::high_resolution_clock::now();
		break;
	case HEAP_SORT:
		start = std::chrono::high_resolution_clock::now();
		heap_sort(data, comparisons, swaps);
		stop = std::chrono::high_resolution_clock::now();
		break;
	case MERGE_SORT:
		start = std::chrono::high_resolution_clock::now();
		merge_sort(data, 0, data.size() - 1, comparisons, swaps);
		stop = std::chrono::high_resolution_clock::now();
		break;
	case QUICK_SORT:
		start = std::chrono::high_resolution_clock::now();
		quick_sort(data, 0, data.size() - 1, comparisons, swaps, additional);
		stop = std::chrono::high_resolution_clock::now();
		break;
	case SHELL_SORT:
		start = std::chrono::high_resolution_clock::now();
		shell_sort(data, comparisons, swaps, additional);
		stop = std::chrono::high_resolution_clock::now();
		break;
	default:
		stream << "SORT_ERROR" << '\n';
		return;
	}
	
	auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

	if (log)
		info::full_info(stream, algo, vector.type, vector.data.size(), comparisons, swaps, duration.count(), additional);
	else
		info::small_info(stream, algo, vector.type);
}

std::string SortType_toString(SortType type)
{
	switch (type)
	{
	case INSERTION_SORT:
		return "INSERTION_SORT";
	case HEAP_SORT:
		return "HEAP_SORT";
	case MERGE_SORT:
		return "MERGE_SORT";
	case QUICK_SORT:
		return "QUICK_SORT";
	case SHELL_SORT:
		return "SHELL_SORT";
	default:
		return "SORT_TYPE_ERROR";
	}
}