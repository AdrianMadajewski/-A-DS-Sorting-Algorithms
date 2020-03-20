#ifndef INFO_H
#define INFO_H

#include <iostream>

#include "Sorting.h"
#include "Vector.h"
#include "Input.h"

namespace info
{	
	/** 
	 * Utility function to print 'data' elements inside 'vector' as follows
	 * Data type, size=(size of the data) and elements in brackets [x, y, z]
	 * Example:
	 * USER size=4 [-1, 0, 3, 4]
	 * 
	 * @param stream - stream object to redirect the output 
	 * @param vect - data vector with .data and .type to be printed
	 */
	void print_vector(std::ostream& stream, Vect &vect);


	/**
	 * Utility function to print 'full information' about the data to the prompted stream buffer
	 * Template is as follows:
	 * WHERE_TO_PRINT - SORT_TYPE - VECTOR_TYPE - DATA.SIZE - COMPARISONS - SWAPS - DURATION - ADDITIONAL
	 *
	 * @param stream - stream object to redirect the output
	 * @param s_type - sorting type to be printed as std::string
	 * @param v_type - data vector type to be printed as std::string
	 * @param comparisons - the number of comparisons the selected algorithm made
	 * @param swaps - the number of swaps the selected algorithm made
	 * @param duration - the time between the start of the algorithm and it's end
	 * @param additional - if empty prints nothing, if has values prints everything in it (for pivots QS and knuth's gains SS)
	 */
	void full_info(std::ostream& stream, SortType s_type, VectType v_type, int v_size, int comparisons, int swaps, int duration, std::vector<int> additional = {});


	/**
	 * Utility function to print 'small information' about the data to the prompted stream buffer
	 * Template is as follows:
	 * WHERE_TO_PRINT - SORT_TYPE - VECTOR_TYPE 
	 *
	 * @param stream - stream object to redirect the output
	 * @param s_type - sorting type to be printed as std::string
	 * @param v_type - data vector type to be printed as std::string
	 */ 
	void small_info(std::ostream& stream, SortType s_type, VectType v_type);
}

#endif
