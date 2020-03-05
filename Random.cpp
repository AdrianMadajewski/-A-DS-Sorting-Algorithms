#include "Random.h"

namespace Random
{
	// Create random distribution seed
	std::random_device rd;
	std::mt19937 seed(rd());

	int getRandomNumber(const int min, const int max)
	{
		std::uniform_int_distribution<> die{ min, max };
		return die(Random::seed);
	}
}


