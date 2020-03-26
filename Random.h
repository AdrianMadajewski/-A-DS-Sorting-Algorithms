#ifndef RANDOM_H
#define RANDOM_H

#include <random>		// for std::mt19937, std::random_device

namespace random
{
	// Generates random number between [min, max] inclusive
	int generateNumber(const int min, const int max);
}

#endif