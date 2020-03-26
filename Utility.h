#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>

#include "Vector.h"
#include "Sorting.h"
#include "Input.h"

// Returns std::ostream data type for redirection to newly created std::ofstream
// When interupted - execution stops
std::ofstream redirect_to_file();

// Utility function to ask the user which algorithm should be executed
// Also executing them with the execute_algorithm() function defined in Sorting.h
void ask_for_execution(std::ostream& stream, Vect& vect);

#endif 
