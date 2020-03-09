#include "Random.h"

namespace random
{
	// Create random distribution seed
	std::random_device rd;
	std::mt19937 seed(rd());

	int generateNumber(const int min, const int max)
	{
		std::uniform_int_distribution<> die{ min, max };
		return die(random::seed);
	}
}


