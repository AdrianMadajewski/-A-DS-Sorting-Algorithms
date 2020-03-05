#ifndef GENERATE_H
#define GENERATE_H

#include "Random.h"
#include <vector>

enum class VectorType
{
	ASCENDING,
	DESCENDING,
	A_SHAPE,
	V_SHAPE
};

constexpr int DATA_SIZE_MAX = 100;
constexpr int DATA_SIZE_MIN = -100;

std::vector<int> generateRandomVector(const int vector_size);
std::vector<int> generateVector_ASC_DSC(const int vector_size, VectorType type);
std::vector<int> generateVectorType_A_V(const int vector_size, VectorType type);

#endif