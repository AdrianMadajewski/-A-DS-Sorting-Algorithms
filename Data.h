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

constexpr auto DATA_SIZE_MIN = 0;
constexpr auto DATA_SIZE_MAX = 10000;

struct Vect
{
	VectType type;
	std::vector<int> data;
	Vect(VectType type, std::vector<int> data) : type(type), data(data) {}
	Vect() = default;
};

std::string VectType_toString(VectType type);

namespace create
{
	Vect random_vector(const int vector_size);
	Vect asc_vector(const int vector_size);
	Vect desc_vector(const int vector_size);
	Vect v_shaped_vector(const int vector_size);
	Vect a_shaped_vector(const int vector_size);
	Vect user_vector(std::string_view message="");
	Vect file_vector(const std::string& filename);
	std::ofstream create_file();
}

#endif