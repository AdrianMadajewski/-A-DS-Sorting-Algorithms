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

Vect create_random_vector(const int vector_size);
Vect create_asc_vector(const int vector_size);
Vect create_desc_vector(const int vector_size);
Vect create_v_shaped_vector(const int vector_size);
Vect create_a_shaped_vector(const int vector_size);
Vect create_user_vector(const std::string_view &message="");
Vect create_file_vector(const std::string& filename);

#endif