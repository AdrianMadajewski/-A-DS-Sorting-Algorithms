#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

void validate(std::vector<int>& data, int heapSize, int parentIndex, int& swaps, int& comparisons);
void heap_sort(std::vector<int>& data, int& comparisons, int& swaps);

#endif 
