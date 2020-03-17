#ifndef INFO_H
#define INFO_H

#include <iostream>

#include "Sorting.h"
#include "Vector.h"
#include "Input.h"

namespace info
{
	void print_vector(std::ostream& stream, Vect &vect);
	void full_info(std::ostream& stream, SortType s_type, VectType v_type, int v_size, int comparisons, int swaps, int duration, std::vector<int> additional = {});
	void small_info(std::ostream& stream, SortType s_type, VectType v_type);
}

#endif
