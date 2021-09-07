#include <iostream>
class Vector
{
private:
	double* data;
	size_t size;
	size_t capacity;
	size_t grow_size;
public:
	Vector() : data(NULL), size(0), capacity(0), grow_size(10) {}
	Vector(const size_t size)
	{
		grow_size = 10;
		this->size = size;
		capacity = size + grow_size;
		data = new double[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			data[i] = 0;
		}
	}
	~Vector()
	{
		delete[] data;
		size = 0;
		capacity = 0;
		grow_size = 0;
	}
	Vector(const Vector& rhs) :capacity(rhs.capacity), size(rhs.size)
	{
		data = new double[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = rhs.data[i];
		}
		grow_size = rhs.grow_size;
	}
	size_t GetSize() const
	{
		return size;
	}
};