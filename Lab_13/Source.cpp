#define CURL_STATICLIB 
#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 

/*
https://github.com/curl/curl.git https://github.com/curl/curl
1. Запустить от учётки админа консоль разработчика VS (x64 Native tools)
2. С помощью CD /D <путь> перейти в папку curl
3. Выполнить buildconf.bat (команда buildconf) - предварительные настройки переменных среды и генерация необходимых файлов
4. Перейти с помощью CD в winbuild
5. Выполнить строку из файла справки BUILD.WINDOWS.txt
*/

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	CURL *curl = nullptr;
	std::string buffer, curs;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.banki.ru/products/currency/cash/moskva/" /* "https://mospolytech.ru/"*/);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	//std::cout << buffer << std::endl; //печатает весь код страницы
	//i = buffer.find("currency__numbers_increase\">6"); //нахождение номера указанной строки
	//вниз пишем строку перед которой идёт нужное значение курса покупки 
	i = buffer.find("<div class=\"currency-table__large-text\">");//нахождение номера указанной строки
	i += 40;
	curs = buffer.substr(i, 5); //вывод с i-того элемента 5 символа
	std::cout << "USD\t" << curs << std::endl;
	i = buffer.rfind("<div class=\"currency-table__large-text\">");
	i += 40;
	curs = buffer.substr(i, 5);
	std::cout << "EUR\t" << curs;
	getchar();
	return 0;
}

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
