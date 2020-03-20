#include "QuickSort.h"

void quick_sort(std::vector<int>& data, int left, int right, int& comparisons, int& swaps, std::vector<int>& pivots)
{
	if (!data.size())
		return;

	if (left < right)
	{
		int middle = partition(data, left, right, comparisons, swaps, pivots);
		quick_sort(data, left, middle - 1, comparisons, swaps, pivots);
		quick_sort(data, middle + 1, right, comparisons, swaps, pivots);
	}
}

int partition(std::vector<int>& data, int left, int right, int& comparisons, int& swaps, std::vector<int> &pivots)
{
	auto pivot = data[right];
	pivots.emplace_back(pivot);
	auto i = left - 1;
	auto j = left;

	while (j < right)
	{
		if (data[j] <= pivot)
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