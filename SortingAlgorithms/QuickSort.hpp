#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <windows.h>
#include <string>
#include "iSort.hpp"

template <class T>
class QuickSort final : public ISort<T>
{
public:
	~QuickSort() = default;
	QuickSort(T* container, const size_t& size)
		:ISort<T>(container, size, "QuickSort") {}

	virtual int Sort() override;
	int Partition(T& a, int left, int right);
	void QuickSortMain(T& array, int left, int right);
};

template <class T>
int QuickSort<T>::Sort()
{
	const auto start = GetTickCount();
	T& container_reference = *ISort<T>::GetContainer();
	const int& size_reference = ISort<T>::GetSize();

	QuickSortMain(container_reference, 0, ISort<T>::GetSize() - 1);

	const auto finish = GetTickCount();

	return finish - start;
}
template <class T>
int QuickSort<T>::Partition(T& a, int left, int right)
{
	int pivot = a[right];
	int i = left - 1;

	for (auto j = left; j <= right - 1; ++j) //changing j from size_t to int maybe?
	{
		if (a[j] <= pivot)
		{
			i++;
			///std::swap(a[i], a[j]);
			auto temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	//std::swap(a[i + 1], a[right]);
	auto temp = a[i + 1];
	a[i + 1] = a[right];
	a[right] = temp;
	return i + 1;
}
template <class T>
void QuickSort<T>::QuickSortMain(T& array, int left, int right)
{
	if (left < right)
	{
		auto p = Partition(array, left, right); // changed auto to int
		QuickSortMain(array, left, p - 1);
		QuickSortMain(array, p + 1, right);
	}
}
#endif
