#include "Sort.h"
#include "Info.h"

//|NAME|COMPARISONS|SWAPS|TIME|ADITIONAL

void sort_to_use(SortType algo, Vect data, std::ostream& stream, bool log)
{
	switch (algo)
	{
	case INSERTION_SORT:
		insertion::sort(data, stream, log);
		break;
	case HEAP_SORT:
		heap::sort(data, stream, log);
		break;

	default:
		stream << "SORT_ERROR" << '\n';
		break;
	}
}

std::string sort_type_toString(SortType type)
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

		if (log) {
			info::full_info(stream, INSERTION_SORT, vect.type, data.size(), comparisons, swaps, duration.count());
		}
		else {
			info::small_info(stream, INSERTION_SORT, vect.type);
		}
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

		if (log) {
			info::full_info(stream, HEAP_SORT, vect.type, data.size(), comparisons, swaps, duration.count());
		}
		else {
			info::small_info(stream, HEAP_SORT, vect.type);
		}
	}
}

