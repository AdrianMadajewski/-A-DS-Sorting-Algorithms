#include "Sorting.h"

//|NAME|COMPARISONS|SWAPS|TIME|

void insertionSort(std::vector<int>& data)
{
	int comparisons{ 0 };
	int swaps{ 0 };

	// Start measuring time
	auto start{ std::chrono::high_resolution_clock::now() };

	if (data.size() == 0) {
		return;
	}

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
	auto stop{std::chrono::high_resolution_clock::now() };

	auto duration{ std::chrono::duration_cast<UNIT_TIME>(stop - start) };

	std::cout << "insertionSort\t" << comparisons << "\t" << swaps << "\t" << duration.count() << "\n";
}
void mergeSort(std::vector<int>& data)
{
	return;
}
void heapSort(std::vector<int>& data)
{
	return;
}
void shellSort(std::vector<int>& data)
{
	return;
}
void quickSort(std::vector<int>& data)
{
	return;
}
