#pragma once
#include <iostream>
class Vector
{
private:
	double* data;
	size_t size;
	size_t capacity;
	size_t grow_size;
	static double epsilon;
	void ExpandCapacityByN(const size_t n, const size_t index = 0, const bool end_insertion = true);
public:
	Vector();
	Vector(const size_t size);
	~Vector();
	Vector(const Vector& rhs);
	void Clear();
	size_t GetSize() const;
	void Print() const;
	void PushBack(const double value);
	void Insert(const double value, const size_t index);
	void Erase(const size_t index);
	Vector& operator=(const Vector& rhs);
	double& operator[] (const size_t index);
	double operator[](const size_t index) const;
	Vector& operator+= (const Vector& rhs);
	Vector operator+(const Vector& rhs) const;
	Vector& operator-= (const Vector& rhs);
	Vector operator-(const Vector& rhs) const;
	double operator*(const Vector& rhs) const;
	Vector& operator*=(const double value);
	Vector operator*(const double value) const;
	Vector& operator/=(const double value);
	Vector operator/(const double value) const;
	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;
	friend std::ostream& operator<< (std::ostream& out, const Vector& point);
};
std::ostream& operator<< (std::ostream& out, const Vector& vector);
Vector& operator*=(const double value, Vector& rhs);
Vector operator*(const double value, const Vector& rhs);