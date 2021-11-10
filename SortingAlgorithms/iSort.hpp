#ifndef I_SORT_HPP
#define I_SORT_HPP

#include <string>
using std::string;

template <class T>
class ISort
{
public:
	virtual int Sort() = 0;
	virtual ~ISort() = default;
	string GetName() const { return name_; }
	T* GetContainer() { return container_; }
	size_t GetSize() const { return size_; }
	ISort(T* container, const size_t& size, const string& name)
		:container_(container), size_(size), name_(name) {}


protected:
	T* container_;
	size_t size_;
	string name_;

};




#endif

