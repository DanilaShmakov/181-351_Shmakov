#include <iostream>
#include <cstring> // библиотека для работы с Си строками
#include <string>
#include <fstream>
using namespace std;

// СТРОКИ И ФАЙЛЫ

/*
Cтроки старого Си-типа представляют из себя всего лишь массив
символов с нулевым окончанием:
char cstr1[] = "C-style string1";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '1', '\0' };
char cstr3[] = {'\67', '\0'};
string cppstr1 = "C++ - style string 1";
string cppstr2 = "";
 В типе char на самом деле хранится знаковое целое число. Его можно складывать, вычитать, умножать и делить
 */

 /*
  ФУНКЦИИ ДЛЯ РАБОТЫ С С-СТРОКАМИ
  вывод на печать:
  printf(char[], , ,)
  или
  printf(* char, ...)
  */

  /*
 %f - для float и double
 %s - для строк
 %d - для целых (int, long, long long)
 %e - для экспонициального вида
 */

 /*
 Виды функций:
 объединение (конкатенация) строк - strcat (*char, *char):
 копирование из одной строки в другую - strcpy():
 char cstr3[255];
 strcpy_s(cstr3, 255, cstr2);
 сравнение - strcmp():
 int i = strcmp(cstr1, cstr2);
 длина строки - strlen():
 int lngth = strlen(cstr1);
 вставка строки в подстроку производится в несколько действий
 */

 /*
 Работа с файлами:
 1) проверить существует ли файл
 2) при работе в С++ - создать объект для работы с файлом
 3) открытие файла
 4) работа с файлом (чтение, запись, поиск)
 5) закрытие файла
 fstream - универсальный класс для ввода и для вывода (чтения из файла и записи в него)
 (if/of)stream - класс для ввода/вывода
 fstream -поток, предназначенный для ввода/вывода в/из файла
 */

 /*
 Открытие файла:
 fs.open("Some text file.txt", fstream::in | fstream::out | fstream::trunc);
 Режимы открытия:
 fs.open("Some text file.txt", - при открытии файла необходимо указать тип файла,
 а также режим открытия с перезаписью или без
 */



int main()
{
	fstream fs;
	fstream text;
	text.open("Text.txt", fstream::in);
	fs.open("Some text.txt", fstream::out);

	string user_str;
	getline(text, user_str);
	string user_str2;
	getline(text, user_str2);

	cout << "input string: " << endl;
	cout << user_str << endl;

	cout << "input underline: " << endl;
	cout << user_str2 << endl;


	int pos = 0;
	while (pos != string::npos) {
		pos = user_str.find(user_str2, pos);
		if (pos == string::npos) {
			break;
		}
		fs << pos + 1 << '\t';

		pos++;
	}

	text.close();
	fs.close();
}