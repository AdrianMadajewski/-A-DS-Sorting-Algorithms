#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <algorithm>	// for std::swap()
#include <vector>		// for std::vector<>()
#include <chrono>		// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
						// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds

#include "Vector.h"

#include "InsertionSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#define UNIT_TIME std::chrono::microseconds
inline constexpr auto SORTS_TO_USE = 5;

enum SortType
{
	INSERTION_SORT,
	HEAP_SORT,
	MERGE_SORT,
	QUICK_SORT,
	SHELL_SORT,
};

void execute_algorithm(SortType algo, Vect data, std::ostream& stream = std::cout, bool log = false);
std::string SortType_toString(SortType type);

#endif