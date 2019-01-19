#include "Strock.h"
Strock::~Strock() {};
Strock::Strock() {};//нулевой конструктор
Strock::Strock(char *arr)// массив чаров
{
	buffer = arr;
	len = strlen(arr);
	std::cout << "Char\n" << buffer << std::endl;
};
Strock::Strock(Strock &arr)// копирование из другого класса
{
    len = arr.len;
    buffer = arr.buffer;
	std::cout << "Class \n" << buffer << std::endl;

};
Strock::Strock(std::string  *arr)// стринговский конструктор
{
	len = arr->length(); // длина buffer равна длине arr + 1, так как должен оканчиваться на '\0'
	buffer = new char[len + 1];
	std::copy(arr->begin(), arr->end(), buffer);// копирование в buffer
	buffer[len] = '\0';
	std::cout << "String\n" << buffer << std::endl;
	delete[] buffer;
}
void Strock::clear()// очистка строки
{
	len = 0; // длина 0 элементов
	buffer = nullptr; //удаление строки
	delete[] buffer;
	std::cout << "Cleared\n";
};
void Strock::add(std::string arr)// сложение строк
{
	len += arr.length();// длина новой строки = сумме длин двух строк
	std::string temp;
	if (buffer != nullptr) temp = std::string(buffer);// если buffer не пуст записываем  в temp
	temp.append(arr);// копирование arr в temp append - вставка последними символами
	buffer = nullptr;// удаляем buffer
	delete[]  buffer;
	buffer = new char[len];// создаем новую строку с новой длиной
	std::copy(temp.begin(), temp.end(), buffer); // копируем все в нее (от начального до конечного символа)
	buffer[len] = '\0';
	std::cout << "String add \n" << buffer << std::endl;
}
int Strock::insert(int pos, char * arr) 
{
	if ((pos <= len) && ( pos >= 0)) // не вышли ли мы за пределы строки
	{
		len += strlen(arr); // увеличиваем длину строки
		std::string temp;
		temp = buffer;
		temp.insert(pos, arr); //вставляем нужные элементы на требуемые позиции
		buffer = nullptr;// пересоздаем buffer и копируем в него новую строку
		delete[] buffer;
		buffer = new char[len];
		std::copy(temp.begin(), temp.end(),buffer);
		buffer[len] = '\0';
		std::cout << "Char insert \n" << buffer << std::endl;
		return 0;
	}
	return -1;
}
int Strock::cut(int pos, int num)
{
	if ((pos + num <= len) && (pos >= 0))
	{
		len -= num;// уменьшение длины
		std::string temp;
		temp = std::string(buffer);
		temp.erase(pos, num);// собственно, вырезание элементов
		buffer = nullptr;// пересоздание buffer
		delete[] buffer;
		buffer = new char[len];
		std::copy(temp.begin(), temp.end(), buffer);
		buffer[len] = '\0';
		std::cout << "Cut \n" << buffer << std::endl;
		return 0;
	}
	return -1;
}
Strock operator+(Strock str1 ,Strock str2)
{
	Strock temp;
	temp.len = str1.len + str2.len;
	temp.buffer = new char[temp.len];
	temp.insert(0, str1.buffer);
	temp.insert((str1.len + 1), str2.buffer);
	return temp;
}
std::ostream & operator << (std::ostream & os, Strock & r)
{
	os << r.buffer << '\t';
	return os;
}

int Strock::find(char * posl)
{
	std::string temp = std::string(buffer);
	if (temp.find(posl, 0) != std::string::npos)// find может найти npos если ничего не найдет
	{
		std::cout << "Found\n";
		return 0;
	}
	else
	{
		std::cout << "Not found\n";
		return -1;
	}
}
void Strock::save(Strock str1, std::string path)
{
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout)
	{
		std::cout << "Error in opening file \n";
	}
	else
	{
		std::cout << "File opened\n";
		fout.write((char*)&str1, sizeof(Strock));
	}
	fout.close();
}
void Strock::load(std::string path)
{
	std::ifstream fin;
	fin.open(path);
	if (!fin)
	{
		std::cout << "Error in opening file \n";
	}
	else
	{
		std::cout << "File opened\n";
		Strock pnt;

		while (fin.read((char*)&pnt, sizeof(Strock)))
		{
			
		//	std::printf((char*)&pnt);
		}
	}
	fin.close();
}
