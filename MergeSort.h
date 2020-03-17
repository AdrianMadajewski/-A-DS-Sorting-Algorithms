#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

void merge_sort(std::vector<int>& data, int leftIndex, int rightIndex, int& comparisons, int& swaps);
void merge(std::vector<int>& data, int leftIndex, int middleIndex, int rightIndex, int& comparisons, int& swaps);

#endif 

