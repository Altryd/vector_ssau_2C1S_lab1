#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <climits>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cfloat>
bool StrToLong(const char* str, long int* value)
{
	char* endptr = NULL;
	*value = strtol(str, &endptr, 0);
	if (endptr == str)return false; //к примеру при вводе "привет"
	if ((*value == LONG_MIN || *value == LONG_MAX) && errno == ERANGE) return false; //при вводе большого числа
	if (*endptr != str[strlen(str)]) return false; //при вводе 23привет
	return true;
}
long int NumberNeeded(const long int left_border, const long int right_border, const char* condition)
{
	std::cout << condition << std::endl;
	long int value = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str.c_str(), &value) == 1) break;
		else
		{
			std::cout << "Input error, try again" << std::endl;
		}
	}
	while (true)
		if (value >= left_border && value <= right_border) return value;
		else
		{
			std::cout << "The number doesn't satisfy the conidition" << std::endl << condition << std::endl;
			while (true)
			{
				str.clear();
				std::cin >> str;
				if (StrToLong(str.c_str(), &value) == 1) break;
				else
				{
					std::cout << "Input error, try again" << std::endl;
				}
			}
		}
}
bool StrToDouble(const char* str, double* value)
{
	char* endptr = NULL;
	*value = strtod(str, &endptr);
	if (endptr == str)return false; //к примеру при вводе "привет"
	if (errno == ERANGE) return false; //при вводе большого числа
	if (*endptr != str[strlen(str)]) return false; //при вводе 23привет
	return true;
}
double NumberNeeded(const double left_border, const double right_border, const char* condition)
{
	std::cout << condition << std::endl;
	double value = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToDouble(str.c_str(), &value) == 1) break;
		else
		{
			std::cout << "Input error, try again" << std::endl;
		}
	}
	while (true)
		if (value >= left_border && value <= right_border) return value;
		else
		{
			std::cout << "The number doesn't satisfy the conidition" << std::endl << condition << std::endl;
			while (true)
			{
				str.clear();
				std::cin >> str;
				if (StrToDouble(str.c_str(), &value) == 1) break;
				else
				{
					std::cout << "Input error, try again" << std::endl;
				}
			}
		}
}

