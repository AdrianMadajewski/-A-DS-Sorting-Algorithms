#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>

#include "Vector.h"
#include "Sorting.h"
#include "Input.h"

std::ofstream redirect_to_file();
void ask_for_execution(std::ostream& stream, Vect& vect);

#endif 
