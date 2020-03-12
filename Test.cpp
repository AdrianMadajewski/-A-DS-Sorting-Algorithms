#include "Test.h"

void performTesting(const int max_elements, bool full_info_mode, std::ostream& stream)
{
	bool generate_continue = askUser("Continue? 1 = yes, 0 = no");

	if (generate_continue)
	{
		for (int i = 10; i < max_elements; ++i)
		{
			// Generate each data set
			auto random = create::random_vector(i);
			auto asc = create::asc_vector(i);
			auto desc = create::desc_vector(i);
			auto a_shape = create::a_shaped_vector(i);
			auto v_shape = create::v_shaped_vector(i);

			std::cout << "Sorting with size = " << i << '\n';

			for (int i = 0; i < SORTS_TO_USE; ++i)
			{
				auto algo_type = static_cast<SortType>(i);
				which_algorithm_to_use(algo_type, random, stream, full_info_mode);
				which_algorithm_to_use(algo_type, asc, stream, full_info_mode);
				which_algorithm_to_use(algo_type, desc, stream, full_info_mode);
				which_algorithm_to_use(algo_type, v_shape, stream, full_info_mode);
				which_algorithm_to_use(algo_type, a_shape, stream, full_info_mode);
			}

			std::cout << "Sorting with size = " << i + 1 << " ended" << '\n';
		}
	}
}