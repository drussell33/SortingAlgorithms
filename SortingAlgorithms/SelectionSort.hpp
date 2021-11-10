#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <windows.h>
#include <string>
#include "iSort.hpp"

template <class T>
class SelectionSort : public ISort<T>
{
public:
	~SelectionSort() = default;
	SelectionSort(T* container, const size_t& size)
		:ISort<T>(container, size, "SelectionSort") {}

	int Sort() override;

};

template <class T>
int SelectionSort<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();



	for (auto i = size_reference - 1; i >= 1; i--)
	{
		auto index = i;
		for (int j = 0; j < i; j++)
		{
			if (container_reference[j] > container_reference[index])
				index = j;
		}
		std::swap(container_reference[i], container_reference[index]);
	}


	const auto finish = GetTickCount();

	return finish - start;
}

#endif

