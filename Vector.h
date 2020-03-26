#ifndef VECTOR_H
#define VECTOR_H

#include "Random.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

static constexpr auto VECTOR_DATA_MIN = 0;
static constexpr auto VECTOR_DATA_MAX = 10000;

enum VectType
{
	RANDOM_VECT,
	ASC_VECT,
	DESC_VECT,
	V_SHAPED_VECT,
	A_SHAPED_VECT,
	USER_VECT,
	FILE_VECT
};

std::string VectType_toString(VectType type);

struct Vect
{
	VectType type;
	std::vector<int> data;
	Vect(VectType type, std::vector<int> data) : type(type), data(data) {}
	Vect() = default;
};

// Creates randomized data with specified size
Vect create_random_vector(const int vector_size);

// Creates ascending data with specified size
Vect create_asc_vector(const int vector_size);

// Creates descending data with specified size
Vect create_desc_vector(const int vector_size);

// Creates v-shaped data with specified size
Vect create_v_shaped_vector(const int vector_size);

// Creates a-shaped data with specified size
Vect create_a_shaped_vector(const int vector_size);

// Prompts the user to enter his own data set with @param message
Vect create_user_vector(const std::string_view &message="");

// Creates file with given @param filename, opens it, and extracts data to returning vector
// when file generation fails the execution of the program is stopped
Vect create_file_vector(const std::string& filename);

#endif