int main()
{
	srand((unsigned int)time(NULL));
	bool function_is_working = true;
	Vector first_vector;
	Vector second_vector;
	while (function_is_working)
	{
		std::cout << "First vector:" << first_vector << std::endl;
		std::cout << "\nSecond vector:" << second_vector << std::endl;
		std::cout << "Enter:\n0 - to work and edit with single vector" << std::endl;
		std::cout << "1 - to sum two vectors\n2 - to substract second vector from first" << std::endl;
		std::cout << "3 - to calculate the scalar product of two vectors\n4 - clear two vectors" << std::endl;
		std::cout << "5 - Print are two vectors equal or not\n6 - make first vector equal to second\n";
		std::cout << "7 - finish the program" << std::endl;
		long int action = NumberNeeded((long int)0, 7, "\nEnter a number in range [0;7]");
		switch (action)
		{
			case 0: //работа с векторами по отдельности
			{
				long int order_number = NumberNeeded((long int)1, 2, "Enter the order number of vector you wanted to edit");
				//[] , * by scalar , / by scalar
				if (order_number==1)
				{
					bool working_with_first_vector = true;
					while (working_with_first_vector)
					{
						system("cls");
						std::cout << first_vector << std::endl;
						std::cout << "You are now editing the first vector, Enter:" << std::endl;
						std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
						std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
						std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
						long int editing_first_vector = NumberNeeded((long int)0, 5, "Enter the number in range[0;5]");
						switch (editing_first_vector)
						{
							case 0: //edit
							{
								size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element");
								try
								{
									double value = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a new value for the element");
									first_vector[index] = value;
								}
								catch (std::out_of_range& ex)
								{
									std::cout << ex.what() << " Try again" << std::endl;
									system("pause");
								}
								break;
							}
							case 1: //*=
							{
								double scalar = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a scalar");
								first_vector *= scalar;
								break;
							}
							case 2: // /=
							{
								double scalar = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a scalar");
								try
								{
									first_vector /= scalar;
								}
								catch (const char* ex)
								{
									std::cout << ex << " Try again" << std::endl;
									system("pause");
								}
								break;
							}
							case 3: //insert
							{
								if (first_vector.GetSize())
								{
									size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element to insert");
									try
									{
										double value = (double)rand();
										first_vector.Insert(value, index);
									}
									catch (std::out_of_range& ex)
									{
										std::cout << ex.what() << " Try again" << std::endl;
										system("pause");
									}
								}
								else
								{
									first_vector.PushBack(rand());
								}
								break;
							}
							case 4: //erase
							{
								if (first_vector.GetSize())
								{
									size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element to delete");
									try
									{
										first_vector.Erase(index);
									}
									catch (std::out_of_range& ex)
									{
										std::cout << ex.what() << " Try again" << std::endl;
										system("pause");
									}
								}
								else
								{
									std::cout << "There are no elements to delete" << std::endl;
								}
								break;
							}
							case 5: //finish working
							{	
								working_with_first_vector = false;
								break;
							}
						}
					}
				}
				else
				{
				bool working_with_second_vector = true;
				while (working_with_second_vector)
				{
					system("cls");
					std::cout << second_vector << std::endl;
					std::cout << "You are now editing the second vector, Enter:" << std::endl;
					std::cout << "0 - to edit the element in the vector with index\n1 - to multiply the vector by a scalar" << std::endl;
					std::cout << "2 - to divide the vector by a scalar\n3 - add a new random element in the vector with index " << std::endl;
					std::cout << "4 - remove an element from the vector\n5 - finish working with the vector" << std::endl;
					long int editing_second_vector = NumberNeeded((long int)0, 5, "Enter the number in range[0;5]");
					switch (editing_second_vector)
					{
						case 0: //edit
						{
							size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element");
							try
							{
								double value = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a new value for the element");
								second_vector[index] = value;
							}
							catch (std::out_of_range& ex)
							{
								std::cout << ex.what() << " Try again" << std::endl;
								system("pause");
							}
							break;
						}
						case 1: //*=
						{
							double scalar = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a scalar");
							second_vector *= scalar;
							break;
						}
						case 2: // /=
						{
							double scalar = NumberNeeded(-DBL_MAX, DBL_MAX, "Enter a scalar");
							try
							{
								second_vector /= scalar;
							}
							catch (const char* ex)
							{
								std::cout << ex << " Try again" << std::endl;
								system("pause");
							}
							break;
						}
						case 3: //insert
						{
							if (second_vector.GetSize())
							{
								size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element to insert");
								try
								{
									double value = (double)rand();
									second_vector.Insert(value, index);
								}
								catch (std::out_of_range& ex)
								{
									std::cout << ex.what() << " Try again" << std::endl;
									system("pause");
								}
							}
							else
							{
								second_vector.PushBack(rand());
							}
							break;
						}
						case 4: //erase
						{
							if (second_vector.GetSize())
							{
								size_t index = (size_t)NumberNeeded(LONG_MIN, LONG_MAX, "Enter the index of element to delete");
								try
								{
									second_vector.Erase(index);
								}
								catch (std::out_of_range& ex)
								{
									std::cout << ex.what() << " Try again" << std::endl;
									system("pause");
								}
							}
							else
							{
								std::cout << "There are no elements to delete" << std::endl;
							}
							break;
						}
						case 5: //finish working
						{
							working_with_second_vector = false;
							break;
						}
					}
				}
				}
				break;
			}
			case 1: //сложить два вектора
			{
				try 
				{
					Vector sum = first_vector + second_vector;
					std::cout << sum;
				}
				catch (const char* ex)
				{
					std::cout << ex << std::endl;
				}
				system("pause");
				break;
			}
			case 2: //вычесть из первого второй вектор
			{
				try
				{
					Vector subtraction = first_vector - second_vector;
					std::cout << subtraction;
				}
				catch (const char* ex)
				{
					std::cout << ex << std::endl;
				}
				system("pause");
				break;
			}
			case 3: //скал€рное произведение
			{
				try
				{
					double scalar_product = first_vector * second_vector;
					std::cout << scalar_product << std::endl;
				}
				catch (const char* ex)
				{
					std::cout << ex << std::endl;
				}
				system("pause");
				break;
			}
			case 4: //очистить векторы
			{
				first_vector.Clear();
				second_vector.Clear();
				break;
			}
			case 5: //оценить, равны ли вектора
			{
				first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
					std::cout << "Vectors are different" << std::endl;
				system("pause");
				break;
			}
			case 6:
			{
				first_vector = second_vector;
				break;
			}
			case 7: //выйти из программы
			{
				function_is_working = false;
				break;
			}

		}
		system("cls");
	}
}