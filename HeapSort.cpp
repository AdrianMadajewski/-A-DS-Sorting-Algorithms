#include "HeapSort.h"

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

void heap_sort(std::vector<int>& data, int& comparisons, int& swaps)
{
	if (!data.size())
		return;

	for (int i = data.size() / 2 - 1; i >= 0; i--)
		validate(data, data.size(), i, swaps, comparisons);

	for (int i = data.size() - 1; i >= 0; i--)
	{
		std::swap(data.at(0), data.at(i));
		swaps++;
		validate(data, i, 0, swaps, comparisons);
	}
}