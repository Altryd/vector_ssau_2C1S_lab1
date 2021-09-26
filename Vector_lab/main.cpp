#define _CRT_SECURE_NO_WARNINGS
#include "Vector.h"
#include <climits>
#include <string>
#include <cstring>
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
	printf("%s\n", condition);
	long int value = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str.c_str(), &value) == 1) break;
		else
		{
			printf("Input error, try again\n");
		}
	}
	while (true)
		if (value >= left_border && value <= right_border) return value;
		else
		{
			printf("The number doesn't satisfy the conidition %s\n", condition);
			while (true)
			{
				str.clear();
				std::cin >> str;
				if (StrToLong(str.c_str(), &value) == 1) break;
				else
				{
					printf("Input error, try again\n");
				}
			}
		}
}


int main()
{
	bool function_is_working = true;
	Vector first_vector;
	Vector second_vector;
	while (function_is_working)
	{
		long int action = NumberNeeded(0, 20, "From 0 to 20");
		/*switch (action)
		{
			case 0: //чтение
			{

				break;
			}
			case 1: //запись
			{

				break;
			}
			case 2: //сложить два вектора
			{

				break;
			}
			case 3: //вычесть из первого второй вектор
			{

				break;
			}
		}*/
	}
}