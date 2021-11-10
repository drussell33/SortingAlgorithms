#ifndef data_fill_HPP
#define data_fill_HPP

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <windows.h>
#include "iSort.hpp"
#include "InsertionSort.hpp"
#include "BubbleSort.hpp"
#include "BubbleSortImproved.hpp"
#include "HeapSort.hpp"
#include "SelectionSort.hpp"
#include "ShellSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "array.hpp"
#include <fstream>


using std::endl;
using std::vector;
namespace data_structures
{

	std::ofstream outfile("sorting_results.txt");
	//outfile.open("sorting_results.txt");
	//outfile << "testing this shit out!" << "and more";

	inline void InsertRandomNumbers(int* container, const int& size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 1);

		for (auto n = 0; n < size; ++n)
			container[n] = dis(gen);

	}

	inline int* CreateMasterDataSet(int kSIZE)
	{
		int* master = new int[kSIZE];

		InsertRandomNumbers(master, kSIZE);

		return master;

	}

	inline vector<int> FreshVectorForSorting(vector<int> vec, int kSIZE)
	{
		int* master = CreateMasterDataSet(kSIZE);
		for (int i = 0u; i < kSIZE; ++i)
		{
			vec[i] = master[i];
		}
		return vec;
	}

	inline int* FreshCArrayForSorting(int* c_array, int kSIZE)
	{
		int* master = CreateMasterDataSet(kSIZE);
		for (int i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = master[i];
		}
		return c_array;
	}

	inline Array<int> FreshOurArrayForSorting(Array<int> our_array, int kSIZE)
	{
		int* master = CreateMasterDataSet(kSIZE);
		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = master[i];
		}
		return our_array;
	}

	inline void AllVectorSorts(int kSIZE)
	{
		vector<int> vector_array(kSIZE);
		vector<int> vector_array_master = FreshVectorForSorting(vector_array, kSIZE);

		vector_array = vector_array_master;

		// ------ InsertionSort ---------
		ISort<vector<int>>* vector_insertion = new InsertionSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_insertion = vector_insertion->Sort();
		outfile << "InsertionSort - Vector, " << kSIZE << " ," << final_time_vector_insertion << endl;

		vector_array = vector_array_master;

		//-- BubbleSOrt------------------
		ISort<vector<int>>* vector_bubble = new BubbleSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_bubble = vector_bubble->Sort();
		outfile << "BubbleSort - Vector," << kSIZE << " ," << final_time_vector_bubble << endl;

		vector_array = vector_array_master;

		//-- BubbleSOrtImproved-------------------
		ISort<vector<int>>* vector_bubble_improved = new BubbleSortImproved<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_bubble_improved = vector_bubble_improved->Sort();
		outfile << "BubbleSortImproved - Vector," << kSIZE << "," << final_time_vector_bubble_improved << endl;

		vector_array = vector_array_master;

		//---HeapSort-----------------------------
		ISort<vector<int>>* vector_heap = new HeapSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_heap = vector_heap->Sort();
		outfile << "HeapSort - Vector," << kSIZE << " ," << final_time_vector_heap << endl;

		vector_array = vector_array_master;

		//---SelectionSort-----------------------------
		ISort<vector<int>>* vector_selection = new SelectionSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_selection = vector_selection->Sort();
		outfile << "SelectionSort - Vector," << kSIZE << " ," << final_time_vector_selection << endl;

		vector_array = vector_array_master;

		//---ShellSort-----------------------------
		ISort<vector<int>>* vector_shell = new ShellSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_shell = vector_shell->Sort();
		outfile << "ShellSort - Vector," << kSIZE << " ," << final_time_vector_shell << endl;

		vector_array = vector_array_master;

		//---MersgeSort-----------------------------
		ISort<vector<int>>* vector_merge = new MergeSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_merge = vector_merge->Sort();
		outfile << "MergeSort - Vector," << kSIZE << " ," << final_time_vector_merge << endl;

		vector_array = vector_array_master;

		//---QuickSort-----------------------------
		ISort<vector<int>>* vector_quick = new QuickSort<vector<int>>(&vector_array, kSIZE);
		auto final_time_vector_quick = vector_quick->Sort();
		outfile << "QuickSort - Vector," << kSIZE << "," << final_time_vector_quick << endl;


	}


	inline void FirstHalfCArraySorts(int kSIZE)
	{
		int* c_array = new int[kSIZE];
		int* c_array_master = FreshCArrayForSorting(c_array, kSIZE);

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//------ InsertionSort ---------
		ISort<int*>* c_array_insertion = new InsertionSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_insertion = c_array_insertion->Sort();
		outfile << "InsertionSort - C-Array," << kSIZE << ", " << final_time_c_array_insertion << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//-- BubbleSOrt------------------
		ISort<int*>* c_array_bubble = new BubbleSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_bubble = c_array_bubble->Sort();
		outfile << "BubbleSort - C-Array," << kSIZE << "," << final_time_c_array_bubble << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}



		//-- BubbleSOrtImproved------------------
		ISort<int*>* c_array_bubble_improved = new BubbleSortImproved<int*>(&c_array, kSIZE);
		auto final_time_c_array_bubble_improved = c_array_bubble_improved->Sort();
		outfile << "BubbleSortImproved - C-Array," << kSIZE << "," << final_time_c_array_bubble_improved << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//---HeapSort-----------------------------
		ISort<int*>* c_array_heap = new HeapSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_heap = c_array_heap->Sort();
		outfile << "HeapSort - C-Array," << kSIZE << "," << final_time_c_array_heap << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//---SelectionSort-----------------------------
		ISort<int*>* c_array_selection = new SelectionSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_selection = c_array_selection->Sort();
		outfile << "SelectionSort - C-Array," << kSIZE << "," << final_time_c_array_selection << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//---Shell-----------------------------
		ISort<int*>* c_array_shell = new ShellSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_shell = c_array_shell->Sort();
		outfile << "ShellSort - C-Array," << kSIZE << "," << final_time_c_array_shell << endl;

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}

		//---MergeSort-----------------------------
		ISort<int*>* c_array_merge = new MergeSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_merge = c_array_merge->Sort();
		outfile << "MergeSort - C-Array," << kSIZE << " ," << final_time_c_array_merge << endl;

	}

	inline void SecondHalfCArraySorts(int kSIZE)
	{
		int* c_array = new int[kSIZE];
		int* c_array_master = FreshCArrayForSorting(c_array, kSIZE);

		for (auto i = 0u; i < kSIZE; ++i)
		{
			c_array[i] = c_array_master[i];
		}


		//---QuickSort-----------------------------
		ISort<int*>* c_array_quick = new QuickSort<int*>(&c_array, kSIZE);
		auto final_time_c_array_quick = c_array_quick->Sort();
		outfile << "QuickSort - C-Array," << kSIZE << "," << final_time_c_array_quick << endl;

	}

	inline void AllArraySorts(int kSIZE)
	{
		Array<int> our_array(kSIZE);
		Array<int> our_array_master = FreshOurArrayForSorting(our_array, kSIZE);

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		// --InsertionSort ---------
		ISort<Array<int>>* array_insertion = new InsertionSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_insertion = array_insertion->Sort();
		outfile << "InsertionSort - OurArray," << kSIZE << "," << final_time_array_insertion << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//-- BubbleSOrt------------------
		ISort<Array<int>>* array_bubble = new BubbleSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_bubble = array_bubble->Sort();
		outfile << "BubbleSort - OurArray," << kSIZE << "," << final_time_array_bubble << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//-- BubbleSOrtImproved------------------
		ISort<Array<int>>* array_bubble_improved = new BubbleSortImproved<Array<int>>(&our_array, kSIZE);
		auto final_time_array_bubble_improved = array_bubble_improved->Sort();
		outfile << "BubbleSortImproved - OurArray," << kSIZE << "," << final_time_array_bubble_improved << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//---HeapSort-----------------------------
		ISort<Array<int>>* array_heap = new HeapSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_heap = array_heap->Sort();
		outfile << "HeapSort - OurArray," << kSIZE << "," << final_time_array_heap << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//---SelectionSort-----------------------------
		ISort<Array<int>>* array_selection_sort = new SelectionSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_selection = array_selection_sort->Sort();
		outfile << "SelectionSort - OurArray," << kSIZE << "," << final_time_array_selection << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//---ShellSort-----------------------------
		ISort<Array<int>>* array_selection_shell = new ShellSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_shell = array_selection_shell->Sort();
		outfile << "ShellSort - OurArray," << kSIZE << "," << final_time_array_shell << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//---MergeSort-----------------------------
		ISort<Array<int>>* array_selection_merge = new MergeSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_merge = array_selection_merge->Sort();
		outfile << "MergeSort - OurArray," << kSIZE << "," << final_time_array_merge << endl;

		for (int i = 0u; i < kSIZE; ++i)
		{
			our_array[i] = our_array_master[i];
		}

		//---QuickSort-----------------------------
		ISort<Array<int>>* array_selection_quick = new QuickSort<Array<int>>(&our_array, kSIZE);
		auto final_time_array_quick = array_selection_quick->Sort();
		outfile << "QuickSort - OurArray," << kSIZE << "," << final_time_array_quick << endl;

	}

}
#endif

