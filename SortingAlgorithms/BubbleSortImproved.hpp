#ifndef BUBBLE_SORT_IMPROVED_HPP
#define BUBBLE_SORT_IMPROVED_HPP

#include <windows.h>
#include "iSort.hpp"

template <class T>
class BubbleSortImproved final : public ISort<T>
{
public:
	~BubbleSortImproved() = default;
	BubbleSortImproved(T* container, const size_t& size)
		:ISort<T>(container, size, "BubbleSortImproved") {}

	int Sort() override;

};

template <class T>
int BubbleSortImproved<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();

	for (auto i = 1; i < size_reference; i++)
	{
		bool is_sorted = true;
		for (auto j = 0; j < size_reference - i; j++)
		{
			if (container_reference[j] > container_reference[j + 1])
			{
				auto temp = container_reference[j];
				container_reference[j] = container_reference[j + 1];
				container_reference[j + 1] = temp;
				is_sorted = false;
			}
		}
		if (is_sorted); // return;
	}


	const auto finish = GetTickCount();

	return finish - start;
}

#endif

