#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <windows.h>
#include <string>
#include "iSort.hpp"



template <class T>
class HeapSort : public ISort<T>
{
public:
	~HeapSort() = default;
	HeapSort(T* container, const size_t& size)
		:ISort<T>(container, size, "HeapSort") {}

	int Sort() override;
	void HeapSorter(T& arr, size_t size);
	void Heapify(T& sort_me, size_t size, size_t root);

};

template <class T>
void HeapSort<T>::HeapSorter(T& arr, size_t size)
{
	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		Heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

template <class T>
void HeapSort<T>::Heapify(T& sort_me, size_t size, size_t root) {
	int largest = root;
	int left_child = (2 * root) + 1;
	int right_child = (2 * root) + 2;
	if (left_child < size && sort_me[left_child] > sort_me[largest])//This is where issues happened
	{
		largest = left_child;
	}
	if (right_child < size && sort_me[right_child] > sort_me[largest])
	{
		largest = right_child;
	}
	if (largest != root)
	{
		std::swap(sort_me[root], sort_me[largest]);
		Heapify(sort_me, size, largest);
	}
}

template <class T>
int HeapSort<T>::Sort()
{
	const auto start = GetTickCount();

	T& container_reference = *ISort<T>::GetContainer();
	const size_t& size_reference = ISort<T>::GetSize();

	HeapSorter(container_reference, size_reference);

	const auto finish = GetTickCount();

	return finish - start;
}
//========================================================
//template <class T>
//inline void HeapSort<T>::Heapify_(T& sort_me, size_t size, int root)
//{
//	auto largest = root;
//	auto left_child = 2 * root + 1;
//	auto right_child = 2 * root + 2;
//
//	if (left_child < size && sort_me[left_child] > sort_me[largest])
//		largest = left_child;
//
//	if (right_child < size && sort_me[right_child] > sort_me[largest])
//		largest = right_child;
//
//	if (largest != root)
//	{
//		std::swap(sort_me[root], sort_me[largest]);
//
//		Heapify_(sort_me, size, largest);
//	}
//}


//template <class T>
//int HeapSort<T>::Sort()
//{
//	const auto start = GetTickCount();
//
//	T& container_reference = *ISort<T>::GetContainer();
//	const size_t& size_reference = ISort<T>::GetSize();
//
//
//	for (auto i = (size_reference / 2) - 1; i >= 0; --i)
//		Heapify_(container_reference, size_reference, i);
//	for (auto i = size_reference - 1; i >= 0; --i)
//	{
//		std::swap(container_reference[0], container_reference[i]);
//
//		Heapify_(container_reference, i, 0);
//	}
//	
//	const auto finish = GetTickCount();
//
//	return finish - start;
//}

#endif

