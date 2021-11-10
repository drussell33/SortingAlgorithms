#include "array.hpp"
#include <iostream>
#include <vector>
#include "data_fill.hpp"
#include <fstream>


//=========The output file is in the Sorting2 folder===========

using namespace data_structures;

int main()
{

	AllVectorSorts(10000);
	AllVectorSorts(20000);
	AllVectorSorts(30000);

	FirstHalfCArraySorts(10000);
	SecondHalfCArraySorts(10000);
	FirstHalfCArraySorts(20000);
	SecondHalfCArraySorts(20000);
	FirstHalfCArraySorts(30000);
	SecondHalfCArraySorts(30000);


	AllArraySorts(10000);
	AllArraySorts(20000);
	AllArraySorts(30000);

	outfile.close();
	return 0;


}