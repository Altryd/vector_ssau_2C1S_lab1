#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
int main()
{
	/*Vector a(4);
	for (size_t i = 0; i < a.GetSize(); i++)
	{
		a[i] += 1 +double(i);
	}
	std::cout << a << std::endl;
	Vector b(4);
	for (size_t i = 0; i < b.GetSize(); i++)
	{
		b[i] += 1 + (double)i * (double)i +50;
	}
	std::cout << b << std::endl;
	Vector c = a + b;
	std::cout << c << std::endl;
	double s_p = a * b;
	std::cout << s_p << std::endl;
	setlocale(LC_ALL, "Russian");
	Vector data(0);
	//a.Insert(5,0);
	//a.PushBack(20);
	for (size_t i = 0; i < 11; i++)
	{
		data.Insert((double)i + 1, i);
	}
	std::cout << "До:  ";
	for (size_t i = 0; i < 11; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "До:  " << data << std::endl << std::endl;
	size_t size = data.GetSize();
	for (int i = size - 2; i >= 0; i -= 2)
	{
		try {
			std::cout << data[i] << std::endl;
			data.Erase((size_t)i);
		}
		catch (std::exception& err)
		{
			std::cout << err.what() << std::endl;
		}
	}
	std::cout << "После:  " << data << std::endl;
	Vector c(data.GetSize());
	c -= data;
	std::cout << c << std::endl;*/
	Vector a(3);
	Vector b(3);
	for (size_t i = 0; i < a.GetSize(); i++)
	{
		a[i] += i;
		b[i] += 2;
	}
	Vector c;
	c = a + b;
#ifdef DEBUG_LINES
	std::cout << c << std::endl;
#endif
	c = c;
#ifdef DEBUG_LINES
	std::cout << c << std::endl;
#endif
	c = a;
#ifdef DEBUG_LINES
	std::cout << c << std::endl;
#endif
	Vector d(10);
	c = d;
#ifdef DEBUG_LINES
	std::cout << c << std::endl;
#endif
}