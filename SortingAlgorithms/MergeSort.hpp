#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <windows.h>
#include <string>
#include "iSort.hpp"



template <class T>
class MergeSort : public ISort<T>
{
public:
	~MergeSort() = default;
	MergeSort(T* container, const size_t& size)
		:ISort<T>(container, size, "MergeSort") {}

	virtual int Sort() override;
	void MergeSorter(T& sort_me, size_t left, size_t middle, size_t right);
	void MergeSortInternal(T& a, size_t i, size_t j);
};
template <class T>
int MergeSort<T>::Sort()
{
	const auto start_time = GetTickCount();
	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();
	MergeSortInternal(container_reference, 0, size_reference - 1);
	const auto end_time = GetTickCount();

	return end_time - start_time;
}

template <class T>
void MergeSort<T>::MergeSortInternal(T& sort_me, size_t left, size_t right)
{
	if (left < right)
	{
		const auto middle = left + (right - left) / 2;

		MergeSortInternal(sort_me, left, middle);
		MergeSortInternal(sort_me, middle + 1, right);
		MergeSorter(sort_me, left, middle, right);
	}
}

template <class T>
void MergeSort<T>::MergeSorter(T& sort_me, size_t left, size_t middle, size_t right)
{
	size_t i, j;
	const auto left_size = middle - left + 1;
	const auto right_size = right - middle;

	auto* left_temp = new int[left_size];
	auto* right_temp = new int[right_size];

	for (i = 0; i < left_size; i++)
	{
		left_temp[i] = sort_me[left + i];
	}
	for (j = 0; j < right_size; j++)
	{
		right_temp[j] = sort_me[middle + 1 + j];
	}

	//merge temp arrays back into sort_me
	i = 0;
	j = 0;
	auto k = left;
	while (i < left_size && j < right_size)
	{
		if (left_temp[i] <= right_temp[j])
		{
			sort_me[k] = left_temp[i];
			i++;
		}
		else
		{
			sort_me[k] = right_temp[j];
			j++;
		}
		k++;
	}

	//copy remaining elements
	while (i < left_size)
	{
		sort_me[k] = left_temp[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		sort_me[k] = right_temp[j];
		j++;
		k++;
	}

	delete[] left_temp;
	delete[] right_temp;
}
#endif
