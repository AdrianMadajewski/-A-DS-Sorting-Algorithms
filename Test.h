#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Vector.h"
#include "Sorting.h"
#include "Input.h"

inline constexpr auto MIN_ELEMENTS = 10;

/**
 * Function to test the program with each generated data sets
 *
 * @param max_elemenents maximum element capacity for created vectors
 * @param full_info_mode whether to display the full info or not
 * @param stream stream at which the generated sorting times etc. will be printed
 */
void performTesting(const int max_elements, bool full_info_mode = true, std::ostream& stream = std::cout);

#endif 