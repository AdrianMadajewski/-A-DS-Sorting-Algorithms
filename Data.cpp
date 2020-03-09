#include "Data.h"
#include "Input.h"

std::string vector_type_toString(VectType type)
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
	case USER_VECT:
		return "USER";
	case FILE_VECT:
		return "FILE";
	default:
		return "VECTOR_TYPE_ERROR";
	}
}

namespace generate
{
	Vect random_vector(const int vector_size)
	{
		std::vector<int> data(vector_size);
		for (int i{ 0 }; i < vector_size; ++i) {
			int value{ random::generateNumber(DATA_SIZE_MIN, DATA_SIZE_MAX) };
			data.at(i) = value;
		}
		return Vect(RANDOM_VECT, data);
	}
	Vect asc_vector(const int vector_size)
	{
		std::vector<int> data{ random::generateNumber(DATA_SIZE_MIN, DATA_SIZE_MAX) };
		for (int i{ 1 }; i < vector_size; ++i) {
			int next_value{ data.back() + random::generateNumber(0, DATA_SIZE_MAX) };
			data.emplace_back(next_value);
		}
		return Vect(ASC_VECT, data);
	}

	Vect desc_vector(const int vector_size)
	{
		std::vector<int> data{ random::generateNumber(DATA_SIZE_MIN, DATA_SIZE_MAX) };
		for (int i{ 1 }; i < vector_size; ++i) {
			int next_value{ data.back() - random::generateNumber(0, DATA_SIZE_MAX) };
			data.emplace_back(next_value);
		}
		return Vect(DESC_VECT, data);
	}

	// TODO:
	Vect v_shaped_vector(const int vector_size)
	{
		std::vector<int> data{};
		return Vect(V_SHAPED_VECT, data);
	}

	// TODO:
	Vect a_shaped_vector(const int vector_size)
	{
		std::vector<int> data{};
		return Vect(A_SHAPED_VECT, data);
	}

	Vect user_vector(std::string_view message)
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

	Vect file_vector(const std::string& filename)
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
	
}



