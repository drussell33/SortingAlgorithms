#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <windows.h>
#include "iSort.hpp"

template <class T>
class BubbleSort final : public ISort<T>
{
public:
	~BubbleSort() = default;
	BubbleSort(T* container, const size_t& size)
		:ISort<T>(container, size, "BubbleSort") {}

	virtual int Sort() override;

};

template <class T>
int BubbleSort<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();

	for (int i = 1; i < size_reference; i++)
	{
		for (int j = 0; j < size_reference - i; j++)
		{
			if (container_reference[j] > container_reference[j + 1])
			{
				int temp = container_reference[j];
				container_reference[j] = container_reference[j + 1];
				container_reference[j + 1] = temp;
			}
		}
	}


	const auto finish = GetTickCount();

	return finish - start;
}
#endif
