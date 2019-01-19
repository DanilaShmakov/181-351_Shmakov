#include <iostream>
using namespace std;

// Указатель (pointer)- переменная, хранящая адрес смещений каких-либо данных, переменных в оперативной памяти 
// Объявляется как обычная переменаая, но добавляется звездочка в начале
// Фактически указатель- это unsigned или unsigned long long  с адресом, так как дробных адресов нет
// 



int main()
{
	int a;
	double dbl;
	
	int * ptr_int;
	ptr_int = &a;
	double * ptr_dbl = &dbl;
	
	cout << "int pointer size = " << sizeof(ptr_int) << endl;
	cout << "double pointer size = " << sizeof(ptr_dbl) << endl;
	cout << "char pointer size = " << sizeof(char *) << endl;
	cout << "long long pointer size = " << sizeof(long long *) << endl;
	cout << "bool pointer size = " << sizeof(bool *) << endl;

	// 3. Содержимое указателя
	cout << "ptr_int = " << ptr_int << endl;
	cout << "ptr_dbl = " << ptr_dbl << endl;

	// Содержимое указателя 
	cout << endl << "prt_int = 0x" << ptr_int << endl;
}

