#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>	// for std::swap()
#include <vector>
#include <chrono>		// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
						// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds

#include "Data.h"

#define UNIT_TIME std::chrono::microseconds
constexpr auto SORTS_TO_USE = 5;

enum SortType
{
	INSERTION_SORT,
	HEAP_SORT,
	MERGE_SORT,
	QUICK_SORT,
	SHELL_SORT,
};

std::string SortType_toString(SortType type);

void which_algorithm_to_use(SortType algo, Vect data, std::ostream& stream = std::cout, bool log = false);
void sorts_to_execute(std::ostream& stream, Vect& vect);

namespace insertion
{
	void sort(Vect& vect, std::ostream &stream=std::cout, bool log=false);
}

namespace heap
{
	void validate(std::vector<int>& data, int heapSize, int parentIndex, int& swaps, int& comparisons);
	void sort(Vect& vect, std::ostream& stream = std::cout, bool log = false);
}

namespace merge
{
	void sort(Vect& vect, std::ostream& stream = std::cout, bool log = false);
	void help_sort(std::vector<int>& data, int leftIndex, int rightIndex, int& comparisons, int& swaps, UNIT_TIME& duration);
	void mergeAll(std::vector<int>& data, int leftIndex, int middleIndex, int rightIndex, int& comparisons, int& swaps);
}

namespace quick
{
	void sort(Vect& vect, std::ostream& stream = std::cout, bool log = false);
}

namespace shell
{
	void sort(Vect& vect, std::ostream& stream = std::cout, bool log = false);
}


#endif