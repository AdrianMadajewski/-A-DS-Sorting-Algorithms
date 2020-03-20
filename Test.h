#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Vector.h"
#include "Sorting.h"
#include "Input.h"

inline constexpr auto MIN_ELEMENTS = 10;

void performTesting(const int max_elements, bool full_info_mode = true, std::ostream& stream = std::cout);

#endif 