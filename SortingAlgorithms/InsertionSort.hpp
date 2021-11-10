#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <windows.h>
#include "iSort.hpp"

template <class T>
class InsertionSort final : public ISort<T>
{
public:
	~InsertionSort() = default;
	InsertionSort(T* container, const size_t& size)
		:ISort<T>(container, size, "InsertionSort") {}

	int Sort() override;

};

template <class T>
int InsertionSort<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();

	for (auto i = 1; i < size_reference; i++)
	{
		int next = container_reference[i];
		int j;

		for (j = i - 1; j >= 0 && container_reference[j] > next; j--)
			container_reference[j + 1] = container_reference[j];

		container_reference[j + 1] = next;
	}
	const auto finish = GetTickCount();

	return finish - start;
}

#endif
