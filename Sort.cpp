#include "Sort.h"
#include "Info.h"
#include "Input.h"

void which_algorithm_to_use(SortType algo, Vect data, std::ostream& stream, bool log)
{
	switch (algo)
	{
	case INSERTION_SORT:
		insertion::sort(data, stream, log);
		break;
	case HEAP_SORT:
		heap::sort(data, stream, log);
		break;
	case MERGE_SORT:
		merge::sort(data, stream, log);
		break;
	case QUICK_SORT:
		quick::sort(data, stream, log);
		break;
	case SHELL_SORT:
		shell::sort(data, stream, log);
		break;
	default:
		stream << "SORT_ERROR" << '\n';
		break;
	}
}

void sorts_to_execute(std::ostream& stream, Vect& vect)
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

	for (int i = 0; i < SORTS_TO_USE; ++i) {
		SortType type = static_cast<SortType>(i);
		std::string s_type = SortType_toString(type);
		which_algorithm_to_use(type, vect, stream, full_info_mode);
	}
	std::cout << "SORTING ENDED..." << '\n';
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

namespace insertion
{
	void sort(Vect& vect, std::ostream& stream, bool log)
	{
		std::vector<int> &data = vect.data;
		if (!data.size())
			return;

		int comparisons{ 0 };
		int swaps{ 0 };

		// Start measuring time
		auto start{ std::chrono::high_resolution_clock::now() };

		for (auto i{ 1 }; i < data.size(); ++i) {
			auto current = data.at(i);
			auto otherIndex = i;

			while (otherIndex > 0 && current < data.at(otherIndex - 1)) {
				comparisons++;
				data.at(otherIndex) = data.at(otherIndex - 1);
				swaps++;
				otherIndex--;
			}
			data.at(otherIndex) = current;
			swaps++;
		}

		// Stop measuring time
		auto stop{ std::chrono::high_resolution_clock::now() };

		auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

		if (log)
			info::full_info(stream, INSERTION_SORT, vect.type, data.size(), comparisons, swaps, duration.count());
		else 
			info::small_info(stream, INSERTION_SORT, vect.type);
	}
}

namespace heap
{
	void validate(std::vector<int>& data, int heapSize, int parentIndex, int& swaps, int& comparisons)
	{
		if (!data.size())
			return;

		int	maxIndex{ parentIndex };
		int	leftChild{ 2 * parentIndex + 1 };
		int	rightChild{ 2 * parentIndex + 2 };

		if (leftChild < heapSize && data.at(leftChild) > data.at(maxIndex))
		{
			comparisons++;
			maxIndex = leftChild;
		}


		if (rightChild < heapSize && data.at(rightChild) > data.at(maxIndex))
		{
			maxIndex = rightChild;
			comparisons++;
		}

		if (maxIndex != parentIndex)
		{
			std::swap(data.at(maxIndex), data.at(parentIndex));
			swaps++;
			validate(data, heapSize, maxIndex, swaps, comparisons);
		}
	}

	void sort(Vect& vect, std::ostream& stream, bool log)
	{
		std::vector<int>& data = vect.data;
		if (!data.size())
			return;

		int comparisons{ 0 };
		int swaps{ 0 };

		auto start{ std::chrono::high_resolution_clock::now() };

		for (int i = data.size() / 2 - 1; i >= 0; i--)
			validate(data, data.size(), i, swaps, comparisons);

		for (int i = data.size() - 1; i >= 0; i--)
		{
			std::swap(data.at(0), data.at(i));
			swaps++;
			validate(data, i, 0, swaps, comparisons);
		}

		auto stop{ std::chrono::high_resolution_clock::now() };

		auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

		if (log) 
			info::full_info(stream, HEAP_SORT, vect.type, data.size(), comparisons, swaps, duration.count());
		else 
			info::small_info(stream, HEAP_SORT, vect.type);
	}
}

namespace merge
{
	void sort(Vect& vect, std::ostream& stream, bool log)
	{
		auto& data = vect.data;

		if (!data.size())
			return;

		int comparisons{ 0 };
		int swaps{ 0 };
		UNIT_TIME duration;

		help_sort(data, 0, data.size() - 1, comparisons, swaps, duration);

		if (log) 
			info::full_info(stream, MERGE_SORT, vect.type, data.size(), comparisons, swaps, duration.count());
		else 
			info::small_info(stream, MERGE_SORT, vect.type);

	}

	void help_sort(std::vector<int>& data, int leftIndex, int rightIndex, int &comparisons, int &swaps, UNIT_TIME &duration)
	{
		auto start{ std::chrono::high_resolution_clock::now() };
		if (leftIndex < rightIndex)
		{
			int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
			help_sort(data, leftIndex, middleIndex, comparisons, swaps, duration);
			help_sort(data, middleIndex + 1, rightIndex, comparisons, swaps, duration);

			mergeAll(data, leftIndex, middleIndex, rightIndex, comparisons, swaps);
		}
		auto stop{ std::chrono::high_resolution_clock::now() };
		duration = std::chrono::duration_cast<UNIT_TIME>(stop - start);
	}

	void mergeAll(std::vector<int>& data, int leftIndex, int middleIndex, int rightIndex, int& comparisons, int& swaps)
	{
		int* extra = new int[data.size()];
		for (int i = leftIndex; i <= rightIndex; i++)
			extra[i] = data[i];

		int finger1 = leftIndex;
		int finger2 = middleIndex + 1;
		int current = leftIndex;

		while (finger1 <= middleIndex && finger2 <= rightIndex)
		{
			if (extra[finger1] <= extra[finger2])
			{
				comparisons++;
				data[current] = extra[finger1];
				swaps++;
				finger1++;
			}
			else
			{
				comparisons++;
				data[current] = extra[finger2];
				swaps++;
				finger2++;
			}
			current++;
		}

		while (finger1 <= middleIndex)
		{
			data[current] = extra[finger1];
			swaps++;
			current++;
			finger1++;
		}
		delete[] extra;
	}

}

namespace quick
{
	void sort(Vect& vect, std::ostream& stream, bool log)
	{

	}
}

namespace shell
{
	void sort(Vect& vect, std::ostream& stream, bool log)
	{
		std::vector<int>& data = vect.data;
		if (!data.size())
			return;

		int comparisons{ 0 };
		int swaps{ 0 };

		std::vector<int> knuth;

		// Start measuring time
		auto start{ std::chrono::high_resolution_clock::now() };

		int gap = 1;
		while (gap < data.size())
			gap = gap * 3 + 1;

		while (gap > 0) {
			knuth.emplace_back(gap);
			for (int i = gap; i < data.size(); ++i) {
				auto temp = data.at(i);
				while (i >= gap && data.at(i - gap) > temp) {
					comparisons++;
					data[i] = data[i - gap];
					i -= gap;
				}
				data[i] = temp;
			}
			gap /= 3;
		}

		// Stop measuring time
		auto stop{ std::chrono::high_resolution_clock::now() };

		auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

		if (log) 
			info::full_info(stream, SHELL_SORT, vect.type, data.size(), comparisons, swaps, duration.count(), knuth);
		else 
			info::small_info(stream, SHELL_SORT, vect.type);
	}
}


