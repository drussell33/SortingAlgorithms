#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <windows.h>
#include <string>
#include "iSort.hpp"

template <class T>
class ShellSort : public ISort<T>
{
public:
	~ShellSort() = default;
	ShellSort(T* container, const size_t& size)
		:ISort<T>(container, size, "ShellSort") {}

	int Sort() override;

};

template <class T>
int ShellSort<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();

	for (auto gap = size_reference / 2; gap > 0; gap /= 2)
	{
		for (auto i = gap; i < size_reference; i += 1)
		{
			auto temp = container_reference[i];
			auto j = 0;
			for (j = i; j >= gap && container_reference[j - gap] > temp; j -= gap)
				container_reference[j] = container_reference[j - gap];
			container_reference[j] = temp;
		}
	}

	const auto finish = GetTickCount();

	return finish - start;
}

#endif