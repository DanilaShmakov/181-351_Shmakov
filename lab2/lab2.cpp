// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "bool\t\t" << sizeof(bool) << "\t" << 0 << "\t" << "\t" << "\t" << 256 << "\t" << std::endl;
	std::cout << "char\t\t" << sizeof(char) << "\t" << CHAR_MIN << "\t" << "\t" << "\t" << CHAR_MAX << "\t" << std::endl;
	std::cout << "int\t\t" << sizeof(int) << "\t" << INT32_MIN << "\t" << "\t" << INT32_MAX << "\t" << std::endl;
	std::cout << "short\t\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << "\t" << "\t" << SHRT_MAX << "\t" << std::endl;
	std::cout << "long\t\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << "\t" << LONG_MAX << "\t" << std::endl;
	std::cout << "long long\t" << sizeof(long long) << "\t" << LLONG_MIN << "\t" << LLONG_MAX << "\t" << std::endl;
	std::cout << "double\t\t" << sizeof(double) << "\t" << DBL_MIN << "\t" << "\t" << DBL_MAX << "\t" << std::endl;
	return(0);

}

