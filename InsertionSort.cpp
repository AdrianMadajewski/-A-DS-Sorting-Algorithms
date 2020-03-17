#include "InsertionSort.h"

void insertion_sort(std::vector<int>& data, int& comparisons, int& swaps)
{
	if (!data.size())
		return;

	for (auto i{ 1 }; i < data.size(); ++i) {
		auto current = data.at(i);
		auto otherIndex = i;

		comparisons++;
		while (otherIndex > 0 && current < data.at(otherIndex - 1)) {
			data.at(otherIndex) = data.at(otherIndex - 1);
			swaps++;
			otherIndex--;
		}
		data.at(otherIndex) = current;
		swaps++;
	}
}