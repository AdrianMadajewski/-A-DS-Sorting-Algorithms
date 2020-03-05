#ifndef RANDOM_H
#define RANDOM_H

#include <random>		// for std::mt19937, std::random_device

namespace Random
{
	int getRandomNumber(const int min, const int max);
}

#endif