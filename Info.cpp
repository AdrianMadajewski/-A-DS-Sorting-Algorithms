#include "Info.h"

namespace info
{
	void print_vector(std::ostream &stream, Vect &vect)
	{
		stream << VectType_toString(vect.type) << " size=" << vect.data.size() << " [";
		for (size_t i{ 0 }; i < vect.data.size() - 1; ++i) {
			stream << vect.data[i] << ',';
		}
		stream << vect.data.back() << "]\n";
		
	}

	void full_info(std::ostream& stream, SortType s_type, VectType v_type, int v_size, int comparisons, int swaps, int duration, std::vector<int> additional)
	{
		std::string sort_type = SortType_toString(s_type);
		std::string vect_type = VectType_toString(v_type);
		stream << sort_type << '\t' << vect_type << '\t' << v_size << '\t' << comparisons << '\t' << swaps << '\t' << duration << '\t';

		if (!additional.empty())
			for (const auto& elem : additional)
				stream << elem << " ";
		stream << '\n';
		
	}

	void small_info(std::ostream& stream, SortType s_type, VectType v_type)
	{
		std::string sort_type = SortType_toString(s_type);
		std::string vect_type = VectType_toString(v_type);
		stream << sort_type << " with " << vect_type << " data ended.\n";
	}
}
