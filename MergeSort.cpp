#include "MergeSort.h"

void merge_sort(std::vector<int>& data, int leftIndex, int rightIndex, int& comparisons, int& swaps)
{
	if (!data.size())
		return;

	if (leftIndex < rightIndex)
	{
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
		merge_sort(data, leftIndex, middleIndex, comparisons, swaps);
		merge_sort(data, middleIndex + 1, rightIndex, comparisons, swaps);
		merge(data, leftIndex, middleIndex, rightIndex, comparisons, swaps);
	}
}

void merge(std::vector<int>& data, int leftIndex, int middleIndex, int rightIndex, int& comparisons, int& swaps)
{
	int* extra = new int[data.size()];
	for (int i = leftIndex; i <= rightIndex; i++)
		extra[i] = data[i];

	int finger1 = leftIndex;
	int finger2 = middleIndex + 1;
	int current = leftIndex;

	while (finger1 <= middleIndex && finger2 <= rightIndex)
	{
		comparisons++;
		if (extra[finger1] <= extra[finger2])
		{
			data[current] = extra[finger1];
			finger1++;
		}
		else
		{
			data[current] = extra[finger2];
			finger2++;
		}
		current++;
	}

	while (finger1 <= middleIndex)
	{
		data[current] = extra[finger1];
		current++;
		finger1++;
	}
	delete[] extra;
}