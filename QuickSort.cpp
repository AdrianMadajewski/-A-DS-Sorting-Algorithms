#include "QuickSort.h"

void quick_sort(std::vector<int>& data, int left, int right, int& comparisons, int& swaps, std::vector<int>& parts)
{
	if (left < right)
	{
		auto middle = partition(data, left, right, comparisons, swaps);
		parts.emplace_back(middle);
		quick_sort(data, left, middle - 1, comparisons, swaps, parts);
		quick_sort(data, middle + 1, right, comparisons, swaps, parts);
	}
}

int partition(std::vector<int>& data, int left, int right, int& comparisons, int& swaps)
{
	auto x = data[right];
	auto i = left - 1;
	auto j = left;

	while (j < right)
	{
		if (data[j] <= x)
		{
			comparisons++;
			i++;
			std::swap(data[i], data[j]);
			swaps++;
		}
		j++;
	}
	std::swap(data[i + 1], data[right]);
	swaps++;
	return i + 1;
}