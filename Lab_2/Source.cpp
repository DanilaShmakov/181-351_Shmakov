#include <iostream>

int main()
{
	//a=300 
	//b=560
	//a*a*b*b =
	//b/a =
	//symbol_A + a =
	int a = 300;
	int b = 560;
	std::cout << "a * a * b * b = " << a * a * b * b << std::endl;
	std::cout << "b/a = " << b / a << std::endl;
	std::cout << "b/a = " << double(b) / double(a) << std::endl;
	std::cout << "b%a = " << b % a << std::endl;
	std::cout << "symbol_A + a = " << 'A' + a << std::endl;
	int max_int = 0b01111111111111111111111111111111;
	std::cout << "Size of int = " << sizeof(int) << std::endl;
	std::cout << "Max int = " << max_int << std::endl;
	//data - value - min - max
	//bool, char, int, short, long, long long, double
	std::cout << "Type\t\t" << "Value\t" << "Min\t\t\t" << "Max\t" << std::endl;
	std::cout << "bool\t\t" << sizeof(bool) << "\t" << 0 << "\t" << "\t" << "\t" << 256 << "\t" << std::endl;
	std::cout << "char\t\t" << sizeof(char) << "\t" << CHAR_MIN << "\t" << "\t" << "\t" << CHAR_MAX << "\t" << std::endl;
	std::cout << "int\t\t" << sizeof(int) << "\t" << INT32_MIN << "\t" << "\t" << INT32_MAX << "\t" << std::endl;
	std::cout << "short\t\t" << sizeof(short) << "\t" << SHRT_MIN << "\t" << "\t" << "\t" << SHRT_MAX << "\t" << std::endl;
	std::cout << "long\t\t" << sizeof(long) << "\t" << LONG_MIN << "\t" << "\t" << LONG_MAX << "\t" << std::endl;
	std::cout << "long long\t" << sizeof(long long) << "\t" << LLONG_MIN << "\t" << LLONG_MAX << "\t" << std::endl;
	std::cout << "double\t\t" << sizeof(double) << "\t" << DBL_MIN << "\t" << "\t" << DBL_MAX << "\t" << std::endl;




	return 0;
}
