#include "Info.h"
#include "Data.h"
#include "Sort.h"

namespace info
{
	void print_vector(std::ostream &stream, Vect &vect)
	{
		stream << vector_type_toString(vect.type) << " size=" << vect.data.size() << " [";
		for (size_t i{ 0 }; i < vect.data.size() - 1; ++i) {
			stream << vect.data[i] << ',';
		}
		stream << vect.data.back() << "]\n";
		
	}

	// aditional should be std::vector (save to a file???)
	void full_info(std::ostream& stream, SortType s_type, VectType v_type, int v_size, int comparisons, int swaps, int duration, int additional)
	{
		std::string s_sort_type = sort_type_toString(s_type);
		std::string s_vect_type = vector_type_toString(v_type);
		stream << s_sort_type << '\t' << s_vect_type << '\t' << v_size << '\t' << comparisons << '\t' << swaps << '\t'  << duration << '\t' << additional << '\n';
	}

	void small_info(std::ostream& stream, SortType s_type, VectType v_type)
	{
		std::string s_sort_type = sort_type_toString(s_type);
		std::string s_vect_type = vector_type_toString(v_type);
		stream << s_sort_type << " with " << s_vect_type << " data ended.\n";
	}
	
}
