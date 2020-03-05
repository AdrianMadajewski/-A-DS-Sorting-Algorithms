#include <iostream>
#include "Random.h"
#include "Input.h"
#include "Generate.h"
#include "Sorting.h"

void printVector(const std::vector<int>& data) {
	for (const int& x : data) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main(int argc, char* argsv[])
{
	// const auto user_vector_size		{ getUserVectorSize("Enter how many elements you wish to enter: (<=10)") };
	// auto userData		{ createUserPromptedVector(user_vector_size) };
	// auto randomVector	{ generateRandomVector(user_vector_size) };
	// auto vector		{ generateVector_ASC_DSC(10, VectorType::DESCENDING) };

	auto vector			 { generateRandomVector(16000) };

	// printVector(vector);

	insertionSort(vector);

	// printVector(vector);



	return 0;
}