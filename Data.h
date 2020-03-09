#ifndef DATA_H
#define DATA_H

#include "Random.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

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

constexpr int DATA_SIZE_MIN = -10;
constexpr int DATA_SIZE_MAX = 10;

struct Vect
{
	VectType type;
	std::vector<int> data;
	Vect(VectType type, std::vector<int> data) : type(type), data(data) {}
	// TODO: DEFAULT CONSTRUCTOR WITH NO VALUES
};

std::string vector_type_toString(VectType type);

namespace generate
{
	Vect random_vector(const int vector_size);
	Vect asc_vector(const int vector_size);
	Vect desc_vector(const int vector_size);
	Vect v_shaped_vector(const int vector_size);
	Vect a_shaped_vector(const int vector_size);
	Vect user_vector(std::string_view message="");
	Vect file_vector(const std::string& filename);
}

#endif