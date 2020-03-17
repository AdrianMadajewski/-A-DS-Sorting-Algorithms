#include "Vector.h"
#include "Input.h"
#include "Sorting.h"

/*
std::ofstream redirect_to_file()
{
	std::cout << "Enter a filename to redirect:" << '\n';
	std::string filename{};
	std::cin >> filename;

	std::ofstream file;
	file.open(filename, std::ios::out);

	if (!file.is_open())
	{
		std::cout << "Couldn't open file " << filename << '\n';
		std::cout << "Please restart" << '\n';
		std::cin.get();
		exit(-1);
	}
	else
	{
		std::cout << "File opened - log will be set to '" << filename << "'" << '\n';
		return file;
	}
}
*/

std::string VectType_toString(VectType type)
{
	switch (type)
	{
	case RANDOM_VECT:
		return "RANDOM";
	case ASC_VECT:
		return "ASC";
	case DESC_VECT:
		return "DESC";
	case V_SHAPED_VECT:
		return "V_SHAPED";
	case A_SHAPED_VECT:
		return "A_SHAPED";
	case USER_VECT:
		return "USER";
	case FILE_VECT:
		return "FILE";
	default:
		return "VECTOR_TYPE_ERROR";
	}
}

Vect create_random_vector(const int vector_size)
{
	std::vector<int> data(vector_size);
	for (int i{ 0 }; i < vector_size; ++i) {
		int value{ random::generateNumber(VECTOR_DATA_MIN, VECTOR_DATA_MAX) };
		data.at(i) = value;
	}
	return Vect(RANDOM_VECT, data);
}

Vect create_asc_vector(const int vector_size)
{
	std::vector<int> data{ random::generateNumber(VECTOR_DATA_MIN, VECTOR_DATA_MAX) };
	for (int i{ 1 }; i < vector_size; ++i) {
		int next_value{ data.back() + random::generateNumber(0, VECTOR_DATA_MAX) };
		data.emplace_back(next_value);
	}
	return Vect(ASC_VECT, data);
}

Vect create_desc_vector(const int vector_size)
{
	std::vector<int> data{ random::generateNumber(VECTOR_DATA_MIN, VECTOR_DATA_MAX) };
	for (int i{ 1 }; i < vector_size; ++i) {
		int next_value{ data.back() - random::generateNumber(0, VECTOR_DATA_MAX) };
		data.emplace_back(next_value);
	}
	return Vect(DESC_VECT, data);
}

Vect create_v_shaped_vector(const int vector_size)
{
	std::vector<int> data(vector_size);
	for (int i = 0; i < vector_size / 2; ++i) {
		data.at(i) = VECTOR_DATA_MAX - i;
		data.at(vector_size - i - 1) = VECTOR_DATA_MAX - i;
	}

	return Vect(V_SHAPED_VECT, data);
}

Vect create_a_shaped_vector(const int vector_size)
{
	std::vector<int> data(vector_size);
	for (int i = 0; i < vector_size / 2; ++i) {
		data.at(i) = VECTOR_DATA_MIN + i;
		data.at(vector_size - i - 1) = VECTOR_DATA_MIN + i;
	}

	return Vect(A_SHAPED_VECT, data);
}

Vect create_user_vector(const std::string_view& message)
{
	const int size = getUserDataSize(message);
	std::vector<int> data;
	for (int i = 0; i < size; ++i) {
		std::cout << "data[" << i << "] = ";
		int x = getUserInput();
		data.emplace_back(x);
	}

	return Vect(USER_VECT, data);
}

Vect create_file_vector(const std::string& filename)
{
	std::vector<int> data;
	std::fstream file;
	file.open(filename.c_str(), std::fstream::in);

	if (!file.is_open())
	{
		std::cout << "Couldn't find the file. Please restart" << '\n';
		std::cin.get();
		exit(-1);
	}
	else
	{
		std::cout << "Succesfully read from file " << filename << '\n';
		while (!file.eof())
		{
			int x;
			file >> x;
			data.emplace_back(x);
		}
	}

	return Vect(FILE_VECT, data);
}