#include <iostream>
#include "Vector.h"
double Vector::epsilon = 0.001;
void Vector::ExpandCapacityByN(const size_t n, const size_t index, const bool end_insertion)
	{
		size_t new_capacity = capacity + n;
		double* new_data = new double[new_capacity];
		if (end_insertion)
		{
			for (size_t i = 0; i < new_capacity; i++)
			{
				if (i == size) break;
				new_data[i] = data[i];
			}
		}
		else
		{
			for (size_t i = 0; i < new_capacity; i++)
			{
				if (i == index) break;
				new_data[i] = data[i];
			}
			data[index] = 0;
			for (size_t i = index + 1; i < new_capacity; i++)
			{
				if (i == size) break;
				new_data[i] = data[i - 1];
			}
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}
Vector::Vector() : data(NULL), size(0), capacity(0), grow_size(10) {}
Vector::Vector(const size_t size)
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
Vector::~Vector()
	{
		delete[] data;
		size = 0;
		capacity = 0;
		grow_size = 0;
	}
Vector::Vector(const Vector& rhs) :capacity(rhs.capacity), size(rhs.size)
	{
		data = new double[capacity];
		for (size_t i = 0; i < capacity; ++i)
		{
			if (i == size) break;
			data[i] = rhs.data[i];
		}
		grow_size = rhs.grow_size;
	}
size_t Vector::GetSize() const
	{
		return size;
	}
void Vector::PushBack(const double value)
	{
		if (size == 0 && capacity == 0 && data==NULL)
		{
			data = new double[grow_size];
			data[size] = value;
			size++;
		}
		else
		{
			if (size + 1 >= capacity) ExpandCapacityByN(grow_size);
			data[size] = value;
			size++;
		}
	}
void Vector::Insert(const double value, const size_t index)
	{
		if (index<0 || index>size) throw std::out_of_range("Index is out of range");
		if (size == 0 && capacity ==0 && data ==NULL)
		{
			data = new double[grow_size];
			data[size] = value;
			size++;
		}
		else
		{
			if (size + 1 >= capacity) ExpandCapacityByN(grow_size);
			for (size_t i = size + 1; i > index; --i)
			{
				std::swap(data[i], data[i - 1]);
			}
			data[index] = value;
			size++;
		}
	}
Vector& Vector::operator=(const Vector& rhs)
{
	if (this == &rhs) return *this;
	if (size != rhs.size)
	{
		delete[] data;
		data = new double[rhs.size];
		for (size_t i = 0; i < rhs.size; i++)
		{
			data[i] = rhs.data[i];
		}
		size = rhs.size;
	}
	else
	{
		for (size_t i = 0; i < rhs.size; i++)
		{
			data[i] = rhs.data[i];
		}
	}
	grow_size = rhs.grow_size;
	capacity = rhs.capacity;
	return *this;
}

void Vector::Erase(const size_t index)
	{
		if (size == 0) return;
		if (index >= size) throw std::out_of_range("Index is out of range");
		for (size_t i = index; i < size-1; ++i)
		{
			std::swap(data[i], data[i + 1]);
		}
		size--;
	}
double& Vector::operator[] (const size_t index)
	{
		if (index >= size) throw std::out_of_range("Index is out of range");
		return data[index];
	}
double Vector::operator[](const size_t index) const
	{
		if (index >= size) throw std::out_of_range("Index is out of range");
		return data[index];
	}
Vector Vector::operator+= (const Vector& rhs)
	{
		if (size != rhs.size) throw std::exception("Bad dimensions");
		for (size_t i = 0; i < size; i++)
		{
			data[i] += rhs.data[i];
		}
		return *this;
	}
Vector Vector::operator+(const Vector& rhs) const
	{
		if (size != rhs.size) throw std::exception("Bad dimensions");
		Vector result(*this);
		result += rhs;
		return result;
	}
Vector Vector::operator-= (const Vector& rhs)
	{
		if (size != rhs.size) throw std::exception("Bad dimensions");
		for (size_t i = 0; i < size; i++)
		{
			data[i] -= rhs.data[i];
		}
		return *this;
	}
Vector Vector::operator-(const Vector& rhs) const
	{
		if (size != rhs.size) throw std::exception("Bad dimensions");
		Vector result(*this);
		result -= rhs;
		return result;
	}
double Vector::operator*(const Vector& rhs) const
	{
		if (size != rhs.size) throw std::exception("Bad dimensions");
		double scalar_product = 0;
		for (size_t i = 0; i < size; i++)
		{
			scalar_product += data[i] * rhs.data[i];
		}
		return scalar_product;
	}
Vector Vector::operator*=(const double value)
	{
		for (size_t i = 0; i < size; i++)
		{
			data[i] *= value;
		}
		return *this;
	}
Vector Vector::operator*(const double value) const
	{
		Vector result(*this);
		result *= value;
		return result;
	}
Vector Vector::operator/=(const double value)
	{
		if (value == 0) throw std::exception("Dividing by zero is prohibited");
		for (size_t i = 0; i < size; i++)
		{
			data[i] /= value;
		}
		return *this;
	}
Vector Vector::operator/(const double value) const
	{
		Vector result(*this);
		result /= value;
		return result;
	}
bool Vector::operator==(const Vector& rhs) const
	{
		if (size != rhs.size) return false;
		for (size_t i = 0; i < size; i++)
		{
			if (abs(data[i] - rhs.data[i]) >= epsilon) return false;
		}
		return true;
	}
bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}
std::ostream& operator<< (std::ostream& out, const Vector& vector)
{
	for (size_t i = 0; i < vector.size; i++)
	{
		out << vector.data[i] << " ";
	}
	out << std::endl;


	return out;
}
Vector operator*=(const double value, Vector& rhs)
{
	rhs *= value;
	return rhs;
}
Vector operator*(const double value, const Vector& rhs)
{
	Vector result(rhs);
	result *= value;
	return result;
}