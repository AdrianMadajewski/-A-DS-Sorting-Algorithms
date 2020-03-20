#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

void quick_sort(std::vector<int>& data, int left, int right, int& comparisons, int& swaps, std::vector<int>& pivots);
int partition(std::vector<int>& data, int left, int right, int& comparisons, int& swaps, std::vector<int> &pivots);

#endif




