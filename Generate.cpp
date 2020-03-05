#include "Generate.h"

std::vector<int> generateRandomVector(const int vector_size)
{
	std::vector<int> result{};
	for (int i { 0 }; i < vector_size; ++i) {
		int value{ Random::getRandomNumber(DATA_SIZE_MIN, DATA_SIZE_MAX) };
		result.emplace_back(value);
	}
	return result;
}

std::vector<int> generateVector_ASC_DSC(const int vector_size, VectorType type)
{
	std::vector<int> result{Random::getRandomNumber(DATA_SIZE_MIN, DATA_SIZE_MAX)};
	for (int i{ 1 }; i < vector_size; ++i) {
		int next_value{};
		if (type == VectorType::ASCENDING) {
			next_value = result.back() + Random::getRandomNumber(0, DATA_SIZE_MAX);
		}
		else if (type == VectorType::DESCENDING) {
			next_value = result.back() - Random::getRandomNumber(0, DATA_SIZE_MAX);
		}
		result.emplace_back(next_value);
	}
	return result;
}

// TODO:
std::vector<int> generateVectorType_A_V(const int vector_size, VectorType type)
{
	std::vector<int> result{};
	return result;
}