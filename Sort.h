#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>	// for std::swap()
#include <vector>
#include <chrono>		// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
						// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds

#include "Data.h"

#define UNIT_TIME std::chrono::nanoseconds

enum SortType
{
	INSERTION_SORT,
	HEAP_SORT,
	MERGE_SORT,
	QUICK_SORT,
	SHELL_SORT,
};

std::string sort_type_toString(SortType type);

void sort_to_use(SortType algo, Vect data, std::ostream& stream = std::cout, bool log = false);

namespace insertion
{
	void sort(Vect& vect, std::ostream &stream=std::cout, bool log=false);
}

namespace heap
{
	void validate(std::vector<int>& data, int heapSize, int parentIndex, int& swaps, int& comparisons);
	void sort(Vect& vect, std::ostream& stream = std::cout, bool log = false);
}


// TODO: the rest

#endif